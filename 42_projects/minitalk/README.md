# minitalk

> 42Seoul | C · UNIX 시그널 | 점수: 125/100 | 재시도: 1회

UNIX 시그널(`SIGUSR1`, `SIGUSR2`)만을 사용해 문자열을 **비트 단위로 전송**하는 클라이언트-서버 통신 프로젝트입니다.  
네트워크나 파이프 없이 시그널 두 개만으로 IPC(프로세스 간 통신)를 구현합니다.

---

## 목차

- [과제 개요](#과제-개요)
- [핵심 개념](#핵심-개념)
- [동작 방식](#동작-방식)
- [Mandatory 구현](#mandatory-구현)
- [Bonus 구현](#bonus-구현)
- [깨달은 점](#깨달은-점)

---

## 과제 개요

서버와 클라이언트 두 개의 프로그램을 구현합니다.

```bash
./server          # 서버 실행 → PID 출력
./client PID "Hello minitalk"   # 클라이언트 실행
```

- **서버**를 먼저 실행하면 자신의 PID를 출력하고 시그널을 대기합니다.
- **클라이언트**는 서버 PID와 전송할 문자열을 인자로 받아, 문자열을 비트 단위로 시그널로 전송합니다.
- **서버**는 수신한 비트를 누적해 문자를 복원하고 출력합니다.

허용 함수: `write`, `ft_printf`, `signal`, `sigemptyset`, `sigaddset`, `sigaction`, `kill`, `getpid`, `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`

---

## 핵심 개념

### UNIX 시그널

프로세스 간에 비동기적으로 이벤트를 전달하는 메커니즘입니다.  
`kill(pid, SIGUSR1)`은 해당 PID 프로세스에 `SIGUSR1` 시그널을 전송합니다.  
이름과 달리 프로세스를 종료하는 게 아니라 시그널을 "보내는" 시스템 콜입니다.

이 과제에서는 `SIGUSR1`과 `SIGUSR2` 두 가지만 사용합니다.  
두 가지 시그널이 각각 비트 `0`과 `1`을 나타냅니다.

### signal vs sigaction

| | `signal()` | `sigaction()` |
|---|---|---|
| 이식성 | 낮음 (POSIX 구현마다 다름) | 높음 |
| 송신자 PID 확인 | 불가 | `siginfo_t`로 가능 |
| 추가 플래그 | 없음 | `SA_SIGINFO` 등 |

Bonus에서 송신자 PID가 필요하므로 `sigaction`을 사용합니다.

### pause()

`pause()`는 시그널이 도착할 때까지 프로세스를 블로킹 상태로 대기시킵니다.  
바쁜 대기(busy wait) 없이 CPU를 소비하지 않으면서 시그널을 기다릴 수 있습니다.

---

## 동작 방식

문자 하나는 8비트로 구성됩니다.  
클라이언트는 각 문자를 MSB부터 1비트씩 시그널로 변환해 전송합니다.

```
문자 'A' = 0x41 = 01000001 (2진수)

비트 0 → SIGUSR1
비트 1 → SIGUSR2

전송 순서: SIGUSR1 SIGUSR2 SIGUSR1 SIGUSR1 SIGUSR1 SIGUSR1 SIGUSR1 SIGUSR2
            0       1       0       0       0       0       0       1
```

서버는 수신한 시그널을 비트로 변환해 누적하고, 8비트가 모이면 문자 하나를 복원해 출력합니다.

```c
// 서버 핸들러 (개념 코드)
static int bit = 0;
static char c = 0;

void handler(int sig) {
    c |= (sig == SIGUSR2) << (7 - bit);  // SIGUSR2=1, SIGUSR1=0
    bit++;
    if (bit == 8) {
        write(1, &c, 1);  // 문자 출력
        bit = 0;
        c = 0;
    }
}
```

---

## Mandatory 구현

**클라이언트**

```
문자열 순회
    └── 각 문자의 비트 7~0 순서로
            비트가 1이면 kill(server_pid, SIGUSR2)
            비트가 0이면 kill(server_pid, SIGUSR1)
            usleep(100)  ← 시그널 처리 시간 확보
```

`usleep`으로 시그널 전송 간격을 주는 이유는 서버가 이전 시그널을 처리하기 전에 다음 시그널이 도착하면 시그널이 유실될 수 있기 때문입니다.

**서버**

```
sigaction으로 SIGUSR1, SIGUSR2 핸들러 등록
    └── pause() 루프로 시그널 대기
            시그널 수신 → 핸들러에서 비트 누적
            8비트 완성 → 문자 출력
```

`\0`(NULL 문자) 수신 시 문자열 끝으로 판단하고 개행을 출력합니다.

---

## Bonus 구현

**ACK(수신 확인) 응답**

Mandatory에서는 `usleep`으로 시간을 두지만, 이는 근본적인 해결책이 아닙니다.  
Bonus에서는 서버가 문자를 수신할 때마다 클라이언트에게 `SIGUSR1`로 ACK를 보내고,  
클라이언트는 ACK를 받은 후에 다음 비트를 전송합니다.

```
클라이언트                        서버
  SIGUSR1 (bit=0) ──────────→
  (ACK 대기)       ←────────── SIGUSR1 (ACK)
  SIGUSR2 (bit=1) ──────────→
  (ACK 대기)       ←────────── SIGUSR1 (ACK)
  ...
```

ACK 방식으로 시그널 유실 없이 안정적으로 전송할 수 있습니다.

**송신자 PID 확인**

서버에서 클라이언트로 ACK를 보내려면 클라이언트의 PID가 필요합니다.  
`sigaction`의 `SA_SIGINFO` 플래그와 `siginfo_t` 구조체를 사용해 시그널 송신자 PID를 추출합니다.

```c
void handler(int sig, siginfo_t *info, void *ctx) {
    pid_t client_pid = info->si_pid;  // 송신자 PID
    // ...
    kill(client_pid, SIGUSR1);  // ACK 전송
}
```

**유니코드 지원**

UTF-8 멀티바이트 문자(한글, 이모지 등)는 1바이트가 아닌 2~4바이트로 구성됩니다.  
첫 바이트의 상위 비트로 전체 바이트 수를 파악하고, 해당 바이트 수만큼 전송하면 유니코드가 정상 출력됩니다.

```
1바이트 문자: 0xxxxxxx
2바이트 문자: 110xxxxx 10xxxxxx
3바이트 문자: 1110xxxx 10xxxxxx 10xxxxxx
4바이트 문자: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
```

---

## 깨달은 점

**시그널은 비동기적이다**  
시그널은 언제든 도착할 수 있고, 도착 순서가 보장되지 않습니다.  
전송 속도를 조절하지 않으면 시그널이 유실되거나 핸들러가 중첩 실행될 수 있습니다.  
ACK 방식이 이 문제를 근본적으로 해결합니다.

**`signal()`보다 `sigaction()`을 써야 한다**  
`signal()`은 구현마다 동작이 다를 수 있고, 송신자 정보를 얻을 수 없습니다.  
이식성과 기능 면에서 `sigaction()`이 훨씬 낫습니다.

**통신 프로토콜은 단순해도 설계가 필요하다**  
시그널 두 개로 만든 통신이지만, 비트 순서(MSB/LSB), 문자열 끝 처리(`\0`), ACK 타이밍 등 프로토콜의 모든 세부 사항을 직접 정의해야 했습니다.  
단순한 통신 수단도 제대로 쓰려면 명확한 프로토콜이 필요하다는 것을 배웠습니다.

**비트 연산에 익숙해야 한다**  
문자를 비트로 분해하고 다시 복원하는 과정에서 비트 시프트(`<<`, `>>`), OR(`|`), AND(`&`) 연산을 자유롭게 다뤄야 합니다.

---

## 사용 기술

`C` `UNIX 시그널` `SIGUSR1/2` `sigaction` `kill` `pause` `비트 연산` `IPC`
