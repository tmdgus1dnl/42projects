# born2beroot

> 42Seoul | Linux · VirtualBox | 점수: 125/125 | 소요 기간: 1주 | 재시도: 0회

VirtualBox에서 Debian 서버를 처음부터 설정하는 시스템 관리 프로젝트입니다.  
GUI 없이 최소한의 환경에서 LVM 파티셔닝, sudo 정책, SSH, 방화벽, 보안 강화, 자동화 모니터링 스크립트까지 직접 구성했습니다.

---

## 목차

- [OS 선택](#os-선택)
- [LVM 파티셔닝](#lvm-파티셔닝)
- [보안 설정](#보안-설정)
- [비밀번호 정책](#비밀번호-정책)
- [sudo 설정](#sudo-설정)
- [모니터링 스크립트](#모니터링-스크립트)
- [보너스: 웹 서비스 구축](#보너스-웹-서비스-구축)
- [깨달은 점](#깨달은-점)

---

## OS 선택

과제에서 Debian과 Rocky 중 하나를 선택할 수 있습니다.

| | Debian | Rocky |
|---|---|---|
| 기반 | 독립 배포판 | RHEL 계열 (CentOS 후속) |
| 목적 | 안정성 + 자유 소프트웨어 | 기업 환경 안정성, 보안 |
| 보안 모듈 | AppArmor | SELinux |
| 패키지 관리 | `apt` / `aptitude` | `dnf` |

**Debian을 선택한 이유**  
Rocky는 기업 환경에 최적화되어 있어 초보자에게 복잡하게 다가올 수 있습니다.  
사용자 친화적이고 문서가 풍부한 Debian이 학습 목적에 적합하다고 판단했습니다.

**apt vs aptitude**  
둘 다 Debian 패키지 관리 도구지만 성격이 다릅니다.  
`apt`는 단순 명령형 도구이고, `aptitude`는 텍스트 UI를 제공하는 대화형 도구입니다.  
의존성 처리와 우선순위 측면에서 `aptitude`가 더 세밀하게 처리하며 여러 해결 방법을 제시합니다.

---

## LVM 파티셔닝

**파티션**은 하나의 물리 디스크를 여러 논리 영역으로 나누는 것입니다. 각 파티션은 독립적인 파일 시스템을 가집니다.

**LVM(Logical Volume Manager)** 은 파티션보다 유연한 디스크 관리 방법입니다.  
여러 디스크/파티션을 하나의 큰 저장 공간으로 통합하거나, 하나를 여러 볼륨으로 나눠 쓸 수 있습니다.  
볼륨 크기를 동적으로 조절할 수 있고 스냅샷, 데이터 이동, 디스크 확장 등이 용이합니다.

**마운트**는 저장 공간을 특정 디렉토리에 연결하는 과정입니다.  
마운트 포인트로 지정된 디렉토리를 통해 해당 파티션의 파일 시스템에 접근할 수 있습니다.  
파티션이나 LVM을 설정할 때 파일 시스템(EXT4 등)과 마운트 포인트(`/`, `/home`, `/boot` 등)를 지정하는 이유가 여기에 있습니다.

**암호화 파티션 구성**

```
sda
├── sda1    /boot         (부팅 파티션, 비암호화)
└── sda2    LVM (암호화)
    ├── root    /
    ├── swap    swap
    ├── home    /home
    ├── var     /var
    ├── srv     /srv
    ├── tmp     /tmp
    └── var--log /var/log
```

---

## 보안 설정

### UFW (방화벽)

Debian의 기본 방화벽 도구입니다. `iptables` 위에서 동작하는 프론트엔드로, 사용이 간단합니다.  
포트 4242만 열어두고 나머지는 모두 차단합니다.

```bash
ufw enable
ufw allow 4242
ufw status
```

고급 보안이 필요할 때는 `iptables` 명령어를 직접 사용할 수 있습니다.

### SSH

네트워크 통신을 암호화하는 프로토콜로, 원격 접속에 사용합니다.  
Public Key로 메시지를 암호화하고, 수신자의 Private Key로만 복호화할 수 있습니다.

적용한 설정:
- **포트**: 기본 22 → 4242로 변경
- **root 로그인 차단**: `PermitRootLogin no`
- **포트 포워딩**: VirtualBox 호스트의 4242 포트 → 가상 머신 4242 포트

```bash
# /etc/ssh/sshd_config
Port 4242
PermitRootLogin no
```

### AppArmor

애플리케이션에 보안 프로파일을 적용해 파일/디렉토리 접근, 권한 등 행동을 제어합니다.  
프로파일별 로그가 남아 이슈 추적이 가능합니다.

SELinux(Rocky에서 사용)는 강제성이 있어 위반 시 동작을 차단하지만,  
AppArmor는 위반 시 차단 없이 로그에 경고만 남기는 권고 방식입니다.

```bash
aa-status    # AppArmor 상태 확인
```

---

## 비밀번호 정책

**정책 내용**

| 항목 | 설정값 |
|---|---|
| 만료 주기 | 30일 |
| 변경 후 최소 유지 기간 | 2일 |
| 만료 7일 전 경고 | 활성화 |
| 최소 길이 | 10자 |
| 대문자 | 최소 1개 (`ucredit -1`) |
| 숫자 | 최소 1개 (`dcredit -1`) |
| 이전 비밀번호와 다른 문자 | 7개 이상 |
| 사용자 이름 포함 금지 | 적용 |

**설정 파일**
- `/etc/login.defs` — 만료 주기, 경고 기간
- `/etc/pam.d/common-password` — 복잡도 규칙 (`pam_pwquality`)

**root 계정 예외**  
과제 명세에 따라 root 계정은 "이전 비밀번호와 7개 이상 달라야 한다" 정책만 제외합니다.  
`enforce_for_root` 옵션을 적용하지 않으면 root는 비밀번호 변경 시 이전 비밀번호를 체크하지 않아 따로 예외처리가 필요 없습니다.

```bash
chage -l [username]    # 비밀번호 정책 확인
passwd -e [username]   # 비밀번호 즉시 만료 (다음 로그인 시 변경 강제)
```

---

## sudo 설정

**sudo**는 "super user do"의 약자입니다.  
일반 사용자에게 제한된 범위에서 root 권한을 부여해, 시스템 보안을 유지하면서 필요한 작업을 수행하게 합니다.  
비밀번호를 입력해야 하므로 명령을 한 번 더 확인하게 되고, 모든 sudo 사용 로그가 남아 추적이 가능합니다.

**적용한 sudo 정책**

```bash
# /etc/sudoers (sudo visudo로 편집)
Defaults  passwd_tries=3          # 비밀번호 시도 횟수 제한
Defaults  badpass_message="..."   # 잘못된 비밀번호 입력 시 출력할 메시지
Defaults  logfile="/var/log/sudo/sudo.log"  # 로그 저장 경로
Defaults  log_input, log_output   # 입출력 로그 기록
Defaults  requiretty              # TTY 환경에서만 sudo 허용
Defaults  secure_path="..."       # sudo 사용 시 허용할 PATH 제한
```

**그룹 설정**
- `sudo` 그룹: sudo 권한 부여
- `user42` 그룹: 과제 요구 사항에 따라 생성

---

## 모니터링 스크립트

`monitoring.sh` — `cron`으로 **10분마다** 전체 터미널에 `wall`로 브로드캐스트합니다.

```bash
# crontab -e
*/10 * * * * /usr/local/bin/monitoring.sh
```

**출력 항목 및 사용 명령어**

| 항목 | 명령어 |
|---|---|
| OS / 커널 버전 | `uname -a` |
| 물리 CPU 수 | `/proc/cpuinfo`의 `physical id` — `sort \| uniq -u` 로 중복 제거 |
| 가상 CPU 수 | `/proc/cpuinfo`의 `processor` 수 |
| RAM 사용량 / 전체 | `free -m` → `awk`로 포맷 |
| 디스크 사용량 | `df -BM` / `df -BG` → `grep -LVM`으로 LVM 파티션 추출 후 합산 |
| CPU 사용률 | `mpstat` → 유휴율을 역산 |
| 마지막 부팅 시간 | `who -b` → `$3, $4` 출력 |
| LVM 사용 여부 | `lsblk \| grep LVM \| wc -l` → 0이면 no, 1 이상이면 yes |
| 활성 TCP 연결 수 | `ss -t \| grep ESTABLISHED \| wc -l` |
| 로그인 중인 사용자 수 | `who \| wc -l` |
| IPv4 / MAC 주소 | `hostname -I` / `ip link` |
| sudo 실행 횟수 | `journalctl _COMM=sudo \| grep COMMAND \| wc -l` |

**cron 비활성화/활성화**

```bash
sudo systemctl disable cron    # 부팅 시 자동 실행 끄기
sudo systemctl enable cron     # 다시 켜기
```

---

## 보너스: 웹 서비스 구축

가상 머신에 lighttpd + PHP + MariaDB + WordPress를 직접 설치하고 설정했습니다.

- **lighttpd**: 경량 웹서버. 빠른 처리 속도와 낮은 메모리 사용이 특징.
- **PHP + php-fpm**: WordPress 처리를 위한 PHP 실행 환경. `lighttpd-enable-mod fastcgi-php` 적용 필수.
- **MariaDB**: WordPress 데이터 저장용 DB.
- **WordPress**: `/var/www/html`에 압축 해제 후 `wp-config.php` 설정.

**Fail2ban**  
SSH를 통한 무차별 대입 공격을 차단하는 서비스입니다.  
특정 IP에서 SSH 로그인 실패가 3회 이상 발생하면 설정한 시간 동안 해당 IP를 차단합니다.

```
설정 파일: /etc/fail2ban/jail.d/jail.local
로그 확인: /var/log/auth.log
```

---

## 깨달은 점

**Linux 시스템 전반을 직접 만져본 첫 경험**  
패키지 설치부터 파티셔닝, 방화벽, SSH, 크론, 쉘 스크립트까지 Linux 서버 운영의 기본을 직접 다뤘습니다.

**파이프의 데이터 흐름**  
모니터링 스크립트를 작성하면서 파이프(`|`)의 동작을 깊이 이해했습니다.  
앞의 명령어 출력이 뒤의 명령어 입력으로 전달되므로, 데이터 흐름 방향을 항상 의식해야 합니다.  
명령어 치환(`$()`, 백틱)을 활용하면 명령어 실행 결과를 문자열 안에 포함시킬 수 있습니다.

**환경 변수와 이름 정확성**  
사소한 이름 오타 하나가 인증 실패, 서비스 오동작으로 이어집니다.  
inception 과제와 마찬가지로 환경 변수, 설정 키 이름은 항상 정확히 확인해야 합니다.

**보안은 계층적으로 구성된다**  
UFW(방화벽) + SSH 설정 + AppArmor + sudo 정책 + 비밀번호 정책 + Fail2ban 각각은 단독으로는 완전하지 않습니다.  
여러 계층의 보안이 함께 작동할 때 더 강한 방어가 됩니다.

---

## 사용 기술

`Debian` `LVM` `UFW` `SSH` `AppArmor` `sudo` `cron` `bash` `pam_pwquality` `Fail2ban` `lighttpd` `MariaDB` `WordPress` `VirtualBox`
