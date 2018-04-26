/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_color_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:02:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/26 14:05:19 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_color_text(t_sdl *s)
{
	print_text(ft_strdup("Color"), s->font.color[1], s, &s->hud1.color_text);
	s->hud1.color_text.rect = init_sdl_rect(SIZE_X + COL4 + 80, WIN_Y / 2 +
		LINE + 100 + 10, 100, 20);
}

void	init_color_selector(t_sdl *s)
{
	s->hud1.color_selector = init_sdl_rect((WIN_X / 2) - 128, (WIN_Y / 2)
	- 128, 256, 256);
	s->hud1.color_selector_surf = SDL_LoadBMP("./img_srcs/selector.bmp");
}
