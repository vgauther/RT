/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 17:14:17 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		lux(t_env *e, t_inter pt)
{
	int		i;
	t_vec	vnorm;
	t_vec	vlux;
	t_color color;
	t_color spot_color;
	t_color colorfin;
	double	angle;

	colorfin.r = 0;
	colorfin.g = 0;
	colorfin.b = 0;
	color = split_color(e->obj[pt.nb].color);
	i = 0;
	angle = 0;
	while (i < e->nb_spot)
	{
		if (!(ray_shadow(e, pt, e->spot[i], pt.nb)))
		{
			vlux = vector_init(pt.pos.x - e->spot[i].pos.x, pt.pos.y - e->spot[i].pos.y, pt.pos.z - e->spot[i].pos.z);
			vlux = normalize_vec(vlux);
			vnorm = normalize_vec(vector_init(pt.pos.x - e->obj[pt.nb].pos.x, pt.pos.y - e->obj[pt.nb].pos.y, pt.pos.z - e->obj[pt.nb].pos.z));
			angle = acos(vnorm.x * vlux.x + vnorm.y * vlux.y + vnorm.z * vlux.z);
			spot_color = split_color(e->spot[i].color);
			if (angle > 0)
			{
				colorfin.r += 0.2 * spot_color.r * angle;
				colorfin.g += 0.2 * spot_color.g * angle;
				colorfin.b += 0.2 * spot_color.b * angle;
			}
		}
		i++;
	}
	colorfin.r = colorfin.r > 255 ? 255 : colorfin.r;
	colorfin.g = colorfin.g > 255 ? 255 : colorfin.g;
	colorfin.b = colorfin.b > 255 ? 255 : colorfin.b;
	return ((colorfin.r * 256 * 256) + (colorfin.g * 256) + colorfin.b);
}
