COMPOSE_FILE = /srcs/docker-compose.yml
DOCKER_COMPOSE = docker-compose -f $(COMPOSE_FILE)

.PHONY: up down restart build logs ps

up: ## Docker Compose를 실행 (백그라운드 모드)
	$(DOCKER_COMPOSE) up -d

down: ## Docker Compose를 종료 및 컨테이너 제거
	$(DOCKER_COMPOSE) down

restart: ## Docker Compose를 재시작
	$(DOCKER_COMPOSE) down
	$(DOCKER_COMPOSE) up -d

build: ## 이미지를 빌드
	$(DOCKER_COMPOSE) build

logs: ## 컨테이너 로그 보기
	$(DOCKER_COMPOSE) logs -f

ps: ## 현재 실행 중인 컨테이너 확인
	$(DOCKER_COMPOSE) ps

exec: ## 지정한 컨테이너에 bash로 접속
	$(DOCKER_COMPOSE) exec $(SERVICE) bash

help: ## 사용 가능한 Makefile 명령어 보기
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}'
