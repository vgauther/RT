/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:22:27 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 12:01:33 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

SDL_Color		init_sdl_color(int r, int g, int b)
{
	SDL_Color ret;

	r = r < 0 ? 0 : r;
	g = g < 0 ? 0 : g;
	b = b < 0 ? 0 : b;
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	return (ret);
}

void			creat_sdl_color(t_sdl *s)
{
	s->font.color[0] = init_sdl_color(0, 0, 0);
	s->font.color[1] = init_sdl_color(255, 255, 255);
	s->font.color[2] = init_sdl_color(0, 0, 255);
	s->font.color[3] = init_sdl_color(0, 255, 0);
	s->font.color[4] = init_sdl_color(255, 0, 0);
}

void			open_font(t_sdl *s)
{
	if (!(s->font.bebas = TTF_OpenFont("src_font/bebas.ttf", 100)))
		ft_error("font error");
}

void			init_font(t_sdl *s)
{
	open_font(s);
	creat_sdl_color(s);
}

void			print_text(char *str, SDL_Color color, t_sdl *s, t_tex_rec *data)
{
	SDL_Surface		*surface;
	int				a;
	int				b;

	a = 0;
	b = 0;
	surface = TTF_RenderText_Solid(s->font.bebas, str, color);
	data->tex = SDL_CreateTextureFromSurface(s->renderer, surface);
	SDL_QueryTexture(data->tex, NULL, NULL, &a, &b);
	SDL_FreeSurface(surface);
	free(str);
}
