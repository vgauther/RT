/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/06 17:55:56 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_vec	cone_normal_at(t_inter t, t_obj obj, t_vec d , t_vec rot)
{
	t_vec	norm;
	t_vec	vec;
	double	rad;
	double	a;
	double	b;
	double	m;


	vec = vector_init(t.pos.x - obj.pos.x, t.pos.y - obj.pos.y, t.pos.z - obj.pos.z);
	rad = 1 + obj.angle * obj.angle;
	a = dot(vec, rot);
	b = dot(d, rot);
	m = b * t.dist + a;
	norm = vector_init(vec.x - (rot.x * (rad * m)), vec.y - (rot.y * (rad * m)), vec.z - (rot.z * (rad * m)));
	norm = normalize_vec(norm);
	return (norm);
}

t_inter		ray_cone(t_env *e, t_vec d, t_point ori, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		v;
	t_vec		x;

	x = vector_init(ori.x - e->obj[nbr].pos.x, ori.y - e->obj[nbr].pos.y,
		ori.z - e->obj[nbr].pos.z);
	v = normalize_vec(e->obj[nbr].rot);
	p.a = dot(d, d) - ((e->obj[nbr].angle * e->obj[nbr].angle + 1) *
	dot(d, v) * dot(d, v));
	p.b = 2 * (dot(d, x) - ((e->obj[nbr].angle * e->obj[nbr].angle + 1) *
	dot(d, v) * dot(v, x)));
	p.c = dot(x, x) - ((e->obj[nbr].angle * e->obj[nbr].angle + 1) *
	dot(x, v) * dot(x, v));
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
	pt.normal = cone_normal_at(pt, e->obj[nbr], d, v);
	return (pt);
}
