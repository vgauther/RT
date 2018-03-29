/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:04:09 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/29 15:07:39 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		ray_sphere(t_env *e, int i, int j, int nbr)
{
	t_polynome	p;
	t_inter		t;
	t_vec		v;
	t_vec		f;

	f = vector_init(e->ca.pos.x - e->obj[nbr].pos.x, e->ca.pos.y - e->obj[nbr].pos.y,
		e->ca.pos.z - e->obj[nbr].pos.z);
	v = vector_init(i - SIZE_X_2, j - SIZE_Y_2, SIZE_X_2 / TAN30);
	p.a = v.x * v.x + v.y * v.y + v.z * v.z;
	p.b = 2 * (v.x * f.x + v.y * f.y + v.z * f.z);
	p.c = pow(f.x, 2) + pow(f.y, 2) + pow(f.z, 2) - e->obj[nbr].rayon_2;
	p.delta = p.b * p.b - 4 * p.a * p.c;
	if (p.delta >= 0)
	{
		if (p.delta > 0)
		{
			p.x1 = (-p.b + sqrt(p.delta)) / (2 * p.a);
			p.x2 = (-p.b - sqrt(p.delta)) / (2 * p.a);
			t.dist = p.x1 < p.x2 ? p.x1 : p.x2;
			if (t.dist < 0)
				t.dist = p.x1 < 0 ? p.x2 : p.x1;
		}
		else
			p.x1 = -p.b / (2 * p.a);
		if (!(p.x1 < 0 && p.x2 < 0))
			intersection_point(&t, e->ca, v);
	}
	else
		t.dist = -1;
	return (t);
}
