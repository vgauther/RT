/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/20 14:46:44 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		cylindre_normal_at(t_inter t, t_obj obj, t_vec ori)
{
	t_vec	x;
	t_vec	dir;
	t_vec	test;
	double	m;

	x = vector_init(ori.x - obj.pos.x,
		ori.y - obj.pos.y, ori.z - obj.pos.z);
	dir = vector_init(t.pos.x - ori.x,
		t.pos.y - ori.y, t.pos.z - ori.z);
	test = vector_init(obj.rot.x * t.dist,
		obj.rot.y * t.dist, obj.rot.z * t.dist);
	test = normalize_vec(test);
	m = dot(dir, test) + dot(x, obj.rot);
	x = vector_init(obj.pos.x + obj.rot.x * m,
		obj.pos.y + obj.rot.y * m, obj.pos.z + obj.rot.z * m);
	x = normalize_vec(vector_init(t.pos.x - x.x, t.pos.y - x.y, t.pos.z - x.z));
	return (x);
}

t_inter		ray_cylindre(t_env *e, t_vec d, t_vec ori, int nbr)
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
	resolve_poly(&p, &pt, d, ori);
	return (pt);
}
