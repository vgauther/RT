/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pipette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:21:26 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/04 11:28:27 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	mouse_pipette_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= COL4 + 120 && x <= COL4 + 160)
	{
		if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
		{
			s->hud1.bouton[15].i = s->hud1.bouton[15].i == 11 ? 10 : 11;
			s->hud1.pipette = s->hud1.pipette == 1 ? 0 : 1;
			if (s->hud1.tok.obj_select != -1)
				s->hud1.tok.change_color_obj = s->hud1.pipette == 1 ? 1 : 0;
			display(s, e);
		}
	}
}

void	mouse_pipette_color(int x, int y, t_sdl *s, t_env *e)
{
	Uint32	color;
	char	*tab;
	int		bpp;

	bpp = s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w;
	x -= (WIN_X / 2) - s->hud1.color_selector_surf->w / 2;
	y -= (WIN_Y / 2) - s->hud1.color_selector_surf->h / 2;
	if (x >= 0 && x <= s->hud1.color_selector_surf->w)
	{
		if (y >= 0 && y <= s->hud1.color_selector_surf->h)
		{
			tab = (char *)s->hud1.color_selector_surf->pixels;
			color = tab[x * bpp + s->hud1.color_selector_surf->w * bpp * y];
			color += tab[x * bpp + s->hud1.color_selector_surf->w * bpp * y + 1]
			* 256;
			color += tab[x * bpp + s->hud1.color_selector_surf->w * bpp * y + 2]
			* 256 * 256;
			s->hud1.color = (int)color;
			print_rect(init_rect(s->hud1.bouton[15].rect.x + 110,
			s->hud1.bouton[15].rect.y, 40, 40), e, 1, color);
			actualize_background(s, e);
			display(s, e);
		}
	}
}
