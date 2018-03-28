/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/28 14:46:26 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		ray_cone(t_env *e, int i, int j, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		d;
	t_vec		v;
	t_vec		x;

	d = vector_init(i - SIZE_X_2, j - SIZE_Y_2, SIZE_X_2 / TAN30);
	x = vector_init(e->ca.x - e->obj[nbr].pos.x, e->ca.y - e->obj[nbr].pos.y,
		e->ca.z - e->obj[nbr].pos.z);
	v = normalize_vec(e->obj[nbr].rot);
	p.a = dot(d, d) - ((e->obj[nbr].angle * e->obj[nbr].angle + 1) * dot(d, v) * dot(d, v));
	p.b = 2 * (dot(d, x) - ((e->obj[nbr].angle * e->obj[nbr].angle + 1) * dot(d, v) * dot(v, x)));
	p.c = dot(x, x) - ((e->obj[nbr].angle * e->obj[nbr].angle + 1) * dot(x, v) * dot(x, v));
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
			intersection_point(&pt, e->ca, d);
	}
	else
		pt.dist = -1;
	return (pt);
}
