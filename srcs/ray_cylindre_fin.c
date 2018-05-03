/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylindre_fin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:58:09 by fde-souz          #+#    #+#             */
/*   Updated: 2018/05/03 15:41:33 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		resolve_poly_fin(t_polynome *p, t_inter *t, t_vec v, t_vec ori)
{
	if (p->delta >= 0)
	{
		if (p->delta > 0)
		{
			p->x1 = (-p->b + sqrt(p->delta)) / (2 * p->a);
			p->x2 = (-p->b - sqrt(p->delta)) / (2 * p->a);
			t->dist = p->x1 > p->x2 ? p->x1 : p->x2;
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

static double	calc_hyp(t_inter *pt, t_obj obj)
{
	double	hyp;

	hyp = sqrt(powf(obj.pos.x - pt->pos.x, 2) +
	powf(obj.pos.y - pt->pos.y, 2) +
	powf(obj.pos.z - pt->pos.z, 2));
	hyp = sqrtf(powf(hyp, 2) - powf(obj.rayon, 2));
	return (hyp);
}

t_inter			ray_cylindre_fin(t_env *e, t_vec d, t_vec ori, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		x;
	double		hyp;

	x = vector_init(ori.x - e->obj[nbr].pos.x, ori.y - e->obj[nbr].pos.y,
		ori.z - e->obj[nbr].pos.z);
	p.a = dot(d, d) - dot_2(d, e->obj[nbr].rot);
	p.b = 2 * (dot(d, x) - dot(d, e->obj[nbr].rot) * dot(x, e->obj[nbr].rot));
	p.c = dot(x, x) - dot_2(x, e->obj[nbr].rot) - e->obj[nbr].rayon_2;
	p.delta = (p.b * p.b) - (4 * p.a * p.c);
	resolve_poly(&p, &pt, d, ori);
	if (pt.dist != MAX_DIST)
	{
		hyp = calc_hyp(&pt, e->obj[nbr]);
		if (hyp > e->obj[nbr].taille / 2)
		{
			resolve_poly_fin(&p, &pt, d, ori);
			hyp = calc_hyp(&pt, e->obj[nbr]);
			if (hyp > e->obj[nbr].taille / 2)
				pt.dist = MAX_DIST;
		}
	}
	return (pt);
}
