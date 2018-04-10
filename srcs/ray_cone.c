/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 18:23:06 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

// t_vec		cone_normal_at(t_inter t, t_obj obj, t_obj spot)
// {
// 	t_vec	v;
// 	t_vec	dir;
// 	double	dop;
// 	double	rdopd;
// 	t_vec	norm;
// 	double	m2;
// 	double	rad;
//
// 	dir = vector_init(t.pos.x - spot.pos.x, t.pos.y - spot.pos.y, t.pos.z - spot.pos.z);
// 	rad = 1 + ((obj.angle) * (obj.angle));
// 	v = vector_init(obj.pos.x - t.pos.x, obj.pos.y - t.pos.y , obj.pos.z - t.pos.z);
// 	dop = dot(v, obj.rot);
// 	rdopd = dot(obj.rot, dir);
// 	m2 = rdopd * sqrtf(t.dist) + dop;
// 	norm = vector_init(v.x - (obj.rot.x * (rad * m2)), v.y - (obj.rot.y * (rad * m2)) , v.z - (obj.rot.z * (rad * m2)));
// 	return (normalize_vec(norm));
// }

t_vec		cone_normal_at(t_inter t, t_obj obj, t_obj spot)
{
	t_vec	v;
	t_vec	norm;
	double	m;
	double rad;

	(void)spot;
	rad = 1 + ((RAD * obj.angle) * (obj.angle * RAD));
	v = vector_init(t.pos.x - obj.pos.x, t.pos.y - obj.pos.y, t.pos.z - obj.pos.z);
	m = sqrt(dot(v, v)) / cos(obj.angle * RAD);
	norm = vector_init(v.x - obj.rot.x * m * rad , v.y - obj.rot.y * m * rad, v.z - obj.rot.z * m * rad);
	norm = normalize_vec(norm);
	return(norm);
}

t_inter		ray_cone(t_env *e, t_vec d, t_point ori, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		x;

	x = vector_init(ori.x - e->obj[nbr].pos.x, ori.y - e->obj[nbr].pos.y,
		ori.z - e->obj[nbr].pos.z);
	p.a = dot(d, d) - ((e->obj[nbr].angletan * e->obj[nbr].angletan + 1) *
	dot(d, e->obj[nbr].rot) * dot(d, e->obj[nbr].rot));
	p.b = 2 * (dot(d, x) - ((e->obj[nbr].angletan * e->obj[nbr].angletan + 1) *
	dot(d, e->obj[nbr].rot) * dot(e->obj[nbr].rot, x)));
	p.c = dot(x, x) - ((e->obj[nbr].angletan * e->obj[nbr].angletan + 1) *
	dot(x, e->obj[nbr].rot) * dot(x, e->obj[nbr].rot));
	p.delta = (p.b * p.b) - (4 * p.a * p.c);
	if (p.delta >= 0)
	{
		if (p.delta > 0)
		{
			p.x1 = (-p.b + sqrt(p.delta)) / (2 * p.a);
			p.x2 = (-p.b - sqrt(p.delta)) / (2 * p.a);
			pt.dist = p.x1 < p.x2 ? p.x1 : p.x2;
			if (pt.dist < 0)
				pt.dist = p.x1 < 0 ? p.x2 : p.x1;
		}
		else
			p.x1 = -p.b / (2 * p.a);
		if (!(p.x1 < 0 && p.x2 < 0))
			intersection_point(&pt, ori, d);
	}
	else
		pt.dist = MAX_DIST;
	pt.delta = p.delta;
	return (pt);
}
