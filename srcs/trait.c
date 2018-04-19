/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 00:18:41 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/20 00:18:46 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	horizontal_trait(t_vec p1, t_vec p2, int color, t_env *e)
{
	if (p1.x > p2.x)
		ft_error("\nhorizontal_trait error\n");
	while (p1.x != p2.x)
	{
		ft_put_pixel_hud(e->hud, p1.x, p1.y, color);
		p1.x++;
	}
}

void	vertical_trait(t_vec p1, t_vec p2, int color, t_env *e)
{
	if (p1.y > p2.y)
		ft_error("\nvertical_trait error\n");
	while (p1.y != p2.y)
	{
		ft_put_pixel_hud(e->hud, p1.x, p1.y, color);
		p1.y++;
	}
}
