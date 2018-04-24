/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/24 13:49:32 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

t_inter		get_closest_test(t_env *e, t_vec dir, t_vec ori, int t)
{
	int		nbr;
	t_inter	tmp;
	t_inter p;

	nbr = 0;
	p.dist = MAX_DIST;
	while (nbr < e->nb)
	{
		tmp = shape_redirection(e, dir, ori, nbr);
		if (tmp.dist < p.dist && tmp.dist > 0 && t != nbr)
		{
			p.dist = tmp.dist;
			p.pos = init_point(tmp.pos.x, tmp.pos.y, tmp.pos.z);
			p.normal = tmp.normal;
			p.nb = nbr;
			p.normal = get_normal(e, p, e->ca.pos);
		}
		nbr++;
	}
	return (p);
}

/*
** Maths for equ -> I * 2 (I . N) * N = R
** I -> Vect from cam to obj hitted
** 2 -> Inverse the angle
** N -> Normal vec from obj hitted
** R -> New vec to the next direction from the hitted obj
*/

Uint32		get_reflect(t_env *e, t_inter pt, int *depth, Uint32 color)
{
	t_color		color_rgb;
	t_color		color_2;
	t_inter		tmp;
	t_vec		ref;
	t_vec		dir_ori;

	color_rgb = normalize_color(split_color(color));
	dir_ori = normalize_vec(sub_vec(pt.pos, e->ca.pos));
	ref = sub_vec(dir_ori, v_scale(2 * dot(dir_ori, pt.normal), &pt.normal));
	tmp = get_closest_test(e, ref, pt.pos, pt.nb);
	if (tmp.dist != MAX_DIST && *depth < 5)
	{
		color_2 = normalize_color(split_color(lux(e, tmp)));
		if (e->obj[tmp.nb].reflex)
		{
			*depth += 1;
			color_2 = mult_color(color_2, normalize_color(
				split_color(get_reflect(e, tmp, depth, rgb_to_int(color_2)))));
		}
		color_rgb = mult_color(color_rgb, color_2);
	}
	return (rgb_to_int(color_rgb));
}

double		lux(t_env *e, t_inter pt)
{
	t_vec		l;
	t_color		colorfin;
	t_spec_dif	difspec;

	colorfin = color_init(0, 0, 0);
	difspec.i = 0;
	pt.color_rgb = e->obj[pt.nb].material == 2 ? split_color(
	get_texture_pixel(e, pt, e->obj[pt.nb])) : split_color(e->obj[pt.nb].color);
	pt.color_rgb = normalize_color(pt.color_rgb);
	while (difspec.i < e->nb_spot)
	{
		if (!(ray_shadow(e, pt, e->spot[difspec.i], pt.nb)) ||
		e->obj[pt.nb].reflex)
		{
			l = normalize_vec(sub_vec(e->spot[difspec.i].pos, pt.pos));
			difspec.specular = get_specular_and_difuse(l, pt, &difspec.difuse);
			get_color_final(e, pt, difspec, &colorfin);
		}
		difspec.i += 1;
	}
	colorfin.r += 0.2 * pt.color_rgb.r;
	colorfin.g += 0.2 * pt.color_rgb.g;
	colorfin.b += 0.2 * pt.color_rgb.b;
	return (rgb_to_int(colorfin));
}
