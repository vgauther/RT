/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:28:07 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/30 13:40:04 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

Uint32	transp(t_env *e, t_inter pt, Uint32 color, t_vec ori)
{
	t_color		color_rgb;
	t_color		color_2;
	t_inter		tmp;
	t_vec		dir;
	int			depth;

	depth = 0;
	color_rgb = normalize_color(split_color(color));
	dir = normalize_vec(sub_vec(pt.pos, ori));
	tmp = get_closest_test(e, dir, pt.pos, pt.nb);
	if (tmp.dist != MAX_DIST)
	{
		color_2 = normalize_color(split_color(lux(e, tmp)));
		if (e->obj[tmp.nb].transp)
			color_2 = mult_color(color_2, normalize_color(split_color(transp(e,
				tmp, rgb_to_int(color_2), pt.pos))));
		if (e->obj[tmp.nb].reflex)
		{
			color_2 = mult_color(color_2, normalize_color(
				split_color(get_reflect(e, tmp, &depth, rgb_to_int(color_2)))));
		}
		color_rgb = mult_color(color_rgb, color_2);
	}
	return (rgb_to_int(color_rgb));
}
