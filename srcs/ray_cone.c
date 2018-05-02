/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 14:31:31 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		cone_normal_at(t_inter t, t_obj obj, t_vec ori)
{
	t_vec	x;
	t_vec	dir;
	t_vec	test;
	double	m;

	x = sub_vec(ori, obj.pos);
	dir = normalize_vec(sub_vec(t.pos, ori));
	m = dot(dir, obj.rot) * t.dist + dot(x, obj.rot);
	t.normal = v_scale(t.dist, &dir);
	t.normal = add_vec(t.normal, x);
	test = v_scale(m * (1 + obj.angletan), &obj.rot);
	t.normal = normalize_vec(sub_vec(t.normal, test));
	return (t.normal);
}

t_inter		ray_cone(t_env *e, t_vec d, t_vec ori, int nbr)
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
	resolve_poly(&p, &pt, d, ori);
	return (pt);
}
