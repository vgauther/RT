/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bloc_lux_workspace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 17:02:36 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/29 17:03:15 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	bloc_work_space(t_env *e, t_sdl *s)
{
	t_vec	p1;
	t_vec	p2;

	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X, SIZE_Y / 8);
	p2 = init_point_2_coord(WIN_X, SIZE_Y / 8);
	horizontal_trait(p1, p2, CONTRAST, e);
	s->hud1.workspace_text.rect = init_sdl_rect(COL + SIZE_X + (COL4 / 18 * 2), (SIZE_Y - 10) /
	16 - 10, COL / 9 * 7, 25);
	print_text(ft_strdup("Workspace"), s->font.color[4], s,
	&s->hud1.workspace_text);
}

void	bloc_lux(t_sdl *s, t_env *e)
{
	char	*str;
	char	*str2;
	t_vec	p1;
	t_vec	p2;

	p1 = init_point_2_coord(SIZE_X - 90, 0);
	p2 = init_point_2_coord(SIZE_X - 90, SIZE_Y / 8);
	vertical_trait(p1, p2, CONTRAST, e);
	s->hud1.lux.title.rect = init_sdl_rect(SIZE_X - 40, 7, 70, 12);
	s->hud1.lux.percento.rect = init_sdl_rect(SIZE_X - 70, LINE / 2 - 6,
		60, 12);
	str = ft_itoa(e->amb * 100);
	str2 = ft_strjoin(str, " %");
	free(str);
	print_text(str2, s->font.color[1], s, &s->hud1.lux.percento);
	print_text(ft_strdup("Light"), s->font.color[4], s, &s->hud1.lux.title);
}
