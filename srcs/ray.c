/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:40:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/05 18:19:13 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel(t_sdl *sdl, int x, int y, int color)
{
	sdl->pixels[(y * SIZE_X + x)] = color;
}

void	one_pixel(t_obj obj, t_sdl *sdl, int i, int j, t_cam ca, int nb)
{
	t_polynome	p;
	double		vx;
	double		vy;
	double		vz;
	double		f1;
	double		f2;
	double		f3;

	f1 = ca.xr - obj.sphere[nb].pos.x;
	f2 = ca.yr - obj.sphere[nb].pos.y;
	f3 = ca.zr - obj.sphere[nb].pos.z;
	vx = (i - SIZE_X / 2);
	vy = (j - SIZE_Y / 2);
	vz = (SIZE_X / 2) / tan(30 * RAD);
	p.a = (vx * vx) + (vy * vy) + (vz * vz);
	p.b = 2 * (vx * (f1) + vy * (f2) + vz * (f3));
	p.c = (((f1 * f1) + (f2 * f2) + (f3 * f3)) - obj.sphere[nb].rayon_pow);
	p.delta = (p.b * p.b) - 4 * p.a * p.c;
	if (p.delta >= 0)
	{
		if (p.delta > 0)
		{
			p.x1 = (-p.b + sqrt(p.delta)) / (2 * p.a);
			p.x2 = (-p.b - sqrt(p.delta)) / (2 * p.a);
		}
		else
			p.x1 = -p.b / (2 * p.a);
		ft_put_pixel(sdl, i, j, obj.sphere[nb].color);
	}
}

void	raytracing(t_obj obj, t_sdl s, t_cam c)
{
	int x;
	int y;
	int nb;

	nb = 0;
	while (nb != obj.nb.sphere)
	{
		x = 0;
		while (x != SIZE_X)
		{
			y = 0;
			while (y != SIZE_Y)
			{
				one_pixel(obj, &s, x, y, c, nb);
				y++;
			}
			x++;
		}
		nb++;
	}
	ft_put_pixel(&s, SIZE_X / 2, SIZE_Y / 2, 0x00FF00);
	s.surface->pixels = s.pixels;
	display(&s);
}
