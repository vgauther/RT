/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_add_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:20:59 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 18:23:49 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	mouse_add_obj_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= SIZE_X / 4 + 180 && x <= SIZE_X / 4 + 220)
	{
		if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
		{
			s->hud1.bouton[16].i = s->hud1.bouton[16].i == 1 ? 3 : 1;
			if (s->hud1.add_obj == 1 || s->hud1.add_obj == 2)
				s->hud1.add_obj = 0;
			else
				s->hud1.add_obj = 1;
			s->hud1.bouton[14].i = 4;
			s->hud1.shape_img.i = 0;
			display(s, e);
		}
	}
}

void	set_obj_as_default(int nb, t_env *e)
{
	e->obj[nb].rot = vector_init(1, 0, 0);
	e->obj[nb].rot_to_print = e->obj[nb].rot;
	e->obj[nb].rot = normalize_vec(e->obj[nb].rot);
	e->obj[nb].pos = vector_init(0, 0, 0);
	e->obj[nb].material = 1;
	e->obj[nb].color = RED;
	e->obj[nb].rayon = 10;
	e->obj[nb].rayon_2 = 10 * 10;
	e->obj[nb].angle = 20;
	e->obj[nb].angletan = tan((e->obj[nb].angle / 2) * RAD);
	e->obj[nb].transp = 0;
	e->obj[nb].num = nb;
	e->obj[nb].reflex = 0;
	e->obj[nb].transp = 0;
}

void	mouse_check_obj(int i, t_env *e, t_sdl *s)
{
	e->obj = realloc_obj(e);
	if (i == 0)
		e->obj[e->nb - 1].type = 1;
	if (i == 0)
		s->hud1.shape_img.i = 12;
	else if (i == 2)
	{
		e->obj[e->nb - 1].type = 2;
		s->hud1.shape_img.i = 14;
	}
	else if (i == 1)
	{
		e->obj[e->nb - 1].type = 3;
		s->hud1.shape_img.i = 13;
	}
	else if (i == 3)
	{
		e->obj[e->nb - 1].type = 4;
		s->hud1.shape_img.i = 15;
	}
	s->hud1.add_obj = 2;
	set_obj_as_default(e->nb - 1, e);
	s->hud1.tok.obj_select = e->nb - 1;
	s->hud1.add_obj = 0;
	s->hud1.bouton[16].i = 1;
}

void	mouse_add_obj_select(int x, int y, t_sdl *s, t_env *e)
{
	int i;

	i = -1;
	if (x >= s->hud1.r_add_obj[0].x && x <= s->hud1.r_add_obj[1].x
		+ s->hud1.r_add_obj[1].w)
	{
		if (y >= s->hud1.r_add_obj[0].y && y <= s->hud1.r_add_obj[2].y
			+ s->hud1.r_add_obj[2].h)
		{
			while (++i != 4)
			{
				if (y >= s->hud1.r_add_obj[i].y && y <= s->hud1.r_add_obj[i].y
					+ s->hud1.r_add_obj[i].h)
				{
					if (x >= s->hud1.r_add_obj[i].x &&
						x <= s->hud1.r_add_obj[i].x + s->hud1.r_add_obj[i].w)
					{
						mouse_check_obj(i, e, s);
						init_is_neg(e);
						raytracing(e, s);
					}
				}
			}
		}
	}
}

void	mouse_add_obj(int x, int y, t_sdl *s, t_env *e)
{
	int i;

	i = -1;
	while (++i != 6)
	{
		if (y >= s->hud1.text_box[i].y &&
			y <= s->hud1.text_box[i].y + s->hud1.text_box[i].h)
		{
			if (x >= s->hud1.text_box[i].x &&
				x <= s->hud1.text_box[i].x + s->hud1.text_box[i].w)
				s->hud1.box_picked = i;
		}
	}
	display(s, e);
}
