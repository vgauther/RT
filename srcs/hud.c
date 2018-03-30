/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/29 16:35:17 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define WIN_X (SIZE_X + SIZE_X_2)
#define WIN_Y (SIZE_Y + SIZE_Y_2 / 2)

void	empty_rect(t_rect b, t_env *e, int t, int color)
{
	int save;
	int save2;

	if (b.y_begin > b.y_end || b.x_begin > b.x_end)
		ft_error("\nbouton error\n");
	save = b.x_begin;
	save2 = b.y_begin;
	while (b.y_begin <= b.y_end)
	{
		b.x_begin = save;
		while (b.x_begin < b.x_end && (b.y_begin == b.y_end || b.y_begin == save2))
		{
			t == 1 ? ft_put_pixel_hud(e->hud, b.x_begin, b.y_begin, color) :
			ft_put_pixel_winrend(e->pixels, b.x_begin, b.y_begin, color);
			b.x_begin++;
		}
		t == 1 ? ft_put_pixel_hud(e->hud, b.x_begin, b.y_begin, color) :
		ft_put_pixel_winrend(e->pixels, b.x_begin, b.y_begin, color);
		t == 1 ? ft_put_pixel_hud(e->hud, b.x_end, b.y_begin, color) :
		ft_put_pixel_winrend(e->pixels, b.x_end, b.y_begin, color);
		b.y_begin++;
	}
}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	t_rect	r2;
	t_rect	r3;
	int		color;

	color = 0x3f3f3f;
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	r2 = init_rect(0, 0, WIN_X / 10 + 100, WIN_Y / 10 + 100);
	r3 = init_rect(0, 0, SIZE_X + SIZE_X_2, SIZE_Y + SIZE_Y_2 / 2);
	print_rect(r1, e, 1, color);
	empty_rect(r2, e, 1, 0x00FF00);
	s->hud->pixels = e->hud;
}
