/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:30:16 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/30 14:31:53 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		ray_shadow(t_env *e, t_inter pt, t_obj spot, Uint32 *color)
{
	int		j;
	t_vec	dir;
	t_inter tmp;
	double	dist;

	j = 0;
	dir = vector_init(pt.pos.x - spot.pos.x,
	pt.pos.y - spot.pos.y, pt.pos.z - spot.pos.z);
	dist = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	dir = normalize_vec(dir);
	while (j < e->nb)
	{
		tmp = shape_redirection(e, dir, spot.pos, j);
		tmp.nb = j;
		if (dist - 1 > tmp.dist && tmp.dist > 0)
		{
			if (!e->obj[j].transp)
				return (1);
			else
				*color = rgb_to_int(mult_color(normalize_color(split_color(
				*color)), normalize_color(color_pix(e, tmp))));
		}
		j++;
	}
	return (0);
}

double	get_specular_and_difuse(t_vec l, t_inter pt, double *difuse, t_cam c)
{
	t_vec	r;
	t_vec	v;
	double	tmp;

	*difuse = dot(pt.normal, l);
	*difuse = *difuse < 0 ? 0 : *difuse;
	tmp = 0;
	if (difuse > 0)
	{
		r = sub_vec(vector_init(-l.x, -l.y, -l.z),
		v_scale(2 * dot(vector_init(-l.x, -l.y, -l.z), pt.normal), &pt.normal));
		v = normalize_vec(sub_vec(c.pos, pt.pos));
		tmp = dot(r, v) > 0 ? dot(r, v) : 0;
		tmp = powf(tmp, 10);
	}
	return (tmp);
}

void	get_color_final(t_env *e, t_inter pt,
	t_spec_dif difspec, t_color *colorfin)
{
	t_color spot_color;

	(void)e;
	spot_color = normalize_color(split_color(difspec.col));
	colorfin->r += 1 * difspec.difuse * (pt.color_rgb.r * spot_color.r);
	colorfin->g += 1 * difspec.difuse * (pt.color_rgb.g * spot_color.g);
	colorfin->b += 1 * difspec.difuse * (pt.color_rgb.b * spot_color.b);
	colorfin->r += 1 * difspec.specular * spot_color.r;
	colorfin->g += 1 * difspec.specular * spot_color.g;
	colorfin->b += 1 * difspec.specular * spot_color.b;
}

t_color	color_pix(t_env *e, t_inter pt)
{
	t_color color;

	if (e->obj[pt.nb].material == 2 && e->obj[pt.nb].type == 1)
		color = split_color(get_texture_pixel_sphere(e, pt, e->obj[pt.nb]));
	else if (e->obj[pt.nb].material == 3 && e->obj[pt.nb].type == 1)
		color = split_color(get_texture_chest_sphere(e, pt, e->obj[pt.nb]));
	else
		color = split_color(e->obj[pt.nb].color);
	return (color);
}

double	lux(t_env *e, t_inter pt)
{
	t_vec		l;
	t_color		colorfin;
	t_spec_dif	difspec;

	colorfin = color_init(0, 0, 0);
	difspec.i = 0;
	pt.color_rgb = color_pix(e, pt);
	pt.color_rgb = normalize_color(pt.color_rgb);
	while (difspec.i < e->nb_spot)
	{
		difspec.col = e->spot[difspec.i].color;
		if (!(ray_shadow(e, pt, e->spot[difspec.i], &difspec.col))
			|| e->obj[pt.nb].reflex)
		{
			l = normalize_vec(sub_vec(e->spot[difspec.i].pos, pt.pos));
			difspec.specular = get_specular_and_difuse(l, pt, &difspec.difuse,
			e->ca);
			get_color_final(e, pt, difspec, &colorfin);
		}
		difspec.i += 1;
	}
	colorfin.r += e->amb * pt.color_rgb.r;
	colorfin.g += e->amb * pt.color_rgb.g;
	colorfin.b += e->amb * pt.color_rgb.b;
	return (rgb_to_int(colorfin));
}
