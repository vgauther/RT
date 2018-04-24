/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_key_interaction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:05:48 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/24 12:04:55 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	cam_mouv2(long key, t_env *e, t_sdl *s)
{
	if (key == CAM_DOWN)
	{
		print_info(s, e, 2);
		e->ca.pos.y += s->hud1.how_much;
	}
	if (key == CAM_FOR)
	{
		print_info(s, e, 3);
		e->ca.pos.z += s->hud1.how_much;
	}
	if (key == CAM_BACK)
	{
		print_info(s, e, 3);
		e->ca.pos.z -= s->hud1.how_much;
	}
}

void	cam_mouv1(long key, t_env *e, t_sdl *s)
{
	if (key == CAM_LEFT)
	{
		print_info(s, e, 1);
		e->ca.pos.x -= s->hud1.how_much;
	}
	if (key == CAM_RIGHT)
	{
		print_info(s, e, 1);
		e->ca.pos.x += s->hud1.how_much;
	}
	if (key == CAM_UP)
	{
		print_info(s, e, 2);
		e->ca.pos.y -= s->hud1.how_much;
	}
}

void	mouv(long key, t_env *e, t_sdl *s)
{
	if (s->hud1.box_picked != 42 || s->hud1.tok.obj_select != -1)
		remplir_text_box(key, e, s, s->hud1.tok.obj_select);
	else
	{
		cam_mouv1(key, e, s);
		cam_mouv2(key, e, s);
		if (do_we_need_to_rt(key))
			raytracing(e, s);
	}
}
