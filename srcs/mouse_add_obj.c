/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_add_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:20:59 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 11:36:36 by vgauther         ###   ########.fr       */
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

void	mouse_add_obj_select(int x, int y, t_sdl *s, t_env *e)
{
	int i;

	i = 0;
	if (x >= s->hud1.r_add_obj[0].x && x <=  s->hud1.r_add_obj[1].x + s->hud1.r_add_obj[1].w)
	{
		if(y >= s->hud1.r_add_obj[0].y && y <= s->hud1.r_add_obj[2].y + s->hud1.r_add_obj[2].h)
		{
			while (i != 4)
			{
				if (y >= s->hud1.r_add_obj[i].y && y <= s->hud1.r_add_obj[i].y + s->hud1.r_add_obj[i].h)
				{
					if (x >= s->hud1.r_add_obj[i].x && x <= s->hud1.r_add_obj[i].x + s->hud1.r_add_obj[i].w)
					{
						e->obj = realloc_obj(e);
						if (i == 0)
						{
							e->obj[e->nb - 1].type = 1;
							s->hud1.shape_img.i = 12;
						}
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
						e->obj[e->nb - 1].rot = vector_init(1, 0, 0);
						e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot);
						e->obj[e->nb - 1].pos = vector_init(0, 0, 0);
						e->obj[e->nb - 1].material = 1;
						e->obj[e->nb - 1].color = RED;
						e->obj[e->nb - 1].rayon = 10;
						e->obj[e->nb - 1].rayon_2 = 10 * 10;
						e->obj[e->nb - 1].angle = 20;
						e->obj[e->nb - 1].angletan = tan((e->obj[e->nb - 1].angle / 2) * RAD);
						e->obj[e->nb - 1].num = e->nb - 1;
					}
				}
				i++;
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
		if (y >= s->hud1.text_box[i].y && y <= s->hud1.text_box[i].y + s->hud1.text_box[i].h)
		{
			if (x >= s->hud1.text_box[i].x && x <= s->hud1.text_box[i].x + s->hud1.text_box[i].w)
				s->hud1.box_picked = i;
		}
	}
	if (y >= s->hud1.ok.rect.y && y <= s->hud1.ok.rect.y + s->hud1.ok.rect.h)
	{
		if (x >= s->hud1.ok.rect.x && x <= s->hud1.ok.rect.x + s->hud1.ok.rect.w)
		{
			s->hud1.ok.i = 18;
			display(s, e);
			s->hud1.add_obj = 0;
			s->hud1.ok.i = 17;
			s->hud1.bouton[16].i = 1;
			s->hud1.box_picked = 42;
		}
	}
	raytracing(e, s);
}
