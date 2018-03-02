/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:40:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/02 14:26:57 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel(t_sdl *sdl, int x, int y, int color)
{
	printf("%d\n", color);
	sdl->pixels[(y * SIZE_X + x)] = 0xff0000;
}

void	one_pixel(t_obj obj, t_sdl *sdl, int x, int y)
{
	int dir_x;
	int dir_y;
	int dir_z;
	int a;
	int b;
	int c;
	int cam_x;
	int cam_y;
	int cam_z;
	int wall;
	double t1;
	double t2;
	int delta;

	cam_x = 0;
	cam_y = 0;
	cam_z = 0;
	wall = (SIZE_X / 2) / tan(30);
	dir_x = x - cam_x;
	dir_y = y - cam_y;
	dir_z = sqrt((SIZE_X/2 - x) * (SIZE_X / 2 - x) + wall * wall) - cam_z;
	a = (dir_x * dir_x) + (dir_y * dir_y) + (dir_z * dir_z);
	b = 2 * (dir_x * (cam_x - obj.sphere[0].pos.x) + dir_y *
	(cam_y - obj.sphere[0].pos.y) + dir_z * (cam_z - obj.sphere[0].pos.z));
	c = ((cam_x - obj.sphere[0].pos.x) * (cam_x - obj.sphere[0].pos.x) +
	(cam_y - obj.sphere[0].pos.y) * (cam_y - obj.sphere[0].pos.y) +
	(cam_z - obj.sphere[0].pos.z) *
	(cam_z - obj.sphere[0].pos.z)) -
	(obj.sphere[0].rayon * obj.sphere[0].rayon);
	delta = (b * b) - 4 * a * c;
	if (delta > 0)
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
			printf("%s\n","pute");
		ft_put_pixel(sdl, x, y, obj.sphere[0].color);
	}
}

void	raytracing(t_obj obj, t_sdl s)
{
	int x;
	int y;

	x = 0;
	(void)obj;
	while (x != SIZE_X)
	{
		y = 0;
		while (y != SIZE_Y)
		{
			one_pixel(obj, &s, x, y);
			//ft_put_pixel(&s, x, y, 0xff0000);
			y++;
		}
		x++;
	}
	s.surface->pixels = s.pixels;
	display(&s);
}
