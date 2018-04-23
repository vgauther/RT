/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_add_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:41 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 19:30:58 by vgauther         ###   ########.fr       */
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
