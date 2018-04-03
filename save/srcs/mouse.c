/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:51:45 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 16:11:07 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	print_bouton(t_bouton b, t_env *e)
{
	int save;

	if (b.y_begin > b.y_end || b.x_begin > b.x_end)
		ft_error("\nbouton error\n");
	save = b.x_begin;
	while (b.y_begin < b.y_end)
	{
		b.x_begin = save;
		while (b.x_begin < b.x_end)
		{
			ft_put_pixel_hud(e->hud, b.x_begin, b.y_begin, 0xFF0000);
			b.x_begin++;
		}
		b.y_begin++;
	}
}

void	main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	t_bouton b;

	b.x_begin = 0;
	b.y_begin = 0;
	b.x_end = 200;
	b.y_end = 200;
	(void)mouse_x;
	(void)mouse_y;
	if (mouse_x > b.x_begin && mouse_x < b.x_end && mouse_y >
		b.y_begin && mouse_y < b.y_end)
		print_bouton(b, e);
	s->hud.s_back->pixels = e->hud;
}
