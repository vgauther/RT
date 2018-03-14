# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 20:24:21 by vgauther          #+#    #+#              #
#    Updated: 2018/03/14 14:57:03 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

#color
CL=\x1b[35m
GREEN=\033[1;32m
RED=\033[1;31m
CL2=\x1b[36m
NC=\033[0m

NAME = rt

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SDL_PATH = $(shell pwd)/lib/SDL
SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/
SDLHEADER_PATH = ./lib/SDL/include/SDL2/

SDL_FLG = -I $(SDLHEADER_PATH) -L $(SDL_PATH)/lib -lSDL2
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = rt.h

SRC_NAME = main.c error.c parser.c ray.c plan.c lux.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@gcc ./make_srcs/dessin.c -lm -L $(LFT_PATH) -lft
	@./a.out
	@rm a.out
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft $(SDL_FLG)
	@echo "[✓] EXECUTABLE RT DONE"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@echo "$(RED)[-] LIBFT CLEANED$(NC)"
	@rm -rf $(OBJ_PATH)
		@echo "$(RED)[-] .o DELETED$(NC)"

fclean:
	@make clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re:
	@make fclean
	@make all

clsdl:
	@rm -rf $(SDL_PATH)
	@echo "$(RED)[-] LIB SDL 2.0 CLEANED$(NC)"

sdl_2:
	@rm -rf $(SDL_PATH)
	@mkdir $(SDL_PATH)
	@cd $(SDL_PATH) && $(SDL_PATH)/../SDL2-2.0.5/configure --prefix=$(SDL_PATH) && make && make install
	@echo "$(GREEN)[✓] SDL 2.0 COMPILED$(NC)"

sdl:
	@make -j8 sdl_2

coffee:
	@echo "$(RED)warning it's hot$(NC)"

push:
	@make fclean
	@make clsdl
	@git add *
	@git commit -m "GIT ADD * via Makefile"
	@git push
	@echo "$(GREEN)[✓] PUSH DONE$(NC)"
