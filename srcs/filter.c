/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/11 16:07:26 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

Uint32	sepia(Uint32 color)
{
	t_color colorin;
	double	tr;
	double	tg;
	double	tb;

	colorin = split_color(color);
	tr = 0.393 * colorin.r + 0.769 * colorin.g + 0.189 * colorin.b;
	tg = 0.349 * colorin.r + 0.686 * colorin.g + 0.168 * colorin.b;
	tb = 0.272 * colorin.r + 0.534 * colorin.g + 0.131 * colorin.b;
	colorin.r = tr > 255 ? 255 : tr;
	colorin.g = tg > 255 ? 255 : tg;
	colorin.b = tb > 255 ? 255 : tb;
	return (((int)colorin.r * 256 * 256)
	+ ((int)colorin.g * 256) + (int)colorin.b);
}

Uint32	blackwhite(Uint32 color)
{
	t_color colorin;
	double	moy;

	colorin = split_color(color);
	moy = (colorin.r + colorin.g + colorin.b) / 3;
	colorin.r = moy;
	colorin.g = moy;
	colorin.b = moy;
	return ((((int)colorin.r * 256 * 256)
	+ ((int)colorin.g * 256) + (int)colorin.b));
}

Uint32	filtre(t_sdl *s, Uint32 color)
{
	if (s->hud1.filter_token.bw == 1)
		color = blackwhite(color);
	if (s->hud1.filter_token.sep == 2)
		color = sepia(color);
	return (color);
}
