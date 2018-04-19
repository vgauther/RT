/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:31:27 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/19 12:20:47 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

// t_vec	v_scale(double c, t_vec *v)
// {
// 	return (vector_init(v->x * c, v->y * c, v->z * c));
// }

// // t_vec	plan_normal_at(t_inter pt, t_env *e)
// // {
// // 	t_vec v;

// // 	if (pt.nb < 0)
// // 		v = e->obj[pt.nb].norm;
// // 	else 
// // 		v = v_scale(-1, &e->obj[pt.nb].norm);
// // 	return (v);
// // }

t_inter	ray_plan(t_env *e, t_vec v, t_vec ori, int nbr)
{
	double	tn;
	double  dv;
	t_vec	dist;
	t_inter t;

	dv = dot(e->obj[nbr].norm, v);
	dist = sub_vec(ori, e->obj[nbr].pos);
	tn = ((-(dot(e->obj[nbr].norm, dist))) / dv);
	t.dist = tn;
	t.pos = dist;
	t.nb = dv;
	return (t);
}
