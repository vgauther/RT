/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_create_bouton.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:38:52 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/24 14:39:29 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		create_bouton_cam(t_sdl *s)
{
	int x;
	int y;
	int i;
	int t;

	i = 0;
	x = 70;
	y = 265;
	t = 0;
	while (i != 12)
	{
		s->hud1.bouton[i].i = t;
		s->hud1.bouton[i].rect = init_sdl_rect(x, y, 20, 20);
		i++;
		y += 40;
		if (i == 3 || i == 9)
		{
			t = 1;
			x -= 25;
		}
		t = i == 6 ? 0 : t;
		x = i == 6 ? 165 : x;
		if (i == 3 || i == 9 || i == 6)
			y = 265;
	}
}

void	create_bouton_tool_bar(t_sdl *s)
{
	s->hud1.bouton[12].i = 8;
	s->hud1.bouton[12].rect = init_sdl_rect(SIZE_X / 2 + COL4,
		SIZE_Y / 16 - 20, 40, 40);
	s->hud1.bouton[13].i = 6;
	s->hud1.bouton[13].rect = init_sdl_rect(SIZE_X / 2 + COL4 + 60,
		SIZE_Y / 16 - 20, 40, 40);
	s->hud1.bouton[14].i = 4;
	s->hud1.bouton[14].rect = init_sdl_rect(COL4 + 60, SIZE_Y / 16 - 20,
		40, 40);
	s->hud1.bouton[15].i = 10;
	s->hud1.bouton[15].rect = init_sdl_rect(COL4 + 120, SIZE_Y / 16 - 20,
		40, 40);
	s->hud1.bouton[16].i = 1;
	s->hud1.bouton[16].rect = init_sdl_rect(COL4 + 180, SIZE_Y / 16 - 20,
			40, 40);
	s->hud1.bouton[17].i = 1;
	s->hud1.bouton[17].rect = init_sdl_rect(SIZE_X - 10,
		SIZE_Y / 16 - 10, 20, 20);
	s->hud1.bouton[18].i = 0;
	s->hud1.bouton[18].rect = init_sdl_rect(SIZE_X + 15,
		SIZE_Y / 16 - 10, 20, 20);
}
