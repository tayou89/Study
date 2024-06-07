COMPOSE_FILE = srcs/docker-compose.yml

all: build up

restart: down up

build:
	docker compose -f $(COMPOSE_FILE) build

up:
	docker compose -f $(COMPOSE_FILE) up

down:
	docker compose -f $(COMPOSE_FILE) down

logs:
	docker compose -f $(COMPOSE_FILE) logs

clean:
	docker compose -f $(COMPOSE_FILE) down --rmi all -v --remove-orphans

fclean: clean
	docker system prune -a --force

re: fclean all

status:
	docker compose -f $(COMPOSE_FILE) ps

.PHONY: all build up down logs clean rebuild status
