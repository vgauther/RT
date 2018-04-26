/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/26 12:14:47 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../libft/includes/libft.h"
#include <stdint.h>
#include <time.h>

void	init_hud_var(t_sdl *s)
{
	s->hud1.filter_token.sep = 0;
	s->hud1.filter_token.bw = 0;
	s->hud1.selectobj = 0;
	s->hud1.pipette = 0;
	s->hud1.shape_img.i = 0;
	s->hud1.add_obj = 0;
	s->hud1.box_picked = 42;
	s->hud1.ok.i = 17;
	s->hud1.tok.obj_select = -1;
	s->hud1.tok.change_color_obj = 0;
	s->hud1.color = 0;
}

void	loading(t_sdl *s, int i)
{
	SDL_Surface *surf;
	SDL_Rect	rect;
	SDL_Texture *tex;

	if (i == 0)
	{
		rect = init_sdl_rect(0, 0, WIN_X - 1, WIN_Y - 1);
		surf = SDL_LoadBMP("./img_srcs/load1.bmp");
	}
	else
	{
		rect = init_sdl_rect(0, 0, WIN_X - 1, WIN_Y - 1);
		surf = SDL_LoadBMP("./img_srcs/load2.bmp");
	}
	if (!(tex = SDL_CreateTextureFromSurface(s->renderer, surf)))
		ft_sdl_error("Texture error : ", SDL_GetError());
	SDL_RenderCopy(s->renderer, tex, NULL, &rect);
	SDL_RenderPresent(s->renderer);
	SDL_FreeSurface(surf);
}

void	call_loading(t_sdl *s)
{
	loading(s, 0);
	ft_wait();
	loading(s, 1);
	ft_wait();
}

void	ft_init(t_sdl *s, char *name, t_env *e)
{
	char *str;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	e->amb = 0.2;
	str = ft_strjoin("RT : Ray Tracer - ", name);
	s->window = SDL_CreateWindow(str, POS_WIN_X, POS_WIN_Y, WIN_X, WIN_Y,
			SDL_WINDOW_ALLOW_HIGHDPI);
	init_hud_var(s);
	free(str);
	if (s->window == NULL)
		exit(1);
	if ((s->renderer = SDL_CreateRenderer(s->window, -1, 0)) == NULL)
		ft_sdl_error("Renderer error : ", SDL_GetError());
	open_texture(s);
	if ((s->rendu = SDL_CreateRGBSurface(0, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
	if ((s->hud1.s_back = SDL_CreateRGBSurface(0, WIN_X, WIN_Y, 32, 0, 0, 0, 0))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
	free(s->rendu->pixels);
	free(s->hud1.s_back->pixels);
	if (!(e->pixels = (Uint32*)malloc(sizeof(Uint32) * SIZE_X * SIZE_Y)))
		ft_error("\nmalloc error\n");
	parser(name, e);
	init_is_neg(e);
	hud_init(s, e);
}

int		main(int ac, char **av)
{
	t_sdl	s;
	t_env	e;
	int		r;

	check_define();
	e.ca = init_cam();
	if ((r = 1) == 1 && ac != 2)
		ft_error("\nWrong number of arguments.\n");
	ft_init(&s, av[1], &e);
	raytracing(&e, &s);
	while (r)
	{
		while (SDL_PollEvent(&s.event))
		{
			if ((SDL_QUIT == s.event.type) ||
		(SDL_SCANCODE_ESCAPE == s.event.key.keysym.scancode))
				r = 0;
			else if ((SDL_KEYDOWN == s.event.type))
				mouv(s.event.key.keysym.scancode, &e, &s);
			else if ((SDL_MOUSEBUTTONDOWN == s.event.type))
				main_mouse(s.event.button.x, s.event.button.y, &s, &e);
		}
	}
	quit_sdl_proprely(&s);
	return (0);
}
