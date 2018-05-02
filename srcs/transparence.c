/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:28:07 by fde-souz          #+#    #+#             */
/*   Updated: 2018/05/02 18:55:55 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

Uint32		transp(t_reflect_transp *var, t_inter pt, Uint32 color, t_vec ori)
{
	t_color		color_rgb;
	t_color		color_2;
	t_inter		tmp;
	t_vec		dir;

	color_rgb = normalize_color(split_color(color));
	dir = normalize_vec(sub_vec(pt.pos, ori));
	tmp = get_closest_test(var->e, dir, pt.pos, pt.nb);
	if (tmp.dist != MAX_DIST)
	{
		color_2 = normalize_color(split_color(lux(var->e, tmp)));
		if (var->e->obj[tmp.nb].transp)
			color_2 = mult_color(color_2, normalize_color(split_color(transp(
				var, tmp, rgb_to_int(color_2), pt.pos))));
		if (var->e->obj[tmp.nb].reflex && *var->depth < 8)
		{
			color_2 = mult_color(color_2, normalize_color(
				split_color(get_reflect(var, tmp, rgb_to_int(color_2)))));
		}
		color_rgb = mult_color(color_rgb, color_2);
	}
	return (rgb_to_int(color_rgb));
}
