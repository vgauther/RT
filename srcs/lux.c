/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 13:25:20 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		lux(t_env *e, t_inter pt)
{
	int		i;
	t_vec	vnorm;
	t_vec	vlux;
	t_color color;
	double	angle;
	int		lightblock;

	color = split_color(e->obj[pt.nb].color);
	i = -1;
	angle = 0;
	while (++i < e->nb_spot)
	{
		if (!ray_shadow(e, pt.pos, e->spot[i], pt.nb))
			{
				vlux = vector_init(pt.pos.x - e->spot[i].pos.x, pt.pos.y - e->spot[i].pos.y, pt.pos.z - e->spot[i].pos.z);
				vlux = normalize_vec(vlux);
				vmorm = normalize_vec(vector_init(pt.pos.x - e->obj[pt.nb].pos.x)
			}
	}
	color.r = color.r * angle > 255 ? 255 : color.r * angle;
	color.g = color.g * angle > 255 ? 255 : color.g * angle;
	color.b = color.b * angle > 255 ? 255 : color.b * angle;
	return (color.r * 256 * 256 + color.g * 256 + color.b);
}
