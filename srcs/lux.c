/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/20 14:56:37 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		get_normal(t_env *e, t_inter pt, t_vec ori)
{
	t_vec norm;

	if (e->obj[pt.nb].type == 1)
		norm = sphere_normal_at(pt, e->obj[pt.nb]);
	else if (e->obj[pt.nb].type == 2)
		norm = cylindre_normal_at(pt, e->obj[pt.nb], ori);
	else if (e->obj[pt.nb].type == 4)
		norm = plan_normal_at(pt, e->obj[pt.nb], ori);
	else
		norm = cone_normal_at(pt, e->obj[pt.nb], ori);
	return (norm);
}

double		get_specular_and_difuse(t_vec l, t_inter pt, double *difuse)
{
	t_vec	r;
	t_vec	v;
	double	tmp;

	*difuse = dot(pt.normal, l);
	*difuse = *difuse < 0 ? 0 : *difuse;
	tmp = 0;
	if (difuse > 0)
	{
		tmp = 2 * dot(pt.normal, l);
		r = vector_init(pt.normal.x * tmp, pt.normal.y * tmp,
			pt.normal.z * tmp);
		r = vector_init(r.x - l.x, r.y - l.y, r.z - l.z);
		v = normalize_vec(vector_init(-pt.pos.x, -pt.pos.y, -pt.pos.z));
		tmp = dot(r, v) > 0 ? dot(r, v) : 0;
		tmp = powf(tmp, 10);
	}
	return (tmp);
}

void		get_color_final(t_env *e, t_inter pt,
	t_spec_dif difspec, t_color *colorfin)
{
	t_color spot_color;

	spot_color = normalize_color(split_color(e->spot[difspec.i].color));
	colorfin->r += 1 * difspec.difuse * (pt.color_rgb.r * spot_color.r);
	colorfin->g += 1 * difspec.difuse * (pt.color_rgb.g * spot_color.g);
	colorfin->b += 1 * difspec.difuse * (pt.color_rgb.b * spot_color.b);
	colorfin->r += 1 * difspec.specular * spot_color.r;
	colorfin->g += 1 * difspec.specular * spot_color.g;
	colorfin->b += 1 * difspec.specular * spot_color.b;
}

double		lux(t_env *e, t_inter pt)
{
	t_vec		l;
	t_color		colorfin;
	t_spec_dif	difspec;

	colorfin = color_init(0, 0, 0);
	difspec.i = 0;
	pt.normal = get_normal(e, pt, e->ca.pos);
	pt.color_rgb = e->obj[pt.nb].material == 2 ? split_color(
	get_texture_pixel(e, pt, e->obj[pt.nb])) : split_color(e->obj[pt.nb].color);
	pt.color_rgb = normalize_color(pt.color_rgb);
	while (difspec.i < e->nb_spot)
	{
		if (!(ray_shadow(e, pt, e->spot[difspec.i], pt.nb)))
		{
			l = normalize_vec(vector_init(e->spot[difspec.i].pos.x - pt.pos.x,
	e->spot[difspec.i].pos.y - pt.pos.y, e->spot[difspec.i].pos.z - pt.pos.z));
			difspec.specular = get_specular_and_difuse(l, pt, &difspec.difuse);
			get_color_final(e, pt, difspec, &colorfin);
		}
		difspec.i += 1;
	}
	return (rgb_to_int(colorfin));
}
