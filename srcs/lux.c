/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/07 17:15:49 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		lux(t_obj obj, int color, t_inter pt, int nb)
{
	int i;
	double norm;
	double norm2;
	t_3dvector vnorm;
	t_3dvector vlux;
	int r;
	int g;
	int b;
	double angle;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	i = 0;
	while (1 != i)
	{
		vnorm.x = (obj.sphere[nb].pos.x - pt.x);
		vnorm.y = (obj.sphere[nb].pos.y - pt.y);
		vnorm.z = (obj.sphere[nb].pos.z - pt.z);
		vlux.x = (0 - pt.x);
		vlux.y = (0 - pt.y);
		vlux.z = (60 - pt.z);
		norm = sqrt(vnorm.x * vnorm.x + vnorm.y * vnorm.y + vnorm.z * vnorm.z);
		norm2 = sqrt(vlux.x * vlux.x + vlux.y * vlux.y + vlux.z * vlux.z);
		i++;
	}
	vnorm.x /= norm;
	vnorm.y /= norm;
	vnorm.z /= norm;
	vlux.x /= norm2;
	vlux.y /= norm2;
	vlux.z /= norm2;
	angle = acos(vnorm.x * vlux.x + vnorm.y * vlux.y + vnorm.z * vlux.z) * 0.42;
	r = r * angle > 255 ? 255 : r * angle;
	g = g * angle > 255 ? 255 : g * angle;
	b = b * angle > 255 ? 255 : b * angle;
	return (r * 256 * 256 + g * 256 + b);
}
