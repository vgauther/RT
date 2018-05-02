/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_color2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:39:24 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 18:44:51 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		normalize_color(t_color in)
{
	in.r /= 255;
	in.g /= 255;
	in.b /= 255;
	return (in);
}

t_color		color_init(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

Uint32		proces_color(t_env *e, t_sdl *s, t_inter pt)
{
	Uint32				color;
	t_reflect_transp	var;
	int					depth;

	depth = 0;
	var.e = e;
	var.depth = &depth;
	color = lux(e, pt);
	if (e->obj[pt.nb].reflex)
		color = get_reflect(&var, pt, color);
	depth = 0;
	if (e->obj[pt.nb].transp)
		color = transp(&var, pt, color, e->ca.pos);
	color = filtre(s, color);
	return (color);
}
