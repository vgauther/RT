/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/27 15:46:18 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		lux(t_env *e, t_inter pt)
{
	int		i;
	double	norm;
	double	norm2;
	t_vec	vnorm;
	t_vec	vlux;
	t_color color;
	double	angle;

	color = split_color(e->obj[pt.nb].color);
	i = -1;
	while (1 != ++i)
	{
		vnorm = vector_init((e->obj[pt.nb].pos.x - pt.x),
		(e->obj[pt.nb].pos.y - pt.y), (e->obj[pt.nb].pos.z - pt.z));
		vlux = vector_init((20 - pt.x), (0 - pt.y), (-90 - pt.z));
		norm = sqrt(vnorm.x * vnorm.x + vnorm.y * vnorm.y + vnorm.z * vnorm.z);
		norm2 = sqrt(vlux.x * vlux.x + vlux.y * vlux.y + vlux.z * vlux.z);
	}
	vnorm = normalize_vec(vnorm);
	vlux = normalize_vec(vlux);
	angle = acos(vnorm.x * vlux.x + vnorm.y * vlux.y + vnorm.z * vlux.z) * 0.42;
	color.r = color.r * angle > 255 ? 255 : color.r * angle;
	color.g = color.g * angle > 255 ? 255 : color.g * angle;
	color.b = color.b * angle > 255 ? 255 : color.b * angle;
	return (color.r * 256 * 256 + color.g * 256 + color.b);
}
