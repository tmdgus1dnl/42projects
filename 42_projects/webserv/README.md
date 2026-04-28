# webserv

> 42Seoul | C++98 · kqueue | 점수: 110/100 | 소요 기간: 1달 | 재시도: 1회  
> 팀 3인 — seunghan, jeshin, jaeblee

NGINX를 기준으로 HTTP/1.1 웹서버를 C++98로 구현한 프로젝트입니다.  
`kqueue` 이벤트 루프 기반 논블로킹 I/O로 단일 스레드에서 다수의 클라이언트를 동시에 처리하며,  
최대 부하 환경에서 10분 이상 **가용성 99.5% 이상**을 달성했습니다.

---

## 목차

- [과제 요구사항](#과제-요구사항)
- [코드 구조](#코드-구조)
- [전체 흐름](#전체-흐름)
- [설정 파일 파싱](#설정-파일-파싱)
- [kqueue 이벤트 루프](#kqueue-이벤트-루프)
- [HTTP 요청 파서](#http-요청-파서)
- [HTTP 응답 처리](#http-응답-처리)
- [CGI 구현](#cgi-구현)
- [트러블슈팅](#트러블슈팅)
- [깨달은 점](#깨달은-점)

---

## 과제 요구사항

- 서버는 블로킹되지 않아야 하며, **단 하나의 비동기 I/O 함수(`kqueue`)** 로 모든 처리를 수행 (`listen` 포함)
- `read` / `write`는 반드시 `kqueue`를 통해서만 수행
- `read` / `write` 후 `errno` 체크 금지
- `fork`는 CGI 처리에 한해서만 허용
- GET, POST, DELETE 메서드 지원
- 파일 업로드 지원
- 설정 파일로 서버 동작 제어 (NGINX 스타일)
- 스트레스 테스트에서도 서버가 살아있어야 함
- 다중 포트 `listen` 지원

---

## 코드 구조

```
webserv/
├── server/
│   ├── Server       — 소켓 생성, kqueue 관리, 이벤트 루프
│   └── Client       — 클라이언트 소켓 상태 관리
├── config/
│   ├── ServConf     — 설정 파일 전체 (http 블록)
│   ├── ServBlock    — server { } 블록
│   ├── LocBlock     — location { } 블록
│   └── utils_conf   — 설정 파싱 유틸
├── request/
│   └── Request      — HTTP 요청 파싱
└── response/
    ├── Response        — 응답 흐름 제어
    ├── ResponseManager — 요청 유형별 처리 분기
    ├── ErrorResponse   — 에러 응답 생성
    ├── StatusLine      — 상태 라인 구성
    ├── Header / GeneralHeader / ResponseHeader / EntityHeader
    └── Body            — 응답 바디 구성
```

---

## 전체 흐름

```
1. 설정 파일 파싱 → ServConf 초기화
2. 서버 소켓 생성 + kqueue 등록
3. kqueue 이벤트 루프 시작
   ├── 서버 소켓 이벤트 → accept() → 클라이언트 소켓 생성 + kqueue 등록
   ├── EVFILT_READ     → HTTP 요청 수신 + 파싱
   ├── EVFILT_WRITE    → HTTP 응답 전송
   └── EV_EOF          → 클라이언트 소켓 close()
4. 주기적으로 timeout 체크 → 오래된 연결 정리
```

메인 루프 코드:

```cpp
while (true)
{
    int nev = serv.getKevent();
    for (int i = 0; i < nev; i++)
    {
        const struct kevent& event = serv.getEvList(i);
        if (serv.getServerIdx(event.ident) != -1)
            serv.acceptClient(event.ident);
        else if (serv.getClientIdx(event.ident) != -1)
        {
            if (event.flags & EV_EOF)          serv.closeClient(event.ident);
            else if (event.filter == EVFILT_READ)  serv.readClient(event.ident, conf);
            else if (event.filter == EVFILT_WRITE) serv.sendClient(event.ident, conf);
        }
    }
    serv.checkTimeout(conf.getAliveTime());
}
```

---

## 설정 파일 파싱

NGINX 스타일의 설정 파일을 파싱합니다. 블록 계층 구조는 중괄호로 구분합니다.

```nginx
http {
    keepalive_timeout 60;

    server {
        listen      4242;
        server_name localhost;
        root        /html;
        client_max_body_size 2024;
        error_page  404 /error_page/40x.html;

        location / {
            index     index.html;
            autoindex on;
        }
        location .py$ {
            cgi_pass  /usr/bin/python3;
        }
    }
}
```

**블록 계층 → 클래스 매핑**

| 블록 | 클래스 | 주요 필드 |
|---|---|---|
| `http { }` | `ServConf` | `keepalive_timeout`, MIME 타입, `ServBlock[]` |
| `server { }` | `ServBlock` | `listen`, `server_name`, `root`, `client_max_body_size`, `error_page` |
| `location { }` | `LocBlock` | `index`, `autoindex`, `cgi_pass`, `return`, 허용 메서드 |

같은 `host:port`를 가진 서버 블록 중 **첫 번째가 디폴트**로 동작하며, `server_name`으로 분기합니다.

---

## kqueue 이벤트 루프

### kevent 구조체 vs kevent 함수

이름이 같아 헷갈리기 쉽습니다.

- **`kevent` 구조체** — 감시할 fd, 이벤트 종류(filter), 동작 플래그를 담는 컨테이너. `EV_SET` 매크로로 초기화합니다.
- **`kevent` 함수** — kqueue 인스턴스에 이벤트를 등록하거나 발생한 이벤트를 가져오는 시스템 콜.

```cpp
// 이벤트 등록
EV_SET(&evSet, fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
kevent(_kq, &evSet, 1, NULL, 0, NULL);

// 발생한 이벤트 수신
int nev = kevent(_kq, NULL, 0, _evList.data(), MAX_EVENTS, &_timeout);
```

| changelist | eventlist | 동작 |
|---|---|---|
| NULL이 아님 | NULL | 이벤트 등록/수정만 |
| NULL | NULL이 아님 | 발생한 이벤트 수신만 |
| NULL이 아님 | NULL이 아님 | 등록 + 수신 동시 |

`kevent` 함수는 등록과 수신을 하나의 시스템 콜로 통합해 호출 비용을 줄입니다.  
분리하면 시스템 콜이 두 번 발생하지만, 통합하면 한 번으로 처리됩니다.

### SO_REUSEADDR

서버 재시작 시 이전 소켓의 `TIME_WAIT` 상태 때문에 `bind()`가 실패하는 경우가 있습니다.  
`SO_REUSEADDR` 옵션을 활성화하면 `TIME_WAIT`을 무시하고 같은 포트를 즉시 재사용할 수 있습니다.  
TCP의 시퀀스 넘버가 새 연결과 이전 연결의 잔류 패킷을 구분해주기 때문에 충돌이 발생하지 않습니다.

---

## HTTP 요청 파서

```
POST /path HTTP/1.1        ← 상태 라인 (메서드 / 경로 / 버전)
Host: www.example.com      ← 헤더 (key: value)
Content-Length: 13
                           ← 빈 줄 (헤더/바디 구분)
Hello, World!              ← 바디
```

**파싱 흐름**

1. **상태 라인** — 공백 기준으로 메서드 / 경로 / 버전 분리. GET·POST·DELETE 이외 메서드, HTTP/1.1 이외 버전은 예외 처리. URL은 `?` 기준으로 경로와 쿼리 분리.
2. **헤더** — `:` 기준으로 key / value 분리. `:` 이후 공백 무시. `unordered_map<string, string>`에 저장.
3. **바디** — 빈 줄 이후 데이터. `Content-Length` 기준 크기 제한 확인. Chunked Transfer Encoding 수신 시 unchunk 처리.

---

## HTTP 응답 처리

`ResponseManager`가 요청 URL, 메서드, 설정을 조합해 응답 유형을 결정합니다.

| 조건 | 처리 |
|---|---|
| `location`에 `return` 설정 | 301/302 리다이렉트 |
| 허용되지 않은 메서드 | 405 응답 |
| 바디 크기 초과 | 413 응답 |
| `cgi_pass` 설정 + 해당 확장자 | CGI 실행 |
| GET + 정적 파일 | 파일 내용 그대로 응답 |
| GET + 디렉토리 + `autoindex on` | 디렉토리 목록 생성 |
| POST + 파일 업로드 | 파일 저장 후 201 응답 |
| DELETE | 파일/디렉토리 삭제 후 응답 |
| 파일 없음 | 404 응답 |

에러 응답은 `ErrorResponse`가 담당합니다. 설정 파일의 `error_page` 경로에서 파일을 먼저 찾고, 없으면 HTML을 직접 생성합니다.

---

## CGI 구현

CGI는 웹서버가 외부 프로그램을 실행해 동적 응답을 생성하는 방식입니다.  
`fork` + `execve`로 Python 등 CGI 프로그램을 자식 프로세스로 실행합니다.

**실행 흐름**

```
1. fork() → 자식 프로세스 생성
2. 자식: pipe를 통해 요청 바디를 stdin으로 전달
3. 자식: 환경 변수 설정 후 execve()로 CGI 프로그램 실행
4. 부모: 자식 stdout을 읽어 HTTP 응답 바디로 사용
```

**환경 변수 목록**

| 환경 변수 | 값 |
|---|---|
| `REQUEST_METHOD` | GET / POST / DELETE |
| `CONTENT_TYPE` | 요청 Content-Type |
| `CONTENT_LENGTH` | 요청 바디 크기 |
| `PATH_INFO` | URL 경로 |
| `QUERY_STRING` | 쿼리 문자열 |

`Content-Length`가 없으면 EOF를 바디 끝으로 판단합니다.

---

## 트러블슈팅

**바이너리 파일 업로드 손상**  
이미지, PDF 등 바이너리 파일을 업로드하면 파일이 손상되는 문제가 발생했습니다.  
원인은 소켓에서 읽은 `char*` 데이터를 `string` 생성자에 그대로 넘긴 것이었습니다.  
`string` 내부에서 `strlen()`을 호출해 `\0` 위치까지만 복사하는데, 바이너리 데이터 중간에 `\0`이 있으면 이후 데이터가 잘렸습니다.  
`string::append(buf, readBytes)`로 바이트 수를 명시적으로 지정하는 방식으로 해결했습니다.

**CGI `FieldStorage()` 빈 객체 반환**  
Python CGI 스크립트에서 `cgi.FieldStorage()`가 항상 빈 객체를 반환했습니다.  
원인은 환경 변수 이름 오타였습니다. `REQUEST_METHOD`를 `REQUESTED_METHOD`로 잘못 설정했고,  
`FieldStorage()`는 환경 변수 하나라도 틀리면 전체를 빈 객체로 반환합니다.

**TIME_WAIT으로 인한 bind() 실패**  
서버를 재시작할 때 이전 소켓이 `TIME_WAIT` 상태여서 `bind()`가 실패하는 경우가 있었습니다.  
`SO_REUSEADDR` 소켓 옵션 활성화로 해결했습니다.

**헤더 멀티라인 처리 여부**  
HTTP 헤더가 여러 줄에 걸쳐 작성될 수 있는지 고민했습니다.  
RFC 7230(2014)에서 헤더 줄 바꿈 방식은 보안 문제로 폐기되었고, 현재 표준에서는 헤더가 항상 한 줄입니다.

---

## 깨달은 점

**논블로킹 I/O의 핵심은 이벤트 중심 설계다**  
스레드 없이 많은 클라이언트를 처리하려면 "기다리지 않는" 코드를 짜야 합니다.  
`kqueue`는 I/O가 준비된 fd만 알려주므로, 준비된 것만 처리하고 나머지는 신경 쓰지 않으면 됩니다.

**시스템 콜 비용을 의식해야 한다**  
`kevent` 함수가 등록과 수신을 통합한 이유는 시스템 콜 호출 횟수를 줄이기 위해서입니다.  
사용자 공간과 커널 공간의 전환(context switch)은 비용이 높습니다.

**바이너리 데이터는 `string`으로 받으면 위험하다**  
C++98에서 `string` 생성자는 `\0` 위치까지만 복사합니다. 바이너리 데이터를 다룰 때는 반드시 바이트 수를 명시적으로 지정해야 합니다.

**환경 변수 이름은 정확해야 한다**  
CGI 표준에서 환경 변수 이름은 정해져 있습니다. 하나라도 틀리면 CGI 프로그램이 정상 동작하지 않습니다.

**HTTP는 스펙보다 실제 브라우저 동작이 기준이다**  
NGINX를 기준으로 만들어야 했기 때문에 표준 스펙과 실제 브라우저/NGINX 동작 간의 차이를 직접 확인해야 했습니다.

---

## 사용 기술

`C++98` `kqueue` `non-blocking I/O` `TCP/IP socket` `HTTP/1.1` `CGI` `fork` `execve` `MIME` `SO_REUSEADDR`
