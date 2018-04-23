/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cam_multi_text.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:34:55 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 19:35:38 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	display_multi_text(t_sdl *s)
{
	if ((SDL_RenderCopy(s->renderer, s->hud1.multi_text[0].tex, NULL,
		&s->hud1.multi_text[0].rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.multi_text[1].tex, NULL,
		&s->hud1.multi_text[1].rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.multi_text[2].tex, NULL,
		&s->hud1.multi_text[2].rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->tex[0], NULL,
		&s->hud1.multi_bouton[s->hud1.multi])) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
}

void	display_cam(t_sdl *s)
{
	int		*r;
	int		i;

	if (!(r = (int*)malloc(sizeof(int) * 7)))
		ft_error("\nMalloc Error\n");
	r[0] = SDL_RenderCopy(s->renderer, s->hud1.cam.title.tex, NULL,
		&s->hud1.cam.title.rect);
	r[1] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_x.tex, NULL,
		&s->hud1.cam.pos_x.rect);
	r[2] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_y.tex, NULL,
		&s->hud1.cam.pos_y.rect);
	r[3] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_z.tex, NULL,
		&s->hud1.cam.pos_z.rect);
	r[4] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_x.tex, NULL,
		&s->hud1.cam.rot_x.rect);
	r[5] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_y.tex, NULL,
		&s->hud1.cam.rot_y.rect);
	r[6] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_z.tex, NULL,
		&s->hud1.cam.rot_z.rect);
	i = -1;
	while (++i < 7)
		if (r[i] < 0)
			ft_error("\nRender copy Error : Camera display\n");
	free(r);
}
