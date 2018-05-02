# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 20:24:21 by vgauther          #+#    #+#              #
#    Updated: 2018/05/02 16:42:19 by ebertin          ###   ########.fr        #
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

SRC_NAME = 	lux.c  \
			main.c  \
			init.c	 \
			trait.c   \
			mouse.c    \
			error.c     \
			rotate.c     \
			filter.c      \
			parser.c       \
			ft_wait.c       \
			reflect.c        \
			texture.c	      \
			loading.c 	       \
			print_text.c        \
			open_texture.c       \
			check_define.c        \
			ft_put_pixels.c        \
			ft_realloc_obj.c        \
			user_key_interaction.c   \
			transparence.c 			  \
			\
			text_box_add_obj.c \
			text_box_del_char.c \
			\
			raytracer.c \
			ray_plan.c   \
			ray_cone.c    \
			ray_sphere.c   \
			ray_cylindre.c  \
			ray_disque.c  \
			\
			pars_spot.c \
			pars_cone.c  \
			pars_plan.c   \
			pars_check.c   \
			pars_sphere.c   \
			pars_cylindre.c  \
			pars_disque.c  \
			\
			mouse_plus.c        \
			mouse_camera.c       \
			mouse_pipette.c       \
			mouse_add_obj.c        \
			mouse_selector.c        \
			mouse_modify_ray_angle.c \
			\
			tools_tab.c \
			tools_key.c  \
			tools_cam.c   \
			tools_sdl.c    \
			tools_color.c   \
			tools_color2.c 	 \
			tools_vector.c    \
			tools_vector_2.c   \
			tools_geometric.c   \
			\
			display.c            \
			display_hud.c         \
			display_credits.c      \
			display_add_obj_menu.c  \
			display_cam_multi_text.c \
			\
			hud.c                     \
			hud_draw.c                 \
			hud_color_select.c          \
			hud_create_bouton.c          \
			hud_init_info_mess.c          \
			hud_bloc_multiplier.c          \
			hud_init_add_obj_menu.c         \
			hud_bloc_lux_workspace.c		 \
			hud_recup_cam_to_print.c 		  \
			hud_bloc_credits_save_logo_cam.c   \

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

norme:
	@make norme_srcs
	@make norme_includes

norme_includes:
	@echo "$(GREEN)- INCLUDES -$(NC)"
	@norminette includes/*.h

norme_srcs:
	@echo "$(GREEN)- SRCS -$(NC)"
	@norminette srcs/
