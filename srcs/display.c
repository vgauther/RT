/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:52 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/26 22:17:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	display_all_bouton(t_sdl *s)
{
	int i;

	i = -1;
	while (++i != 19)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[s->hud1.bouton[i].i], NULL,
			&s->hud1.bouton[i].rect)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
	}
}

void	display_work_space(t_sdl *s, t_env *e)
{
	if ((s->hud1.shape_img.i >= 12 && s->hud1.shape_img.i <= 15) ||
	s->hud1.add_obj == 2)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[s->hud1.shape_img.i], NULL,
			&s->hud1.shape_img.rect)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
	}
	if (s->hud1.add_obj == 1)
		add_obj_selection_display(s);
	if (s->hud1.add_obj == 2 || s->hud1.tok.obj_select != -1)
		add_obj_menu(s, e, s->hud1.tok.obj_select);
}

void	display_pipette(t_sdl *s)
{
	if (s->hud1.pipette == 1)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[16], NULL,
			&s->hud1.color_selector)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
	}
}

void	display_light(t_sdl *s, t_env *e)
{
	char	*str;
	char	*str2;
	int		x;

	x = ((int)(e->amb * 100) % 10 == 0) ? e->amb * 100 : e->amb * 100 + 1;
	str = ft_itoa(x);
	str2 = ft_strjoin(str, " %");
	free(str);
	print_text(str2, s->font.color[1], s, &s->hud1.lux.percento);
	if ((SDL_RenderCopy(s->renderer, s->hud1.lux.percento.tex, NULL,
		&s->hud1.lux.percento.rect)) < 0)
		ft_sdl_error("Renderer : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.lux.title.tex, NULL,
		&s->hud1.lux.title.rect)) < 0)
		ft_sdl_error("Renderer : ", SDL_GetError());
}

void	display(t_sdl *s, t_env *e)
{
	SDL_Rect	rendu_rect;

	SDL_RenderClear(s->renderer);
	recup_cam_to_print(s, e);
	s->rendu->pixels = e->pixels;
	rendu_rect = init_sdl_rect(SIZE_X / 4, SIZE_Y / 8, SIZE_X, SIZE_Y);
	if ((s->texture = SDL_CreateTextureFromSurface(s->renderer, s->rendu))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	display_hud(s, e);
	if ((SDL_RenderCopy(s->renderer, s->texture, NULL, &rendu_rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	display_pipette(s);
	SDL_RenderPresent(s->renderer);
}
