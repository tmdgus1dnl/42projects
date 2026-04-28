# Inception

> 42Seoul | Docker · Shell Script | 점수: 100/100 | 소요 기간: 3주 | 재시도: 1회

VirtualBox 가상 머신 안에서 Docker와 docker-compose로 다중 컨테이너 웹 인프라를 구축하는 프로젝트입니다.  
가상 환경 속에 또 다른 가상 환경(컨테이너)을 띄운다는 점에서 영화 인셉션과 이름이 같습니다.

---

## 목차

- [과제 개요](#과제-개요)
- [아키텍처](#아키텍처)
- [컨테이너 구성](#컨테이너-구성)
- [docker-compose](#docker-compose)
- [Dockerfile 핵심 규칙](#dockerfile-핵심-규칙)
- [시작 스크립트](#시작-스크립트)
- [트러블슈팅](#트러블슈팅)
- [깨달은 점](#깨달은-점)

---

## 과제 개요

VirtualBox 가상 머신 안에서 컨테이너 3개를 직접 빌드해 연결합니다.  
`nginx:latest` 같은 사전 빌드 이미지 사용이 금지되며, 모든 컨테이너를 Debian/Alpine 베이스 이미지부터 Dockerfile로 직접 만들어야 합니다.

| 컨테이너 | 역할 |
|---|---|
| nginx | 웹서버, TLS 종료, 리버스 프록시 |
| wordpress + php-fpm | CMS 애플리케이션 서버 |
| mariaDB | 데이터베이스 |

---

## 아키텍처

```
[브라우저]
    |
    | HTTPS :443
    v
[nginx 컨테이너]          ← 정적 파일 직접 서빙
    |                       동적 요청은 wordpress로 전달
    | FastCGI :9000
    v
[wordpress 컨테이너]      ← PHP 처리 (php-fpm)
    |                       DB에 데이터 읽기/쓰기 요청
    | MySQL :3306
    v
[mariaDB 컨테이너]        ← WordPress 데이터 저장
```

이 구조는 웹 서비스의 **3계층 구조(3-Tier Architecture)** 를 그대로 구현한 것입니다.

- **프레젠테이션 계층** — nginx (사용자와 직접 통신)
- **애플리케이션 계층** — wordpress + php-fpm (비즈니스 로직 처리)
- **데이터 계층** — mariaDB (데이터 영속 저장)

각 계층이 분리되어 있어 한 컨테이너를 수정해도 다른 계층에 영향을 주지 않습니다.

---

## 컨테이너 구성

### nginx

- 443 포트만 외부에 노출 (HTTP 차단)
- 빌드 시 자체 서명 인증서(self-signed) 생성해 HTTPS 적용
- WordPress 볼륨(`/var/www/html`)을 공유해 정적 파일 직접 서빙
- PHP 요청은 `fastcgi_pass wordpress:9000`으로 WordPress 컨테이너에 전달

### wordpress + php-fpm

- php-fpm을 포그라운드로 실행 (`--nodaemonize`)
- `expose: "9000"`으로 내부 네트워크에만 포트 노출 (외부에서 직접 접근 불가)
- 컨테이너 시작 시 MariaDB 준비 여부 확인 후 WordPress 초기화 수행
- `.env`에서 DB 접속 정보, 관리자 계정 등 환경 변수로 주입

### mariaDB

- WordPress DB, 사용자, 권한을 컨테이너 시작 스크립트에서 자동 생성
- DB 데이터는 바인드 마운트 볼륨으로 호스트에 영구 저장

---

## docker-compose

```yaml
services:
  nginx:
    image: nginx:inception
    build:
      context: ./requirements/nginx
    restart: always
    volumes:
      - WordPress:/var/www/html
    ports:
      - "443:443"
    networks:
      - intra

  wordpress:
    image: wordpress:inception
    build:
      context: ./requirements/wordpress
    restart: always
    env_file: .env
    volumes:
      - WordPress:/var/www/html
    expose:
      - "9000"
    networks:
      - intra

  mariadb:
    image: mariadb:inception
    build:
      context: ./requirements/mariadb
    restart: always
    env_file: .env
    volumes:
      - DB:/var/lib/mysql
    networks:
      - intra

volumes:
  DB:
    driver: local
    driver_opts:
      o: bind
      type: none
      device: /home/seunghan/data/var/lib/mysql
  WordPress:
    driver: local
    driver_opts:
      o: bind
      type: none
      device: /home/seunghan/data/var/www/html

networks:
  intra:
    driver: bridge
```

**볼륨은 바인드 마운트 방식으로 생성했습니다.**  
호스트의 특정 경로를 컨테이너 내부 경로와 직접 연결해 파일을 직접 관리할 수 있습니다.  
단, 컨테이너 시작 시 볼륨 경로가 호스트 디렉토리로 덮어씌워지므로, Dockerfile에서 해당 경로에 파일을 넣어도 시작 후 사라집니다. 파일 이동은 반드시 시작 스크립트에서 처리해야 합니다.

**브릿지 네트워크(`intra`)로 컨테이너 간 통신을 격리합니다.**  
같은 네트워크에 속한 컨테이너들은 컨테이너 이름으로 서로를 찾을 수 있습니다. (`wordpress:9000`, `mariadb:3306`)

---

## Dockerfile 핵심 규칙

- 베이스 이미지는 `debian:bullseye` 사용 (Debian bullseye 공식 레포에 PHP 7.4 포함)
- `tail -f`, `sleep infinity` 같은 프로세스 유지 트릭 없이, 서비스 프로세스를 PID 1로 포그라운드 실행
- 설정 파일은 호스트에서 미리 작성해 `COPY`로 컨테이너 내부에 복사

**서비스별 설정 파일 확장자**

| 서비스 | 설정 파일 확장자 |
|---|---|
| mariaDB / MySQL | `.cnf` |
| nginx | 확장자 없음 |
| php-fpm | `.conf` |
| WordPress | `.php` (`wp-config.php`) |

---

## 시작 스크립트

컨테이너 시작 순서를 보장할 수 없기 때문에, WordPress가 시작할 때 MariaDB가 아직 준비되지 않았을 수 있습니다.  
`depends_on`은 컨테이너 시작 기준이지 내부 서비스 준비 기준이 아니므로, 직접 쉘 스크립트로 제어했습니다.

```bash
#!/bin/bash

# MariaDB 서비스 준비 확인 (준비될 때까지 대기)
until mysqladmin ping -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_USER_PASSWORD" --silent; do
    echo "Waiting for database connection..."
    sleep 2
done

# WordPress 테이블 존재 여부 확인
if ! echo 'SHOW TABLES;' | mysql -h"$MYSQL_HOST" -u"$MYSQL_USER" \
    -p"$MYSQL_USER_PASSWORD" "$MYSQL_DATABASE" | grep -q 'wp_options'; then
    echo "WordPress tables not found. Initializing..."
    wp core install --url="$WP_URL" ...
else
    echo "WordPress tables already exist. Skipping setup."
fi

exec php-fpm7.4 --nodaemonize
```

- `until ~ do ~ done` — `mysqladmin ping`이 성공(반환 코드 0)할 때까지 반복
- `if ~ then ~ else ~ fi` — 테이블 존재 여부에 따라 초기화 여부 결정
- `exec` — 스크립트 프로세스를 php-fpm 프로세스로 교체 (PID 1 유지)

---

## 트러블슈팅

**볼륨 경로 파일 사라짐**  
Dockerfile에서 볼륨 경로에 파일을 설치했는데 컨테이너 시작 후 사라졌습니다.  
컨테이너 시작 시 볼륨이 바인드된 호스트 디렉토리로 해당 경로를 덮어씌우기 때문이었습니다.  
파일 이동 작업을 Dockerfile이 아닌 시작 스크립트로 옮겨 해결했습니다.

**환경 변수가 이미지 빌드 시점에 적용 안 됨**  
`.env` 파일의 환경 변수를 Dockerfile 내부에서 사용했는데 적용이 안 됐습니다.  
docker-compose의 `env_file`은 컨테이너 실행 시점에 적용되고, 이미지 빌드 시점에는 적용되지 않습니다.  
환경 변수가 필요한 초기화 작업은 시작 스크립트로 분리해 해결했습니다.

**환경 변수 이름 오타**  
`MYSQL_USER_PASSWORD`를 `MYSQL_PASSWORD`로 잘못 작성해 MariaDB 접속이 되지 않았습니다.  
`wp-config.php`에 비밀번호가 빈 값으로 적히고, `wp core install` 같은 명령어도 전부 실패했습니다.  
환경 변수 이름은 모든 컨테이너에서 동일하게 사용되므로 오타 하나가 연쇄 오류로 이어집니다.

**docker-compose 파일에 탭 사용 불가**  
YAML 파일 특성상 들여쓰기를 탭이 아닌 공백으로만 해야 합니다. 탭이 섞이면 파싱 오류가 발생합니다.

**상위 컨테이너 빌드 실패 시 하위 작업 CANCELED**  
`docker compose up`은 컴포즈 파일 위에서 아래 순으로 이미지를 빌드합니다.  
경로 오류나 존재하지 않는 파일 참조로 빌드가 실패하면 이후 작업들이 모두 CANCELED됩니다.

---

## 깨달은 점

**컨테이너는 프로세스다**  
도커 컨테이너는 운영체제가 아닌, 호스트 커널 위에서 격리된 채 실행되는 프로세스입니다.  
그래서 컨테이너 안의 서비스가 종료되면 컨테이너 자체도 종료됩니다. `restart: always` 옵션이 중요한 이유입니다.

**실행 순서는 보장되지 않는다**  
`depends_on`은 컨테이너 시작 순서만 제어할 뿐, 내부 서비스가 준비됐는지는 보장하지 않습니다.  
컨테이너 간 의존성이 있다면 시작 스크립트에서 직접 준비 여부를 확인해야 합니다.

**환경 변수 적용 시점을 구분해야 한다**  
`env_file`은 컨테이너 실행 시점에 적용되고, `ARG`는 빌드 시점에 적용됩니다.  
필요한 시점에 맞는 방법을 선택하지 않으면 빌드 오류나 런타임 오류로 이어집니다.

**볼륨은 Dockerfile보다 나중에 마운트된다**  
Dockerfile에서 아무리 파일을 넣어도 볼륨이 마운트되는 순간 덮어씌워집니다.  
볼륨 경로에 필요한 파일은 반드시 컨테이너 시작 후 스크립트로 처리해야 합니다.

**쉘 스크립트의 반환 코드가 핵심이다**  
`until`, `if` 같은 제어 구조는 모두 명령어의 반환 코드(0 = 성공, 비0 = 실패)를 기준으로 동작합니다.  
이를 이해하면 컨테이너 시작 흐름을 쉘 스크립트 하나로 세밀하게 제어할 수 있습니다.

---

## 사용 기술

`Docker` `docker-compose` `nginx` `WordPress` `php-fpm` `MariaDB` `Shell Script` `TLS` `VirtualBox`
