/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:53:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/27 14:33:18 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	x(double *y, double *z, double rot_x)
{
	*y = cos(rot_x * RAD) * *y - sin(rot_x * RAD) * *z;
	*z = sin(rot_x * RAD) * *y + cos(rot_x * RAD) * *z;
}

void	y(double *x, double *z, double rot_y)
{
	*x = cos(rot_y * RAD) * *x + sin(rot_y * RAD) * *z;
	*z = -sin(rot_y * RAD) * *x + cos(rot_y * RAD) * *z;
}

void	z(double *x, double *y, double rot_z)
{
	*x = cos(rot_z * RAD) * *x - sin(rot_z * RAD) * *y;
	*y = sin(rot_z * RAD) * *x + cos(rot_z * RAD) * *y;
}

t_vec			ft_rotate(t_vec p, double rot_x, double rot_y, double rot_z)
{
	int					x;
	int					y;
	int					z;
	t_vec				v;

	v.x = p.x;
	v.y = p.y;
	v.z = p.z;
	x = v.x;
	z = v.z;
	v.x = cos(rot_y * RAD) * x + sin(rot_y * RAD) * z;
	v.z = -sin(rot_y * RAD) * x + cos(rot_y * RAD) * z;
	y = v.y;
	z = v.z;
	v.y = cos(rot_x * RAD) * y - sin(rot_x * RAD) * z;
	v.z = sin(rot_x * RAD) * y + cos(rot_x * RAD) * z;
	x = v.x;
	y = v.y;
	v.x = cos(rot_z * RAD) * x - sin(rot_z * RAD) * y;
	v.y = sin(rot_z * RAD) * x + cos(rot_z * RAD) * y;
	return (v);
}

// t_inter		ray_cylindre(t_env *e, int i, int j, t_cam ca, int nbr)
// {
// 	t_inter		pt;
// 	t_polynome	p;
// 	t_vec		v;
//
// 	v = vector_init((i - SIZE_X / 2), (j - SIZE_Y / 2),
// 	(SIZE_X / 2) / tan(30 * RAD));
// 	p.a = v.x * v.x + v.z * v.z;
// 	p.b = 2 * (v.x * (ca.xr - e->obj[nbr].pos.x) +
// 	v.z * (ca.zr - e->obj[nbr].pos.z));
// 	p.c = (ca.xr - e->obj[nbr].pos.x) * (ca.xr - e->obj[nbr].pos.x) +
// 	(ca.zr - e->obj[nbr].pos.z) * (ca.zr - e->obj[nbr].pos.z) -
// 	e->obj[nbr].rayon * e->obj[nbr].rayon;
// 	p.delta = powf(p.b, 2) - 4 * p.a * p.c;
// 	if (p.delta >= 0)
// 	{
// 		if (p.delta > 0)
// 		{
// 			p.x1 = (-p.b + sqrt(p.delta)) / (2 * p.a);
// 			p.x2 = (-p.b - sqrt(p.delta)) / (2 * p.a);
// 			pt.dist = p.x1 < p.x2 ? p.x1 : p.x2;
// 			if (pt.dist < 0)
// 				pt.dist = p.x1 < 0 ? p.x2 : p.x1;
// 		}
// 		else
// 			p.x1 = -p.b / (2 * p.a);
// 		if (!(p.x1 < 0 && p.x2 < 0))
// 			intersection_point(&pt, ca, v);
// 	}
// 	else
// 		pt.dist = -1;
// 	return (pt);
// }

t_inter		ray_cylindre(t_env *e, int i, int j, t_cam ca, int nbr)
{
	t_inter		pt;
	t_polynome	p;
	t_vec		d;
	t_vec		v;
	t_vec		x;
	t_point		o;

	d = vector_init((i - SIZE_X / 2), (j - SIZE_Y / 2),
	(SIZE_X / 2) / tan(30 * RAD));
	o = init_point(e->obj[nbr].pos.x, e->obj[nbr].pos.y, e->obj[nbr].pos.z);
	x = vector_init(ca.xr - o.x, ca.yr - o.y, ca.zr - o.z);
	v = vector_init(1, -1, 0);
	p.a = (dot(d, d) - dot(d, v) * dot(d, v));
	p.b = 2.0 * (dot(d, x) - (dot(d, v) * dot(x, v)));
	p.c = (dot(x, x) - dot(x, v) * dot(x, v)) -
	(e->obj[nbr].rayon * e->obj[nbr].rayon);
	p.delta = pow(p.b, 2) - (4 * p.a * p.c);
	if (p.delta >= 0)
	{
		if (p.delta > 0)
		{
			p.x1 = (-p.b + sqrt(p.delta)) / (2 * p.a);
			p.x2 = (-p.b - sqrt(p.delta)) / (2 * p.a);
			pt.dist = p.x1 < p.x2 ? p.x1 : p.x2;
			if (pt.dist < 0)
				pt.dist = p.x1 < 0 ? p.x2 : p.x1;
		}
		else
			p.x1 = -p.b / (2 * p.a);
		if (!(p.x1 < 0 && p.x2 < 0))
		{
			pt.x = ca.xr + d.x * pt.dist;
			pt.y = ca.yr + d.y * pt.dist;
			pt.z = ca.zr + d.z * pt.dist;
		}
	}
	else
		pt.dist = -1;
	return (pt);
}
