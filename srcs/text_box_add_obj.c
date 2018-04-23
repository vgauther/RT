/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_add_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:41 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 14:59:13 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	del_char(t_env *e, t_sdl *s)
{
	if (s->hud1.box_picked == 0)
	{
		e->obj[e->nb - 1].pos.x = (e->obj[e->nb - 1].pos.x - (int)e->obj[e->nb - 1].pos.x % 10) / 10;
	}
	else if (s->hud1.box_picked == 1)
	{
		e->obj[e->nb - 1].pos.y = (e->obj[e->nb - 1].pos.y - (int)e->obj[e->nb - 1].pos.y % 10) / 10;
	}
	else if (s->hud1.box_picked == 2)
	{
		e->obj[e->nb - 1].pos.z = (e->obj[e->nb - 1].pos.z - (int)e->obj[e->nb - 1].pos.z % 10) / 10;
	}
	else if (s->hud1.box_picked == 3)
	{
		e->obj[e->nb - 1].rot_to_print.x = (e->obj[e->nb - 1].rot_to_print.x - (int)e->obj[e->nb - 1].rot_to_print.x % 10) / 10;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot_to_print);
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[e->nb - 1].rot_to_print.y = (e->obj[e->nb - 1].rot_to_print.y - (int)e->obj[e->nb - 1].rot.y % 10) / 10;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot_to_print);
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[e->nb - 1].rot_to_print.z = (e->obj[e->nb - 1].rot_to_print.z - (int)e->obj[e->nb - 1].rot_to_print.z % 10) / 10;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot_to_print);
 	}
	raytracing(e, s);
}

void	remplir_text_box(int key, t_env *e, t_sdl *s)
{
	int x;
	int y;

	y = 1;
	x = nbr_touch(key);
	if (key == 42)
	{
		del_char(e, s);
		return ;
	}
	if (x == -1)
	{
		x = 0;
		y = -1;
	}
	if (x == 42)
		return ;
	if (s->hud1.box_picked == 0)
	{
		e->obj[e->nb - 1].pos.x = (e->obj[e->nb - 1].pos.x * 10 + x) * y;
	}
	else if (s->hud1.box_picked == 1)
	{
		e->obj[e->nb - 1].pos.y = (e->obj[e->nb - 1].pos.y * 10 + x) * y;
	}
	else if (s->hud1.box_picked == 2)
	{
		e->obj[e->nb - 1].pos.z = (e->obj[e->nb - 1].pos.z * 10 + x) * y;
	}
	else if (s->hud1.box_picked == 3)
	{
		e->obj[e->nb - 1].rot_to_print.x = (e->obj[e->nb - 1].rot_to_print.x * 10 + x) * y;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot_to_print);
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[e->nb - 1].rot_to_print.y = (e->obj[e->nb - 1].rot_to_print.y * 10 + x) * y;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot_to_print);
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[e->nb - 1].rot_to_print.z = (e->obj[e->nb - 1].rot_to_print.z * 10 + x) * y;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot_to_print);
	}
	raytracing(e, s);
}
