/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 12:02:33 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		cone_normal_at(t_inter t, t_obj obj)
{
	t_vec	v;
	t_vec	norm;
	double	m;

	v = vector_init(t.pos.x - obj.pos.x, t.pos.y -
		obj.pos.y, t.pos.z - obj.pos.z);
	m = sqrt(dot(v,v)) / cos(obj.angle * RAD);
	norm = vector_init(v.x - obj.rot.x * m, v.y -
		 obj.rot.y * m, v.z - obj.rot.z * m);
	return (normalize_vec(norm));
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
	pt.normal = cone_normal_at(pt, e->obj[nbr]);
	return (pt);
}
