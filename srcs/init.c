/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <ebertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:28:43 by ebertin           #+#    #+#             */
/*   Updated: 2018/05/02 17:13:01 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_init_sub(t_sdl *s, t_env *e, char *name)
{
	free(s->rendu->pixels);
	free(s->hud1.s_back->pixels);
	parser(name, e);
	init_is_neg(e);
	hud_init(s, e);
}

void		ft_init(t_sdl *s, char *name, t_env *e)
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
	if (!(e->pixels = (Uint32*)ft_memalloc(sizeof(Uint32) * SIZE_X * SIZE_Y)))
		ft_error("\nmalloc error\n");
	ft_init_sub(s, e, name);
}
