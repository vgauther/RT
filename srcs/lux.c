/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/07 15:29:58 by vgauther         ###   ########.fr       */
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
	int r;
	int g;
	int b;
	double angle;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	i = 0;
	(void)ca;
	(void)obj;
	(void)nb;
	while (1 != i)
	{
		f1 = (obj.sphere[nb].pos.x - pt.x);
		f2 = (obj.sphere[nb].pos.y - pt.y);
		f3 = (obj.sphere[nb].pos.z - pt.z);
		f12 = (100 - pt.x);
		f22 = (100 - pt.y);
		f32 = (50 - pt.z);
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
//	angle = acos(f1 * f1 + f2 * f2 + f3 * f3);
	angle = acos(f1 * f12 + f2 * f22 + f3 * f32);
	//printf("%f\n", f1 * f12 + f2 * f22 + f3 * f32);
	//printf("%f\n", angle / RAD);
	angle *= 0.4;
	r *= angle;
	g *= angle;
	b *= angle;
	r  = r > 255 ? 255 : r;
	b  = b > 255 ? 255 : b;
	g  = g > 255 ? 255 : g;
	return ((r * 256 * 256 + g * 256 + b));
	//return (color *angle);
}
