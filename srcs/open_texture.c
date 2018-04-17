/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:19:57 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/17 11:42:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	open_texture(t_sdl *s)
{
	SDL_Surface *surface[17];
	int i;

	i = 0;
	surface[0] = SDL_LoadBMP("./img_srcs/-.bmp");
	surface[1] = SDL_LoadBMP("./img_srcs/+.bmp");
	surface[2] = SDL_LoadBMP("./img_srcs/-2.bmp");
	surface[3] = SDL_LoadBMP("./img_srcs/+2.bmp");
	surface[4] = SDL_LoadBMP("./img_srcs/m.bmp");
	surface[5] = SDL_LoadBMP("./img_srcs/m2.bmp");
	surface[6] = SDL_LoadBMP("./img_srcs/blwh.bmp");
	surface[7] = SDL_LoadBMP("./img_srcs/blwh2.bmp");
	surface[8] = SDL_LoadBMP("./img_srcs/sep.bmp");
	surface[9] = SDL_LoadBMP("./img_srcs/sep2.bmp");
	surface[10] = SDL_LoadBMP("./img_srcs/pipette.bmp");
	surface[11] = SDL_LoadBMP("./img_srcs/pipette2.bmp");
	surface[12] = SDL_LoadBMP("./img_srcs/sphere.bmp");
	surface[13] = SDL_LoadBMP("./img_srcs/cone.bmp");
	surface[14] = SDL_LoadBMP("./img_srcs/cylindre.bmp");
	surface[15] = SDL_LoadBMP("./img_srcs/plan.bmp");
	surface[16] = SDL_LoadBMP("./img_srcs/color.bmp");
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
	if ((s->tex[6] = SDL_CreateTextureFromSurface(s->renderer, surface[6])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[7] = SDL_CreateTextureFromSurface(s->renderer, surface[7])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[8] = SDL_CreateTextureFromSurface(s->renderer, surface[8])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[9] = SDL_CreateTextureFromSurface(s->renderer, surface[9])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[10] = SDL_CreateTextureFromSurface(s->renderer, surface[10])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[11] = SDL_CreateTextureFromSurface(s->renderer, surface[11])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[12] = SDL_CreateTextureFromSurface(s->renderer, surface[12])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[13] = SDL_CreateTextureFromSurface(s->renderer, surface[13])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[14] = SDL_CreateTextureFromSurface(s->renderer, surface[14])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[15] = SDL_CreateTextureFromSurface(s->renderer, surface[15])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[16] = SDL_CreateTextureFromSurface(s->renderer, surface[16])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	while (i != 17)
	{
		SDL_FreeSurface(surface[i]);
		i++;
	}
}
