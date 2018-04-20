/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:31:27 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/20 14:45:59 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec	v_scale(double c, t_vec *v)
{
	return (vector_init(v->x * c, v->y * c, v->z * c));
}

t_vec	plan_normal_at(t_inter t, t_obj obj, t_vec ori)
{
	t_vec	v;
	double	d;

	v = normalize_vec(vector_init(t.pos.x - ori.x,
		t.pos.y - ori.y, t.pos.z - ori.z));
	d = dot(v, obj.norm);
	if (d < 0.01)
		v = obj.norm;
	else
		v = v_scale(-1, &obj.norm);
	return (v);
}

t_inter	ray_plan(t_env *e, t_vec v, t_vec ori, int nbr)
{
	double	tn;
	double	dv;
	t_vec	dist;
	t_inter t;

	dv = dot(e->obj[nbr].norm, v);
	dist = sub_vec(ori, e->obj[nbr].pos);
	tn = ((-(dot(e->obj[nbr].norm, dist))) / dv);
	t.dist = tn;
	intersection_point(&t, ori, v);
	t.nb = dv;
	return (t);
}
