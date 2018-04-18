/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:19:57 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/18 13:15:56 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	open_texture(t_sdl *s)
{
	SDL_Surface	*surfac[17];
	int			i;

	i = -1;
	surfac[0] = SDL_LoadBMP("./img_srcs/-.bmp");
	surfac[1] = SDL_LoadBMP("./img_srcs/+.bmp");
	surfac[2] = SDL_LoadBMP("./img_srcs/-2.bmp");
	surfac[3] = SDL_LoadBMP("./img_srcs/+2.bmp");
	surfac[4] = SDL_LoadBMP("./img_srcs/m.bmp");
	surfac[5] = SDL_LoadBMP("./img_srcs/m2.bmp");
	surfac[6] = SDL_LoadBMP("./img_srcs/blwh.bmp");
	surfac[7] = SDL_LoadBMP("./img_srcs/blwh2.bmp");
	surfac[8] = SDL_LoadBMP("./img_srcs/sep.bmp");
	surfac[9] = SDL_LoadBMP("./img_srcs/sep2.bmp");
	surfac[10] = SDL_LoadBMP("./img_srcs/pipette.bmp");
	surfac[11] = SDL_LoadBMP("./img_srcs/pipette2.bmp");
	surfac[12] = SDL_LoadBMP("./img_srcs/sphere.bmp");
	surfac[13] = SDL_LoadBMP("./img_srcs/cone.bmp");
	surfac[14] = SDL_LoadBMP("./img_srcs/cylindre.bmp");
	surfac[15] = SDL_LoadBMP("./img_srcs/plan.bmp");
	surfac[16] = SDL_LoadBMP("./img_srcs/color.bmp");
	while (++i < 17)
	{
		if (!(s->tex[i] = SDL_CreateTextureFromSurface(s->renderer, surfac[i])))
			ft_sdl_error("Texture error : ", SDL_GetError());
		SDL_FreeSurface(surfac[i]);
	}
}
