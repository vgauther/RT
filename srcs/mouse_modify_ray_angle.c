/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_modify_ray_angle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:46:03 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 13:47:19 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		mouse_rayon_modify(int i, t_sdl *s, t_env *e)
{
	if (e->obj[s->hud1.tok.obj_select].type == 1 ||
		e->obj[s->hud1.tok.obj_select].type == 2)
	{
		if (i == 0)
			e->obj[s->hud1.tok.obj_select].rayon++;
		else
			e->obj[s->hud1.tok.obj_select].rayon--;
		(e->obj[s->hud1.tok.obj_select].rayon < 0) ?
		e->obj[s->hud1.tok.obj_select].rayon = 0 : 0;
		e->obj[s->hud1.tok.obj_select].rayon_2 =
	e->obj[s->hud1.tok.obj_select].rayon * e->obj[s->hud1.tok.obj_select].rayon;
	}
}

static void		mouse_angle_modify(int i, t_sdl *s, t_env *e)
{
	if (e->obj[s->hud1.tok.obj_select].type == 3)
	{
		if (i == 0)
			e->obj[s->hud1.tok.obj_select].angle++;
		else
			e->obj[s->hud1.tok.obj_select].angle--;
		(e->obj[s->hud1.tok.obj_select].angle < 0) ?
		e->obj[s->hud1.tok.obj_select].angle = 0 : 0;
		e->obj[s->hud1.tok.obj_select].angletan =
		tan((e->obj[s->hud1.tok.obj_select].angle / 2) * RAD);
	}
}

static void		plus(t_sdl *s, t_env *e)
{
	s->hud1.plmor[1].i = P2;
	display(s, e);
	s->hud1.plmor[1].i = P1;
	mouse_rayon_modify(0, s, e);
	mouse_angle_modify(0, s, e);
	raytracing(e, s);
}

static void		meno(t_sdl *s, t_env *e)
{
	s->hud1.plmor[2].i = M2;
	display(s, e);
	s->hud1.plmor[2].i = M1;
	mouse_rayon_modify(1, s, e);
	mouse_angle_modify(1, s, e);
	raytracing(e, s);
}

void			mouse_modify_ray_angle(int x, int y, t_sdl *s, t_env *e)
{
	if (e->obj[s->hud1.tok.obj_select].type >= 1 ||
		e->obj[s->hud1.tok.obj_select].type <= 3)
	{
		if (x >= s->hud1.plmor[1].rect.x &&
			x <= s->hud1.plmor[1].rect.x + s->hud1.plmor[1].rect.w)
		{
			if (y >= s->hud1.plmor[1].rect.y &&
				y <= s->hud1.plmor[1].rect.y + s->hud1.plmor[1].rect.h)
				plus(s, e);
		}
		if (x >= s->hud1.plmor[2].rect.x &&
			x <= s->hud1.plmor[2].rect.x + s->hud1.plmor[2].rect.w)
		{
			if (y >= s->hud1.plmor[2].rect.y &&
				y <= s->hud1.plmor[2].rect.y + s->hud1.plmor[2].rect.h)
				meno(s, e);
		}
	}
}
