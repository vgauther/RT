/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/06 13:12:41 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		lux(t_env *e, t_inter pt)
{
	int		i;
	t_vec	n;
	t_vec	l;
	t_vec	r;
	t_vec 	v;
	double	te;
	t_color	color;
	t_color spot_color;
	t_color colorfin;
	double	angle;
	double	specular;
	double lambert;

	colorfin.r = 0;
	colorfin.g = 0;
	colorfin.b = 0;
	i = 0;
	n = normalize_vec(vector_init(pt.pos.x - e->obj[pt.nb].pos.x, pt.pos.y - e->obj[pt.nb].pos.y, pt.pos.z - e->obj[pt.nb].pos.z));
	color = split_color(e->obj[pt.nb].color);
	color = normalize_color(color);
	while (i < e->nb_spot)
	{
		if (!(ray_shadow(e, pt, e->spot[i], pt.nb)))
		{
			l = normalize_vec(vector_init(e->spot[i].pos.x - pt.pos.x, e->spot[i].pos.y - pt.pos.y, e->spot[i].pos.z - pt.pos.z));
			lambert = dot(n, l);
			lambert = lambert < 0 ? 0 : lambert;
			specular = 0;
			if (lambert > 0)
			{
				te = 2 * dot(n, l);
				r = vector_init(n.x * te, n.y * te, n.z * te);
				r = vector_init(r.x - l.x, r.y - l.y, r.z - l.z);
				v = normalize_vec(vector_init(-pt.pos.x, -pt.pos.y, -pt.pos.z));
				angle = dot(r, v) > 0 ? dot(r, v) : 0;
				specular = powf(angle, 10);
			}
			spot_color = split_color(e->spot[i].color);
			spot_color = normalize_color(spot_color);
			colorfin.r += 1 * lambert * ((spot_color.r + color.r) / 2);
			colorfin.g += 1 * lambert * ((spot_color.g + color.g) / 2);
			colorfin.b += 1 * lambert * ((spot_color.b + color.b) / 2);
			colorfin.r += 1 * specular * 1;
			colorfin.g += 1 * specular * 1;
			colorfin.b += 1 * specular * 1;
		}
		i++;
	}
	colorfin.r *= 255;
	colorfin.g *= 255;
	colorfin.b *= 255;

	colorfin.r = colorfin.r > 255 ? 255 : colorfin.r;
	colorfin.g = colorfin.g > 255 ? 255 : colorfin.g;
	colorfin.b = colorfin.b > 255 ? 255 : colorfin.b;
	return (((int)colorfin.r * 256 * 256) + ((int)colorfin.g * 256) + (int)colorfin.b);
}
