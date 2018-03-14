/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>   	        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/03/06 14:40:03 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	e->pixels[(y * SIZE_X + x)] = color;
}

t_inter	one_pixel(t_env *e, int i, int j, t_cam ca, int nbr)
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

void	raytracing(t_env *e, t_cam c, t_sdl s)
{
	int x;
	int y;
	int nbr;
	int token;
	t_inter pt;
	t_inter tmp;

	token = 42;
	x = 0;
	while (x != SIZE_X)
	{
		y = 0;
		while (y != SIZE_Y)
		{
			nbr = 0;
			token = 42;
			while (nbr != e->nb)
			{
				tmp = one_pixel(e, x, y, c, nbr);
				if ((tmp.dist < pt.dist || pt.dist < 0) && tmp.dist >= 0)
				{
					pt.dist = tmp.dist;
					pt.x = tmp.x;
					pt.y = tmp.y;
					pt.z = tmp.z;
					pt.nb = nbr;
					token = 0;
				}
				else if (token == 42)
				{
					pt.dist = tmp.dist;
					pt.nb = nbr;
					pt.x = tmp.x;
					pt.y = tmp.y;
					pt.z = tmp.z;
					token = 0;
				}
				nbr++;
			}
			if (pt.dist >= 0)
				ft_put_pixel(e, x, y, lux(e, pt));
			y++;
		}
		x++;
	}
	// ft_put_pixel(e, SIZE_X / 2, SIZE_Y / 2, 0x00FF00);
	s.surface->pixels = e->pixels;
	display(&s);
}
