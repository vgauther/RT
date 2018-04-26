/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:21:13 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/25 17:45:38 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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
	if (tmp.dist != MAX_DIST && *depth < 100)
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
