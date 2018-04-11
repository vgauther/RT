# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 20:24:21 by vgauther          #+#    #+#              #
#    Updated: 2018/04/11 12:09:21 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

#color
CL = \x1b[35m
GREEN = \033[1;32m
RED = \033[1;31m
CL2 = \x1b[36m
NC = \033[0m

NAME = rt

CC = gcc
CC_FLAGS = -g3 -Wall -Wextra -Werror

SDL_PATH = $(shell pwd)/lib/SDL
TTF_PATH = $(shell pwd)/lib/TTF
SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/
SDLHEADER_PATH = ./lib/SDL/include/SDL2/

SDL_FLG = -I $(SDLHEADER_PATH) -L $(SDL_PATH)/lib -lSDL2 -L $(TTF_PATH)/lib -lSDL2_ttf
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = rt.h

SRC_NAME = 	lux.c \
			hud.c  \
			main.c  \
			mouse.c  \
			error.c   \
			parser.c   \
			ray_cone.c  \
			tools_tab.c  \
			pars_spot.c   \
			raytracer.c    \
			pars_cone.c     \
			ray_sphere.c     \
			pars_check.c      \
			pars_sphere.c      \
			tools_color.c       \
			open_texture.c       \
			tools_vector.c        \
			ray_cylindre.c         \
			pars_cylindre.c         \
			ft_put_pixels.c          \
			tools_geometric.c         \
			print_text.c               \
			filter.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@make sdl_if
	@gcc ./make_srcs/dessin.c -lm -L $(LFT_PATH) -lft
	@./a.out
	@rm a.out
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft $(SDL_FLG)
	@echo "$(GREEN)[✓] EXECUTABLE RT DONE$(NC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@echo "$(RED)[-] LIBFT CLEANED$(NC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[-] .o DELETED$(NC)"

sdl_if:
	@make -C ./lib

fclean:
	@make clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(RED)[-] EXECUTABLE RT DELETED$(NC)"

fclean_all:
	@make fclean
	@make cllib

clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re:
	@make fclean
	@make all

cllib:
	@make -C ./lib clean

clfreetype:
	@make -C ./lib freetype_clean

clttf:
	@make -C ./lib ttf_clean

clsdl:
	@make -C ./lib sdl_clean

push:
	@make fclean_all
	@git add *
	@git commit -m "GIT ADD * via Makefile"
	@git push
	@echo "$(GREEN)[✓] PUSH DONE$(NC)"

coffee:
	@echo "$(RED)warning it's hot$(NC)"
