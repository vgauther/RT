/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vector_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:44:39 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/30 19:34:49 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		get_normal(t_env *e, t_inter pt, t_vec ori)
{
	t_vec norm;

	if (e->obj[pt.nb].type == 1)
		norm = sphere_normal_at(pt, e->obj[pt.nb]);
	else if (e->obj[pt.nb].type == 2)
		norm = cylindre_normal_at(pt, e->obj[pt.nb], ori);
	else if (e->obj[pt.nb].type == 4)
		norm = plan_normal_at(pt, e->obj[pt.nb], ori);
	else if (e->obj[pt.nb].type == 5)
		norm = disque_normal_at(pt, e->obj[pt.nb], ori);
	else
		norm = cone_normal_at(pt, e->obj[pt.nb], ori);
	return (norm);
}

/*
** addition of two vecteur (V1 + V2)
*/

t_vec		add_vec(t_vec v1, t_vec v2)
{
	return (vector_init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec		calc_dir_vec(int x, int y, t_env *e)
{
	t_vec dir;

	dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
	dir = ft_rotate(dir, e->ca.rot.x, e->ca.rot.y, e->ca.rot.z);
	dir = normalize_vec(dir);
	return (dir);
}

/*
** cross product of vector
*/

t_vec		vec3_cross(t_vec va, t_vec vb)
{
	t_vec	v;

	v.x = va.y * vb.z - va.z * vb.y;
	v.y = va.z * vb.x - va.x * vb.z;
	v.z = va.x * vb.y - va.y * vb.x;
	return (v);
}

/*
** multiplication of each postion of the vector
*/

t_vec		v_scale(double c, t_vec *v)
{
	return (vector_init(v->x * c, v->y * c, v->z * c));
}
