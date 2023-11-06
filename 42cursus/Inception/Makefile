name = inception

all:
	bash srcs/requirements/wordpress/tools/make_dir.sh
	docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d

down:
	docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env down

clean: down
	docker system prune -a
	sudo rm -rf ~/data/wordpress/*
	sudo rm -rf ~/data/mariadb/*

.PHONY: all down clean
