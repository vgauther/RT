/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:19:57 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 11:23:20 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	open_texture(t_sdl *s)
{
	SDL_Surface *surface[6];
	int i;

	i = 0;
	surface[0] = SDL_LoadBMP("./img_srcs/-.bmp");
	surface[1] = SDL_LoadBMP("./img_srcs/+.bmp");
	surface[2] = SDL_LoadBMP("./img_srcs/-2.bmp");
	surface[3] = SDL_LoadBMP("./img_srcs/+2.bmp");
	surface[4] = SDL_LoadBMP("./img_srcs/m.bmp");
	surface[5] = SDL_LoadBMP("./img_srcs/m2.bmp");
	if ((s->tex[0] = SDL_CreateTextureFromSurface(s->renderer, surface[0])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[1] = SDL_CreateTextureFromSurface(s->renderer, surface[1])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[2] = SDL_CreateTextureFromSurface(s->renderer, surface[2])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[3] = SDL_CreateTextureFromSurface(s->renderer, surface[3])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[4] = SDL_CreateTextureFromSurface(s->renderer, surface[4])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[5] = SDL_CreateTextureFromSurface(s->renderer, surface[5])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	while (i != 6)
	{
		SDL_FreeSurface(surface[i]);
		i++;
	}
}
