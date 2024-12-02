COMPOSE_FILE = ./srcs/docker-compose.yml
DOCKER_COMPOSE = docker compose -f $(COMPOSE_FILE)

up: ## Execute
	$(DOCKER_COMPOSE) up

down: ## Quit and remove containers
	$(DOCKER_COMPOSE) down

restart:
	$(DOCKER_COMPOSE) down
	$(DOCKER_COMPOSE) up -d

build: ## Image build
	$(DOCKER_COMPOSE) build

logs:
	$(DOCKER_COMPOSE) logs -f

ps: ## Check current containers
	$(DOCKER_COMPOSE) ps

.PHONY: up down restart build logs ps
