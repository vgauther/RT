/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:50:27 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/26 13:57:09 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	call_display_hud_function(t_sdl *s, t_env *e)
{
	display_pipette(s);
	display_work_space(s, e);
	display_cam(s);
	display_credits(s);
	display_all_bouton(s);
	display_light(s, e);
	display_multi_text(s);
}

void	display_hud(t_sdl *s, t_env *e)
{
	t_rect r1;

	if (s->hud1.tok.obj_select != -1)
	{
		r1 = init_rect(SIZE_X + COL4 + 20, WIN_Y / 2 + LINE + 100, 40, 40);
		print_rect(r1, e, 1, e->obj[s->hud1.tok.obj_select].color);
		actualize_background(s, e);
	}
	SDL_RenderCopy(s->renderer, s->hud1.t_back, NULL, NULL);
	SDL_RenderCopy(s->renderer, s->hud1.info.tex, NULL, &s->hud1.info.rect);
	SDL_RenderCopy(s->renderer, s->hud1.logo.tex, NULL, &s->hud1.logo.rect);
	SDL_RenderCopy(s->renderer, s->hud1.save.tex, NULL, &s->hud1.save.rect);
	SDL_RenderCopy(s->renderer, s->hud1.workspace_text.tex, NULL,
		&s->hud1.workspace_text.rect);
	call_display_hud_function(s, e);
}
