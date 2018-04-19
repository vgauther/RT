/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:04:09 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/18 12:55:18 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		sphere_normal_at(t_inter t, t_obj obj)
{
	return (normalize_vec(vector_init(t.pos.x - obj.pos.x,
		t.pos.y - obj.pos.y,
		t.pos.z - obj.pos.z)));
}

void		resolve_poly(t_polynome *p, t_inter *t, t_vec v, t_vec ori)
{
	if (p->delta >= 0)
	{
		if (p->delta > 0)
		{
			p->x1 = (-p->b + sqrt(p->delta)) / (2 * p->a);
			p->x2 = (-p->b - sqrt(p->delta)) / (2 * p->a);
			t->dist = p->x1 < p->x2 ? p->x1 : p->x2;
			if (t->dist < 0)
				t->dist = p->x1 < 0 ? p->x2 : p->x1;
		}
		else
			p->x1 = -p->b / (2 * p->a);
		if (!(p->x1 < 0 && p->x2 < 0))
			intersection_point(t, ori, v);
	}
	else
		t->dist = MAX_DIST;
	t->delta = p->delta;
}

t_inter		ray_sphere(t_env *e, t_vec v, t_vec ori, int nbr)
{
	t_polynome	p;
	t_inter		t;
	t_vec		f;

	f = vector_init(ori.x - e->obj[nbr].pos.x, ori.y - e->obj[nbr].pos.y,
		ori.z - e->obj[nbr].pos.z);
	p.a = v.x * v.x + v.y * v.y + v.z * v.z;
	p.b = 2 * (v.x * f.x + v.y * f.y + v.z * f.z);
	p.c = pow(f.x, 2) + pow(f.y, 2) + pow(f.z, 2) - e->obj[nbr].rayon_2;
	p.delta = p.b * p.b - 4 * p.a * p.c;
	resolve_poly(&p, &t, v, ori);
	return (t);
}
