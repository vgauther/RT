/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:20:09 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/30 19:16:18 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			print_data_obj(t_sdl *s, t_env *e, int nbr)
{
	if (e->obj[nbr].type == 1)
		s->hud1.shape_img.i = 12;
	if (e->obj[nbr].type == 2)
		s->hud1.shape_img.i = 14;
	if (e->obj[nbr].type == 3)
		s->hud1.shape_img.i = 13;
	if (e->obj[nbr].type == 4)
		s->hud1.shape_img.i = 15;
	if (e->obj[nbr].type == 5)
		s->hud1.shape_img.i = 12;
	display(s, e);
}

static t_inter	mouse_save_tmp(t_inter tmp, int nbr, t_sdl *s)
{
	t_inter pt;

	pt.dist = tmp.dist;
	pt.pos = init_point(tmp.pos.x, tmp.pos.y, tmp.pos.z);
	pt.normal = tmp.normal;
	pt.nb = nbr;
	s->hud1.tok.obj_select = nbr;
	return (pt);
}

void			mouse_obj_seletor(int x, int y, t_sdl *s, t_env *e)
{
	int			nbr;
	t_inter		pt;
	t_inter		tmp;
	t_vec		dir;

	if (x > SIZE_X / 4 && x < SIZE_X / 4 + SIZE_X && (x -= SIZE_X / 4) >= 0)
	{
		if (y > LINE && y < LINE + SIZE_Y && (y -= LINE) >= 0)
		{
			nbr = -1;
			pt.dist = MAX_DIST;
			while (++nbr < e->nb)
			{
				dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
				dir = ft_rotate(dir, e->ca.rot.x, e->ca.rot.y, e->ca.rot.z);
				dir = normalize_vec(dir);
				tmp = shape_redirection(e, dir, e->ca.pos, nbr);
				if (tmp.dist < pt.dist && tmp.dist > 0)
					pt = mouse_save_tmp(tmp, nbr, s);
			}
			if (pt.dist != MAX_DIST && s->hud1.selectobj)
				print_data_obj(s, e, pt.nb);
		}
	}
}

void			mouse_selector_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= SIZE_X / 4 + 60 && x <= SIZE_X / 4 + 100)
	{
		if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
		{
			s->hud1.bouton[14].i = s->hud1.bouton[14].i == 5 ? 4 : 5;
			display(s, e);
			s->hud1.selectobj = s->hud1.selectobj == 1 ? 0 : 1;
		}
	}
}
