/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 17:03:29 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		ray_cylindre(t_env *e, int i, int j, t_cam ca, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		v;

	v = vector_init((i - SIZE_X / 2) - ca.xr, (j - SIZE_Y / 2) - ca.yr,
	(SIZE_X / 2) / tan(30 * RAD) - ca.zr);
	p.a = v.x * v.x + v.z * v.z;
	p.b = 2 * (v.x * (ca.xr - e->obj[nbr].pos.x) +
	v.z * (ca.zr - e->obj[nbr].pos.z));
	p.c = (ca.xr - e->obj[nbr].pos.x) * (ca.xr - e->obj[nbr].pos.x) +
	(ca.zr - e->obj[nbr].pos.z) * (ca.zr - e->obj[nbr].pos.z) -
	e->obj[nbr].rayon * e->obj[nbr].rayon;
	p.delta = powf(p.b, 2) - 4 * p.a * p.c;
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
			intersection_point(&pt, ca, v);
	}
	else
		pt.dist = -1;
	return (pt);
}
