/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/06 18:31:11 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		lux(t_obj obj, int color, t_pos pt, t_cam ca, int nb)
{
	int i;
	double norm;
	double norm2;
	double f1;
	double f2;
	double f3;
	double f12;
	double f22;
	double f32;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	double angle;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	i = 0;
	norm = 0;
	(void)ca;
	(void)obj;
	(void)nb;
	while (1 != i)
	{
		f1 = (obj.sphere[0].pos.x - pt.x);
		f2 = (obj.sphere[0].pos.y - pt.y);
		f3 = (obj.sphere[0].pos.z - pt.z);
		f12 = (10 - pt.x);
		f22 = (10 - pt.y);
		f32 = (10 - pt.z);
		norm = sqrt(f1 * f1 + f2 * f2 + f3 * f3);
		norm2 = sqrt(f12 * f12 + f22 * f22 + f32 * f32);
		i++;
	}
	//f1 = f1 - f12;
	f1 /= norm;
	//f2 = f2 - f22;
	f2 /= norm;
	//f3 = f3 - f32;
	f3 /= norm;
	f12 /= norm2;
	f22 /= norm2;
	f32 /= norm2;
	/*f1 = f1 - f12;
	f2 = f2 - f22;
	f3 = f3 - f32;*/
	angle = acos(f1 * f1 + f2 * f2 + f3 * f3);
	//angle = acos(f1 * f12 + f2 * f22 + f3 * f32);
	//printf("%f\n", f1 * f12 + f2 * f22 + f3 * f32);
	//printf("%f\n", angle / RAD);
	//r = r + 1000/norm;
	//g = g + 1000/norm;
	//b = b + 1000/norm;
	r *= angle;
	g *= angle;
	b *= angle;
	return (r * 256 * 256 + g * 256 + b);
	//return (color *angle);
}
