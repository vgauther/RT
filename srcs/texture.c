/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:26:07 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/24 16:57:10 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

Uint32	get_texture_pixel_sphere(t_env *e, t_inter pt, t_obj obj)
{
	t_texture_calc v;

	v.pl = normalize_vec(vector_init(0, 1, 0));
	v.eq = normalize_vec(vector_init(1, 0, 0));
	v.pixels = (char*)e->test->pixels;
	v.vp = normalize_vec(vector_init(pt.pos.x - obj.pos.x,
		pt.pos.y - obj.pos.y, pt.pos.z - obj.pos.z));
	v.phi = acos(-dot(v.vp, v.pl));
	v.y = v.phi / M_PI;
	v.theta = (acos(dot(v.vp, v.eq) / sin(v.phi))) / (2 * M_PI);
	if (dot(vec3_cross(v.pl, v.eq), v.vp) > 0)
		v.x = v.theta;
	else
		v.x = 1 - v.theta;
	v.x = isnan(v.x) ? 1 : v.x;
	v.y = isnan(v.y) ? 1 : v.y;
	v.y = v.y * e->test->h;
	v.x = v.x * e->test->w;
	v.color = v.pixels[(int)v.x * (e->test->pitch / e->test->w) +
	e->test->w * (e->test->pitch / e->test->w) * (int)v.y];
	v.color += v.pixels[(int)v.x * (e->test->pitch / e->test->w) + e->test->w
	* (e->test->pitch / e->test->w) * (int)v.y + 1] * 256;
	v.color += v.pixels[(int)v.x * (e->test->pitch / e->test->w) + e->test->w
	* (e->test->pitch / e->test->w) * (int)v.y + 2] * 256 * 256;
	return (v.color);
}

Uint32	get_texture_pixel_plane(t_env *e, t_inter pt, t_obj obj)
{
	t_vec	ua;
	t_vec	va;
	double	u;
	double	v;

	(void)e;
	(void)obj;
	ua = vector_init(pt.normal.y, pt.normal.z, -pt.normal.x);
	va = vec3_cross(ua, pt.normal);
	u = dot(pt.pos, ua);
	v = dot(pt.pos, va);
	if ((((int)u % 2) && ((int)v % 2)))
		return (0);
	return (0xffffff);
}

Uint32	get_texture_chest_sphere(t_env *e, t_inter pt, t_obj obj)
{
	t_texture_calc	v;
	int				xpair;
	int				ypair;

	(void)e;
	v.pl = normalize_vec(vector_init(0, 1, 0));
	v.eq = normalize_vec(vector_init(1, 0, 0));
	v.vp = normalize_vec(vector_init(pt.pos.x - obj.pos.x,
		pt.pos.y - obj.pos.y, pt.pos.z - obj.pos.z));
	v.phi = acos(-dot(v.vp, v.pl));
	v.y = v.phi / M_PI;
	v.theta = (acos(dot(v.vp, v.eq) / sin(v.phi))) / (2 * M_PI);
	if (dot(vec3_cross(v.pl, v.eq), v.vp) > 0)
		v.x = v.theta;
	else
		v.x = 1 - v.theta;
	v.x = isnan(v.x) ? 1 : v.x;
	v.y = isnan(v.y) ? 1 : v.y;
	v.x *= 10;
	v.y *= 10;
	xpair = ((int)v.x % 2);
	ypair = ((int)v.y % 2);
	//get_texture_pixel_plane(e, pt, obj);
	if ((xpair && ypair) || (!xpair && !ypair))
		return (0);
	return (0xffff00);
}
