/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/29 15:08:12 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		ray_cylindre(t_env *e, int i, int j, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		d;
	t_vec		v;
	t_vec		x;

	d = vector_init(i - SIZE_X_2, j - SIZE_Y_2, SIZE_X_2 / TAN30);
	x = vector_init(e->ca.pos.x - e->obj[nbr].pos.x, e->ca.pos.y - e->obj[nbr].pos.y,
		e->ca.pos.z - e->obj[nbr].pos.z);
	v = normalize_vec(e->obj[nbr].rot);
	p.a = dot(d, d) - dot_2(d, v);
	p.b = 2 * (dot(d, x) - dot(d, v) * dot(x, v));
	p.c = dot(x, x) - dot_2(x, v) - e->obj[nbr].rayon_2;
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
