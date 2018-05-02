/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:21:13 by fde-souz          #+#    #+#             */
/*   Updated: 2018/05/02 18:53:37 by fde-souz         ###   ########.fr       */
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

Uint32		get_reflect(t_reflect_transp *var, t_inter pt, Uint32 color)
{
	t_color		color_rgb;
	t_color		color_2;
	t_inter		tmp;
	t_vec		ref;

	color_rgb = normalize_color(split_color(color));
	ref = normalize_vec(sub_vec(pt.pos, var->e->ca.pos));
	ref = sub_vec(ref, v_scale(2 * dot(ref, pt.normal), &pt.normal));
	pt.pos = add_vec(pt.pos, v_scale(0.01, &ref));
	tmp = get_closest_test(var->e, ref, pt.pos, pt.nb);
	if (tmp.dist != MAX_DIST)
	{
		color_2 = normalize_color(split_color(lux(var->e, tmp)));
		if (var->e->obj[tmp.nb].reflex && *var->depth < 8)
		{
			*var->depth += 1;
			color_2 = mult_color(color_2, normalize_color(
				split_color(get_reflect(var, tmp, rgb_to_int(color_2)))));
		}
		if (var->e->obj[tmp.nb].transp)
			color_2 = mult_color(color_2, normalize_color(split_color(transp(
				var, tmp, rgb_to_int(color_2), pt.pos))));
		color_rgb = mult_color(color_rgb, color_2);
	}
	return (rgb_to_int(color_rgb));
}
