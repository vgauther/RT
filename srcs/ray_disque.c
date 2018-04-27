/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_disque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:55:12 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/27 17:05:25 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec	disque_normal_at(t_inter t, t_obj obj, t_vec ori)
{
	t_vec	v;
	double	d;

	v = normalize_vec(vector_init(t.pos.x - ori.x,
		t.pos.y - ori.y, t.pos.z - ori.z));
	d = dot(v, obj.rot);
	if (d < 0.01)
		v = obj.rot;
	else
		v = v_scale(-1, &obj.rot);
	return (v);
}

t_inter	ray_disque(t_env *e, t_vec v, t_vec ori, int nbr)
{
	double	tn;
	double	dv;
	t_vec	dist;
	t_inter t;

	dv = dot(e->obj[nbr].rot, v);
	dist = sub_vec(ori, e->obj[nbr].pos);
	tn = ((-(dot(e->obj[nbr].rot, dist))) / dv);
	t.dist = tn;
	intersection_point(&t, ori, v);
	if ((sqrt(powf((e->obj[nbr].pos.x - t.pos.x), 2) +
			powf((e->obj[nbr].pos.y - t.pos.y), 2) +
				powf((e->obj[nbr].pos.z - t.pos.z), 2))) > e->obj[nbr].rayon)
		t.dist = MAX_DIST;
	return (t);
}
