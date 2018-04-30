/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:35:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/30 19:36:50 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*
** function destroy window and quit all sdl things
*/

void		quit_sdl_proprely(t_sdl *s)
{
	SDL_DestroyWindow(s->window);
	TTF_Quit();
	SDL_Quit();
}

SDL_Rect	init_sdl_rect(int x, int y, int w, int h)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

/*
** print all draw made on hud surface
*/

void		actualize_background(t_sdl *s, t_env *e)
{
	s->hud1.s_back->pixels = e->hud;
	if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer,
		s->hud1.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
}
