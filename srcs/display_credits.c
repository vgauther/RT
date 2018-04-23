/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_credits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:45:57 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 13:46:31 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	display_credits(t_sdl *s)
{
	if ((SDL_RenderCopy(s->renderer, s->hud1.credits.title.tex, NULL,
		&s->hud1.credits.title.rect)) < 0)
		ft_error("\nRender copy Error\n");
	if ((SDL_RenderCopy(s->renderer, s->hud1.credits.names.tex, NULL,
		&s->hud1.credits.names.rect)) < 0)
		ft_error("\nRender copy Error\n");
}
