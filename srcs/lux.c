/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/16 13:50:00 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec	get_normal(t_env *e, t_inter pt, t_obj spot)
{
	t_vec norm;

	if (e->obj[pt.nb].type == 1)
		norm = sphere_normal_at(pt, e->obj[pt.nb]);
	else if (e->obj[pt.nb].type == 2)
		norm = cylindre_normal_at(pt, e->obj[pt.nb], spot);
	else
		norm = cone_normal_at(pt, e->obj[pt.nb], spot);
	return (norm);
}

double		lux(t_env *e, t_inter pt)
{
	int		i;
	t_vec	l;
	t_vec	r;
	t_vec	v;
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
	color = split_color(e->obj[pt.nb].color);
	//color = split_color(get_texture_pixel(e, pt, e->obj[pt.nb]));
	color = normalize_color(color);
	while (i < e->nb_spot)
	{
		if (!(ray_shadow(e, pt, e->spot[i], pt.nb)))
		{
			l = normalize_vec(vector_init(e->spot[i].pos.x - pt.pos.x, e->spot[i].pos.y - pt.pos.y, e->spot[i].pos.z - pt.pos.z));
			pt.normal = get_normal(e, pt, e->spot[i]);
			lambert = dot(pt.normal, l);
			lambert = lambert < 0 ? 0 : lambert;
			specular = 0;
			if (lambert > 0)
			{
				te = 2 * dot(pt.normal, l);
				r = vector_init(pt.normal.x * te, pt.normal.y * te, pt.normal.z * te);
				r = vector_init(r.x - l.x, r.y - l.y, r.z - l.z);
				v = normalize_vec(vector_init(-pt.pos.x, -pt.pos.y, -pt.pos.z));
				angle = dot(r, v) > 0 ? dot(r, v) : 0;
				specular = powf(angle, 10);
			}
			spot_color = split_color(e->spot[i].color);
			spot_color = normalize_color(spot_color);
			colorfin.r += 1 * lambert * (color.r * spot_color.r);
			colorfin.g += 1 * lambert * (color.g * spot_color.g);
			colorfin.b += 1 * lambert * (color.b * spot_color.b);
			colorfin.r += 1 * specular * spot_color.r;
			colorfin.g += 1 * specular * spot_color.g;
			colorfin.b += 1 * specular * spot_color.b;
			/*colorfin.r += 0.2 * color.r * spot_color.r;
			colorfin.g += 0.2 * color.g * spot_color.g;
			colorfin.b += 0.2 * color.b * spot_color.b;*/
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
