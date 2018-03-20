/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:04:09 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 17:04:54 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		ray_sphere(t_env *e, int i, int j, t_cam ca, int nbr)
{
	t_polynome	p;
	t_inter		t;
	double		vx;
	double		vy;
	double		vz;
	double		f1;
	double		f2;
	double		f3;

	f1 = ca.xr - e->obj[nbr].pos.x;
	f2 = ca.yr - e->obj[nbr].pos.y;
	f3 = ca.zr - e->obj[nbr].pos.z;
	vx = (i - SIZE_X / 2);
	vy = (j - SIZE_Y / 2);
	vz = (SIZE_X / 2) / tan(30 * RAD);
	p.a = pow(vx, 2) + pow(vy, 2) + pow(vz, 2);
	p.b = 2 * (vx * (f1) + vy * (f2) + vz * (f3));
	p.c = (pow(f1, 2) + pow(f2, 2) + pow(f3, 2) - pow((e->obj[nbr].rayon), 2));
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
			t.x = ca.xr + vx * t.dist;
			t.y = ca.yr + vy * t.dist;
			t.z = ca.zr + vz * t.dist;
		}
	}
	else
		t.dist = -1;
	return (t);
}
