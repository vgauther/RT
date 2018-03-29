/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/29 14:07:06 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	int		color;

	color = 0xFC00FC;
	r1 = init_rect(0, 0, 700, 700);
	print_rect(r1, e, 1, color);
	s->hud->pixels = e->hud;
}
