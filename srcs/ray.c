/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:40:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/14 14:26:19 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel(t_sdl *sdl, int x, int y, double color)
{
	sdl->pixels[(y * VIEW_X + x)] = color;
}

t_inter		one_pixel(t_obj obj, t_sdl *sdl, int i, int j, t_cam ca, int nb)
{
	t_polynome	p;
	t_inter		t;
	double		vx;
	double		vy;
	double		vz;
	double		f1;
	double		f2;
	double		f3;

	(void)sdl;
	f1 = ca.xr - obj.sphere[nb].pos.x;
	f2 = ca.yr - obj.sphere[nb].pos.y;
	f3 = ca.zr - obj.sphere[nb].pos.z;
	vx = (i - VIEW_X / 2);
	vy = (j - VIEW_Y / 2);
	vz = (VIEW_X / 2) / tan(30 * RAD);
	p.a = (vx * vx) + (vy * vy) + (vz * vz);
	p.b = 2 * (vx * f1 + vy * f2 + vz * f3);
	p.c = (((f1 * f1) + (f2 * f2) + (f3 * f3)) - obj.sphere[nb].rayon_pow);
	p.delta = (p.b * p.b) - 4 * p.a * p.c;
	if (p.delta >= 0)
	{
		if (p.delta > 0)
		{
			p.x1 = (-p.b + sqrt(p.delta)) / (2 * p.a);
			p.x2 = (-p.b - sqrt(p.delta)) / (2 * p.a);
			t.dist = p.x1 < p.x2 ? p.x1 : p.x2;
		}
		else
			t.dist = -p.b / (2 * p.a);
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

void	raytracing(t_obj obj, t_sdl s, t_cam c)
{
	int x;
	int y;
	int nb;
	int token;
	t_inter pt;
	t_inter tmp;

	token = 42;
	x = 0;
	ft_memset(s.pixels, 255, SIZE_X * SIZE_Y * sizeof(Uint32));
	while (x < VIEW_X)
	{
		y = 0;
		while (y < VIEW_Y)
		{
			nb = 0;
			token = 42;
			while (nb != obj.nb.sphere)
			{
				tmp = one_pixel(obj, &s, x, y, c, nb);
				if ((tmp.dist < pt.dist || pt.dist < 0) && tmp.dist >= 0)
				{
					pt.dist = tmp.dist;
					pt.x = tmp.x;
					pt.y = tmp.y;
					pt.z = tmp.z;
					pt.nb = nb;
					token = 0;
				}
				else if (token == 42)
				{
					pt.dist = tmp.dist;
					pt.nb = nb;
					pt.x = tmp.x;
					pt.y = tmp.y;
					pt.z = tmp.z;
					token = 0;
				}
				nb++;
			}
			if (pt.dist >= 0)
				ft_put_pixel(&s, x, y, lux(obj, obj.sphere[pt.nb].color, pt, pt.nb));
			y++;
		}
		x++;
	}
	ft_put_pixel(&s, VIEW_X / 2, VIEW_Y / 2, 0x00FF00);
	s.surface->pixels = s.pixels;
	display(&s);
}
