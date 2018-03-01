/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:40:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/01 18:39:05 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel(Uint32 **pixels, int x, int y, int color)
{
			*pixels[(y * SIZE_Y + x)] = color;
}

void	one_pixel(t_obj obj, Uint32 **pixels)
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
	double t1;
	double t2;
	int delta;

	cam_x = 0;
	cam_y = 0;
	cam_z = 0;
	dir_x = obj.sphere[0].pos.x - cam_x;
	dir_y = obj.sphere[0].pos.y - cam_y;
	dir_z = obj.sphere[0].pos.z - cam_z;
	a = (dir_x*dir_x) + (dir_y*dir_y) + (dir_z*dir_z)
	b = 2 * (dir_x * (cam_x - obj.sphere[0].pos.x) + dir_y * (cam_y - obj.sphere[0].pos.y) + dir_z * (cam_z - obj.sphere[0].pos.z))
	c = ((cam_x - obj.sphere[0].pos.x)*(cam_x - obj.sphere[0].pos.x)+(cam_y - obj.sphere[0].pos.y)*(cam_y - obj.sphere[0].pos.y)+(cam_z - obj.sphere[0].pos.z)*(cam_z - obj.sphere[0].pos.z)) - (obj.sphere[0].rayon * obj.sphere[0].rayon)
	delta = (b*b) - 4*a*c;
	if(delta > 0)
	{
		t1 = (-b + sqrt(delta))/(2 * a);
		t2 = (-b - sqrt(delta))/(2 * a);
		ft_put_pixel(pixels, x, y, obj.sphere[0].color);
	}
}

void	raytring(t_obj obj)
{
	int x;
	int y;
	Uint32 pixels[SIZE_Y * SIZE_X];

	y = 0;
	while (y != SIZE_Y)
	{
		x = 0;
		while (x != SIZE_X)
		{
			one_pixel(obj, &pixels);
			x++;
		}
		y++;
	}
}
