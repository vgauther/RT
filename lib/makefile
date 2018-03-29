# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 20:24:21 by vgauther          #+#    #+#              #
#    Updated: 2018/03/28 16:00:44 by fde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

#color
CL = \x1b[35m
GREEN = \033[1;32m
RED = \033[1;31m
CL2 = \x1b[36m
NC = \033[0m

NAME = SDL
SDL_PATH = $(shell pwd)/SDL

ifneq ("$(wildcard $(SDL_PATH))","")
FILE = 1
else
FILE = 0
endif

all: $(NAME)

$(NAME):
	@if [ $(FILE) = 0 ]; then \
	make sdl_2 -j8; \
	fi

sdl_2:
	@rm -rf $(SDL_PATH)
	@mkdir $(SDL_PATH)
	@cd $(SDL_PATH) && $(SDL_PATH)/../SDL2-2.0.8/configure --prefix=$(SDL_PATH) && make && make install
	@echo "$(GREEN)[✓] SDL 2.0 COMPILED$(NC)"

clean:
	@rm -rf $(SDL_PATH)
	@echo "$(RED)[-] LIB SDL 2.0 CLEANED$(NC)"
