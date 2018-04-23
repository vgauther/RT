/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_init_add_obj_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:52:21 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 19:53:04 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_add_obj_text_box(t_sdl *s)
{
	s->hud1.text_box[0] = init_sdl_rect(COL + SIZE_X + COL / 11, WIN_Y / 2,
		COL / 9 * 2, COL / 9);
	s->hud1.text_box[1] = init_sdl_rect(COL + SIZE_X + (COL / 11) * 4,
	WIN_Y / 2, COL / 9 * 2, COL / 9);
	s->hud1.text_box[2] = init_sdl_rect(COL + SIZE_X + (COL / 11) * 7,
	WIN_Y / 2, COL / 9 * 2, COL / 9);
	s->hud1.text_box[3] = init_sdl_rect(COL + SIZE_X + COL / 11, WIN_Y / 3 +
		WIN_Y / 4, COL / 9 * 2, COL / 9);
	s->hud1.text_box[4] = init_sdl_rect(COL + SIZE_X + (COL / 11) * 4,
	WIN_Y / 3 + WIN_Y / 4, COL / 9 * 2, COL / 9);
	s->hud1.text_box[5] = init_sdl_rect(COL + SIZE_X + (COL / 11) * 7,
	WIN_Y / 3 + WIN_Y / 4, COL / 9 * 2, COL / 9);
	s->hud1.add_obj_data[0].rect = s->hud1.text_box[0];
	s->hud1.add_obj_data[1].rect = s->hud1.text_box[1];
	s->hud1.add_obj_data[2].rect = s->hud1.text_box[2];
	s->hud1.add_obj_data[3].rect = s->hud1.text_box[3];
	s->hud1.add_obj_data[4].rect = s->hud1.text_box[4];
	s->hud1.add_obj_data[5].rect = s->hud1.text_box[5];
}

void	init_add_obj_selection_rect(t_sdl *s)
{
	s->hud1.r_add_obj[0] = init_sdl_rect(SIZE_X / 4 + SIZE_X + COL / 9, SIZE_Y
		/ 4, COL / 9 * 3, COL / 9 * 3);
	s->hud1.r_add_obj[1] = init_sdl_rect(SIZE_X / 4 + SIZE_X + (COL / 9 * 5),
	SIZE_Y / 4, COL / 9 * 3, COL / 9 * 3);
	s->hud1.r_add_obj[2] = init_sdl_rect(SIZE_X / 4 + SIZE_X + COL / 9, SIZE_Y
		/ 4 + COL / 9 * 4, COL / 9 * 3, COL / 9 * 3);
	s->hud1.r_add_obj[3] = init_sdl_rect(SIZE_X / 4 + SIZE_X + (COL / 9 * 5),
	SIZE_Y / 4 + COL / 9 * 4, COL / 9 * 3, COL / 9 * 3);
}
