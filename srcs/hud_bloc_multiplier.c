/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bloc_multiplier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 00:19:34 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 21:40:40 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	bloc_multiplier_rect(t_env *e)
{
	t_rect rect;

	rect = init_rect((SIZE_X / 4 + 10) / 8, WIN_Y / 2 + WIN_Y / 4, (SIZE_X / 4
		+ 10) / 9, (SIZE_X / 4 + 10) / 9);
	print_rect(rect, e, 1, CONTRAST);
	rect = init_rect((SIZE_X / 4 + 10) / 8, WIN_Y / 2 + WIN_Y / 4 - ((SIZE_X /
		4 + 10) / 9) * 1.5, (SIZE_X / 4 + 10) / 9, (SIZE_X / 4 + 10) / 9);
	print_rect(rect, e, 1, CONTRAST);
	rect = init_rect((SIZE_X / 4 + 10) / 8, WIN_Y / 2 + WIN_Y / 4 + ((SIZE_X /
		4 + 10) / 9) * 1.5, (SIZE_X / 4 + 10) / 9, (SIZE_X / 4 + 10) / 9);
	print_rect(rect, e, 1, CONTRAST);
}

void	bloc_multiplier_bouton_rect(t_sdl *s)
{
	s->hud1.multi_bouton[0] = init_sdl_rect(COL / 8 + 5,
	WIN_Y / 2 + WIN_Y / 4 + 5, COL / 9 - 10, COL / 9 - 10);
	s->hud1.multi_bouton[1] = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5,
	WIN_Y / 2 + WIN_Y / 4 - ((SIZE_X / 4 + 10) / 9)
	* 1.5 + 5, (SIZE_X / 4 + 10) / 9 - 10, (SIZE_X / 4 + 10) / 9 - 10);
	s->hud1.multi_bouton[2] = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5, WIN_Y / 2
	+ WIN_Y / 4 + ((SIZE_X / 4 + 10) / 9) * 1.5 + 5,
	(SIZE_X / 4 + 10) / 9 - 10, (SIZE_X / 4 + 10) / 9 - 10);
}

void	bloc_multiplier(t_env *e, t_sdl *s)
{
	bloc_multiplier_rect(e);
	bloc_multiplier_bouton_rect(s);
	s->hud1.multi = 1;
	s->hud1.how_much = 1;
	print_text(ft_strdup("+ 1"), s->font.color[1], s, &s->hud1.multi_text[1]);
	s->hud1.multi_text[0].rect = init_sdl_rect(COL / 8 + 5 + (COL / 9 - 10) * 2,
	WIN_Y / 2 + WIN_Y / 4 + 5, (COL / 9), COL / 9 - 10);
	print_text(ft_strdup("+ 10"), s->font.color[1], s, &s->hud1.multi_text[0]);
	s->hud1.multi_text[1].rect = init_sdl_rect(COL / 8 + 5 + (COL / 9 - 10) * 2,
	WIN_Y / 2 + WIN_Y / 4 + 5 - (COL / 9) * 1.5, (COL / 9 - 10), COL / 9 - 10);
	print_text(ft_strdup("+ 100"), s->font.color[1], s, &s->hud1.multi_text[2]);
	s->hud1.multi_text[2].rect = init_sdl_rect(COL / 8 + 5 + (COL / 9 - 10) * 2,
	WIN_Y / 2 + WIN_Y / 4 + 5 + (COL / 9) * 1.5, (COL / 9 + 10), COL / 9 - 10);
}
