/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:04:09 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 13:40:32 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_vec	sphere_normal_at(t_inter t, t_obj obj)
{
	return (normalize_vec(vector_init(t.pos.x - obj.pos.x,
		t.pos.y - obj.pos.y,
		t.pos.z - obj.pos.z)));
}

t_inter			ray_sphere(t_env *e, t_vec v, t_point ori, int nbr)
{
	t_polynome	p;
	t_inter		t;
	t_vec		f;

	f = vector_init(ori.x - e->obj[nbr].pos.x, ori.y - e->obj[nbr].pos.y,
		ori.z - e->obj[nbr].pos.z);
	//printf("%f\n", ori.z);
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
			intersection_point(&t, ori, v);
	}
	else
		t.dist = MAX_DIST;
	t.delta = p.delta;
	t.normal = sphere_normal_at(t, e->obj[nbr]);
	return (t);
}
