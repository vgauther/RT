/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 16:57:09 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		cylindre_normal_at(t_inter t, t_obj obj)
{
	return (normalize_vec(vector_init(t.pos.x - obj.pos.x,
		t.pos.y - obj.pos.y,
		t.pos.z - obj.pos.z)));
}


t_inter		ray_cylindre(t_env *e, t_vec d, t_point ori, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		x;

	x = vector_init(ori.x - e->obj[nbr].pos.x, ori.y - e->obj[nbr].pos.y,
		ori.z - e->obj[nbr].pos.z);
	p.a = dot(d, d) - dot_2(d, e->obj[nbr].rot);
	p.b = 2 * (dot(d, x) - dot(d, e->obj[nbr].rot) * dot(x, e->obj[nbr].rot));
	p.c = dot(x, x) - dot_2(x, e->obj[nbr].rot) - e->obj[nbr].rayon_2;
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
		{
			p.x1 = -p.b / (2 * p.a);
			p.x2 = p.x1;
			pt.dist = p.x1;
		}
		if (!(p.x1 < 0 && p.x2 < 0))
			intersection_point(&pt, ori, d);
	}
	else
		pt.dist = MAX_DIST;
	pt.normal = cylindre_normal_at(pt, e->obj[nbr]);
	return (pt);
}
