/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:04:09 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 22:40:03 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		ray_sphere(t_env *e, int i, int j, t_cam ca, int nbr)
{
	t_polynome	p;
	t_inter		t;
	t_vec 		v;
	t_vec			f;

	f = vector_init(ca.xr - e->obj[nbr].pos.x, ca.yr - e->obj[nbr].pos.y, ca.zr - e->obj[nbr].pos.z);
	v = vector_init((i - SIZE_X / 2), (j - SIZE_Y / 2),
	(SIZE_X / 2) / tan(30 * RAD));
	p.a = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
	p.b = 2 * (v.x * (f.x) + v.y * (f.y) + v.z * (f.z));
	p.c = (pow(f.x, 2) + pow(f.y, 2) + pow(f.z, 2) - pow((e->obj[nbr].rayon), 2));
	p.delta = pow(p.b, 2) - 4 * p.a * p.c;
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
		{
			t.x = ca.xr + v.x * t.dist;
			t.y = ca.yr + v.y * t.dist;
			t.z = ca.zr + v.z * t.dist;
		}
	}
	else
		t.dist = -1;
	return (t);
}
