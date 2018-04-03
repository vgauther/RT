/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:08:41 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 11:54:38 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_put_pixel_winrend(Uint32 *tab, int x, int y, int color)
{
	tab[(y * SIZE_X + x)] = color;
}

void	ft_put_pixel_hud(Uint32 *tab, int x, int y, int color)
{
	tab[(y * (WIN_X) + x)] = color;
}
