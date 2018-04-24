/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_del_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:30:04 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/24 13:15:22 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		del_char2(t_env *e, t_sdl *s, int n)
{
	if (s->hud1.box_picked == 3)
	{
		e->obj[n].rot_to_print.x = (e->obj[n].rot_to_print.x -
			(int)e->obj[n].rot_to_print.x % 10) / 10;
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
		(e->obj[n].rot_to_print.x == 0) ? e->obj[n].is_neg[3] = 1 : 0;
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[n].rot_to_print.y = (e->obj[n].rot_to_print.y -
			(int)e->obj[n].rot_to_print.y % 10) / 10;
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
		(e->obj[n].rot_to_print.y == 0) ? e->obj[n].is_neg[4] = 1 : 0;
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[n].rot_to_print.z = (e->obj[n].rot_to_print.z -
			(int)e->obj[n].rot_to_print.z % 10) / 10;
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
		(e->obj[n].rot_to_print.z == 0) ? e->obj[n].is_neg[5] = 1 : 0;
	}
}

void			del_char(t_env *e, t_sdl *s, int n)
{
	if (s->hud1.box_picked == 0)
	{
		e->obj[n].pos.x = (e->obj[n].pos.x - (int)e->obj[n].pos.x % 10) / 10;
		(e->obj[n].pos.x == 0) ? e->obj[n].is_neg[0] = 1 : 0;
	}
	else if (s->hud1.box_picked == 1)
	{
		e->obj[n].pos.y = (e->obj[n].pos.y - (int)e->obj[n].pos.y % 10) / 10;
		(e->obj[n].pos.y == 0) ? e->obj[n].is_neg[1] = 1 : 0;
	}
	else if (s->hud1.box_picked == 2)
	{
		e->obj[n].pos.z = (e->obj[n].pos.z - (int)e->obj[n].pos.z % 10) / 10;
		(e->obj[n].pos.z == 0) ? e->obj[n].is_neg[2] = 1 : 0;
	}
	del_char2(e, s, n);
	raytracing(e, s);
}
