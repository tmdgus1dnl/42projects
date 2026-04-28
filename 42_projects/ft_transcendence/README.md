# ft_transcendence

> 42Seoul | TypeScript · Node.js · Docker | 점수: 105/100 | 소요 기간: 1달 | 재시도: 1회  
> 팀 5인 — seunghan, jaeblee, seungryk, heuchoi, dongeunk

실시간 Pong 게임, 사용자 인증, 프로필 관리가 포함된 풀스택 싱글 페이지 웹 애플리케이션입니다.  
42 커리큘럼의 최종 프로젝트입니다.

---

## 목차

- [과제 개요](#과제-개요)
- [기술 스택](#기술-스택)
- [프로젝트 구조](#프로젝트-구조)
- [SPA 라우팅](#spa-라우팅)
- [인증 흐름](#인증-흐름)
- [주요 기능](#주요-기능)
- [트러블슈팅](#트러블슈팅)
- [깨달은 점](#깨달은-점)

---

## 과제 개요

실시간 Pong 게임이 작동하는 웹 사이트를 구현합니다.  
페이지 리로드 없이 동작하는 SPA(Single Page Application) 방식으로 제작하며,  
Docker로 컨테이너화해 배포합니다.

---

## 기술 스택

| 구분 | 기술 |
|---|---|
| 프론트엔드 | TypeScript, Tailwind CSS, Vite |
| 백엔드 | Node.js, Fastify |
| 데이터베이스 | SQLite |
| 인증 | OAuth2 (42 로그인), JWT, 2FA (speakeasy, qrcode) |
| 게임 렌더링 | Babylon.js |
| 차트 | Chart.js |
| 인프라 | Docker, docker-compose, HTTPS |

---

## 프로젝트 구조

```
srcs/
├── backend/
│   ├── server.ts          — Fastify HTTPS 서버, 라우트 등록
│   ├── routes/
│   │   ├── login.ts       — OAuth2 로그인
│   │   ├── auth.ts        — JWT 검증
│   │   ├── profile.ts     — 프로필 조회/수정
│   │   ├── game-stats.ts  — 게임 통계
│   │   ├── match-results.ts
│   │   └── userinfo.ts
│   ├── db/                — SQLite 초기화
│   └── cert/              — HTTPS 인증서
├── frontend/
│   ├── src/
│   │   ├── app.ts         — 라우터 초기화
│   │   ├── router.ts      — SPA 라우터
│   │   └── pages/
│   │       ├── loading.ts
│   │       ├── login.ts
│   │       ├── game.ts
│   │       └── settings.ts
│   ├── public/
│   │   └── index.html     — #app 컨테이너
│   └── dist/              — 빌드 결과물 (tsc 컴파일)
└── docker-compose.yml
```

---

## SPA 라우팅

페이지 전환 시 서버에 요청을 보내지 않고 JavaScript만으로 화면을 교체하는 방식입니다.

**핵심 원리**

`index.html`에는 `<div id="app"></div>` 하나만 있습니다.  
라우터가 현재 URL에 맞는 HTML을 이 `#app` 안에 동적으로 삽입합니다.

```typescript
// router.ts
public navigate(url: string) {
    history.pushState(null, "", url);  // URL 변경 (서버 요청 없음)
    this.render();                      // #app 내용 교체
}

public render() {
    const path = window.location.pathname;
    document.getElementById("app")!.innerHTML =
        this.routes[path] || "<h1>404 Not Found</h1>";
}
```

**`history.pushState`** — URL을 변경하지만 페이지를 새로고침하지 않습니다.  
**`popstate` 이벤트** — 브라우저의 뒤로 가기/앞으로 가기를 감지해 `render()`를 재실행합니다.

```typescript
window.addEventListener("popstate", () => this.render());
```

**프로그램이 종료되지 않는 이유**  
C/C++와 달리 JavaScript는 이벤트 루프 기반으로 동작합니다.  
이벤트 리스너가 등록되어 있는 한 프로그램은 이벤트 큐를 감시하며 대기 상태를 유지합니다.

**TypeScript 컴파일 흐름**  
`src/*.ts` → `tsc` → `dist/*.js` → `index.html`에서 `dist/app.js` 로드  
라우터는 `dist/app.js`를 덮어쓰지 않고, 이미 컴파일된 JS를 실행해 `#app`을 업데이트합니다.

---

## 인증 흐름

```
1. 42 OAuth 로그인
      ↓
2. OTP(2FA) 인증 페이지
   - 최초 1회만 수행
   - 로그아웃 시 재인증 필요
      ↓
3. JWT 토큰 발급
      ↓
4. 이후 게임/프로필/대시보드 접근 시 JWT 검증
```

- **OTP 페이지**는 42 OAuth 로그인을 완료한 경우에만 접근 가능합니다.
- **게임, 프로필, 대시보드** 페이지는 JWT 토큰이 있어야 접근 가능합니다.
- 로그아웃 시 JWT 토큰이 파기되며 다음 로그인 시 OTP 재인증이 필요합니다.

---

## 주요 기능

**Pong 게임**
- Babylon.js 기반 실시간 렌더링
- 매치메이킹, 게임 결과 저장, 전적 조회

**프로필**
- 닉네임, 프로필 사진 설정
- 경기 기록, 승/패 통계 (Chart.js 시각화)

**대시보드**
- 전체 유저 통계 조회

---

## 트러블슈팅

**백엔드/프론트엔드 라우트 이름 충돌**  
프론트(`/profile`)와 백엔드(`/profile`)의 라우트 이름이 겹쳐, 브라우저에서 URL을 직접 입력하면 Fastify 서버의 `/profile` 라우트가 응답해 JSON 데이터만 텍스트로 표시됐습니다.  
백엔드 라우트 이름을 `/sendprofile`처럼 구분해 충돌을 방지하고, 프론트에서 `fetch`로 데이터를 가져와 페이지에 렌더링하는 방식으로 해결했습니다.

**로그아웃 후 프로필 정보 초기화**  
로그아웃 시 JWT 토큰 파기와 함께 SQLite에서 프로필 데이터까지 사라지는 문제가 발생했습니다.  
원인은 JWT 토큰 처리 SQL 구문이 `DELETE`로 되어 있던 것이었습니다.  
`UPDATE`로 변경해 토큰만 무효화하고 프로필 데이터는 유지되도록 수정했습니다.

**파일 업로드 응답 지연**  
프로필 사진 업로드 시 작은 파일은 빠르게 응답하지만 큰 파일(700KB 이상)은 응답이 오래 걸리는 문제가 발생했습니다.  
원인은 Node.js 스트림을 소비하지 않은 것이었습니다.  
`multipart` 파트를 순회할 때 `part.file.resume()`을 호출하지 않으면 스트림이 `pause` 상태로 남아, 브라우저가 TCP 흐름 제어(Flow Control)로 전송 속도를 늦추고 Fastify는 요청이 완료되지 않았다고 판단해 응답을 지연시킵니다.  
`part.file.resume()`을 명시적으로 호출해 스트림을 소비하도록 수정해 해결했습니다.

**닉네임 대소문자 중복 허용**  
페이지에서는 대문자로 표시되지만 내부적으로는 대소문자를 구분해 저장하기 때문에, `User`와 `user`가 다른 계정으로 생성됐습니다.  
닉네임 저장 및 조회 시 소문자로 정규화하는 방식으로 처리했습니다.

---

## 깨달은 점

**SPA는 URL 관리가 핵심이다**  
`history.pushState`로 URL을 변경하고 `popstate`로 뒤로 가기를 처리하는 패턴을 직접 구현하면서 SPA의 동작 원리를 깊이 이해했습니다.  
React나 Vue 같은 프레임워크가 내부적으로 하는 일을 직접 구현한 경험이었습니다.

**백엔드와 프론트엔드의 라우트는 독립적으로 설계해야 한다**  
같은 경로를 공유하면 서버 응답이 프론트 렌더링보다 우선됩니다.  
API 라우트와 프론트 라우트의 네이밍을 처음부터 명확히 구분해야 합니다.

**Node.js 스트림은 반드시 소비해야 한다**  
스트림을 소비하지 않으면 TCP 흐름 제어로 인해 요청이 완료되지 않은 상태가 지속됩니다.  
에러 경로에서도 반드시 `resume()`이나 `pipe()`로 스트림을 처리해야 합니다.

**SQL 구문 하나가 데이터 손실로 이어진다**  
`DELETE`와 `UPDATE`의 차이를 간과해 프로필 데이터가 사라지는 버그를 만들었습니다.  
어떤 데이터를 지우고 어떤 데이터를 유지할지 의도를 명확히 하고 SQL 구문을 작성해야 합니다.

---

## 사용 기술

`TypeScript` `Node.js` `Fastify` `SQLite` `Tailwind CSS` `Vite` `Babylon.js` `Chart.js` `JWT` `OAuth2` `2FA` `Docker` `docker-compose` `HTTPS`
