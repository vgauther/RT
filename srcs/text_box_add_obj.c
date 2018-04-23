/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_add_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:41 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 18:37:11 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_is_neg(t_env *e)
{
	int i;

	i = -1;
	while (++i < e->nb)
	{
		e->obj[i].is_neg[0] = (e->obj[i].pos.x < 0) ? -1 : 1;
		e->obj[i].is_neg[1] = (e->obj[i].pos.y < 0) ? -1 : 1;
		e->obj[i].is_neg[2] = (e->obj[i].pos.z < 0) ? -1 : 1;
		e->obj[i].is_neg[3] = (e->obj[i].rot.x < 0) ? -1 : 1;
		e->obj[i].is_neg[4] = (e->obj[i].rot.y < 0) ? -1 : 1;
		e->obj[i].is_neg[5] = (e->obj[i].rot.z < 0) ? -1 : 1;
	}
}

void	del_char(t_env *e, t_sdl *s, int n)
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
	else if (s->hud1.box_picked == 3)
	{
		e->obj[n].rot_to_print.x = (e->obj[n].rot_to_print.x - (int)e->obj[n].rot_to_print.x % 10) / 10;
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
		(e->obj[n].rot_to_print.x == 0) ? e->obj[n].is_neg[3] = 1 : 0;
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[n].rot_to_print.y = (e->obj[n].rot_to_print.y - (int)e->obj[n].rot.y % 10) / 10;
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
		(e->obj[n].rot_to_print.y == 0) ? e->obj[n].is_neg[4] = 1 : 0;
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[n].rot_to_print.z = (e->obj[n].rot_to_print.z - (int)e->obj[n].rot_to_print.z % 10) / 10;
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
		(e->obj[n].rot_to_print.z == 0) ? e->obj[n].is_neg[5] = 1 : 0;
	}
	raytracing(e, s);
}

void	neg_gestion(t_env *e, t_sdl *s, int n)
{
	if (s->hud1.box_picked == 0)
	{
		e->obj[n].is_neg[0] = -1;
	}
	else if (s->hud1.box_picked == 1)
	{
		e->obj[n].is_neg[1] = -1;
	}
	else if (s->hud1.box_picked == 2)
	{
		e->obj[n].is_neg[2] = -1;
	}
	else if (s->hud1.box_picked == 3)
	{
		e->obj[n].is_neg[3] = -1;
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[n].is_neg[4] = -1;
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[n].is_neg[5] = -1;
	}
}

void	remplir_text_box_calcul(t_sdl *s, t_env *e, int n, t_vec p)
{
	(s->hud1.box_picked == 0) ? e->obj[n].pos.x = (fabs(e->obj[n].pos.x * p.y)
	+ p.x) * e->obj[n].is_neg[0] : 0;
	(s->hud1.box_picked == 1) ? e->obj[n].pos.y = (fabs(e->obj[n].pos.y * p.y)
	+ p.x) * e->obj[n].is_neg[1] : 0;
	(s->hud1.box_picked == 2) ? e->obj[n].pos.z = (fabs(e->obj[n].pos.z * p.y)
	+ p.x) * e->obj[n].is_neg[2] : 0;
	if (s->hud1.box_picked == 3)
	{
		e->obj[n].rot_to_print.x = (fabs(e->obj[n].rot_to_print.x * p.y) + p.x)
		* e->obj[n].is_neg[3];
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[n].rot_to_print.y = (fabs(e->obj[n].rot_to_print.y * p.y) + p.x)
		* e->obj[n].is_neg[4];
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[n].rot_to_print.z = (fabs(e->obj[n].rot_to_print.z * p.y) + p.x)
		* e->obj[n].is_neg[5];
		e->obj[n].rot = normalize_vec(e->obj[n].rot_to_print);
	}
}

void	remplir_text_box(int key, t_env *e, t_sdl *s, int n)
{
	t_vec p;

	p.y = 10;
	if (key == 42)
	{
		del_char(e, s, n);
		return ;
	}
	if ((p.x = nbr_touch(key)) == 42)
		return ;
	if (p.x == -1)
	{
		neg_gestion(e, s, n);
		p.x = 0;
		p.y = 1;
	}
	remplir_text_box_calcul(s, e, n, p);
	raytracing(e, s);
}
