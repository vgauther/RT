/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:26:07 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/16 13:12:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec	vec3_cross(t_vec va, t_vec vb)
{
	t_vec	v;

	v.x = va.y * vb.z - va.z * vb.y;
	v.y = va.z * vb.x - va.x * vb.z;
	v.z = va.x * vb.y - va.y * vb.x;
	return (v);
}

Uint32	get_texture_pixel(t_env *e, t_inter pt, t_obj obj)
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
	v.y = v.y * e->test->h;
	v.x = v.x * e->test->w;
	v.color = v.pixels[(int)v.x * (e->test->pitch / e->test->w) +
	e->test->w * (e->test->pitch / e->test->w) * (int)v.y];
	v.color += v.pixels[(int)v.x * (e->test->pitch / e->test->w) + e->test->w
	* (e->test->pitch / e->test->w) * (int)v.y + 1] * 256;
	v.color += v.pixels[(int)v.x * (e->test->pitch / e->test->w) + e->test->w
	* (e->test->pitch / e->test->w) * (int)v.y + 2]
	* 256 * 256;
	return (v.color);
}
