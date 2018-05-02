/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:19:57 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 21:09:55 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static SDL_Surface		**open_texture3(SDL_Surface **surfac)
{
	surfac[16] = SDL_LoadBMP("./img_srcs/selector.bmp");
	surfac[17] = SDL_LoadBMP("./img_srcs/ok.bmp");
	surfac[18] = SDL_LoadBMP("./img_srcs/ok2.bmp");
	surfac[19] = SDL_LoadBMP("./img_srcs/loadwin20.bmp");
	surfac[20] = SDL_LoadBMP("./img_srcs/loadwin50.bmp");
	surfac[21] = SDL_LoadBMP("./img_srcs/loadwin75.bmp");
	surfac[22] = SDL_LoadBMP("./img_srcs/loadwin100.bmp");
	surfac[23] = SDL_LoadBMP("./img_srcs/load20.bmp");
	surfac[24] = SDL_LoadBMP("./img_srcs/load50.bmp");
	surfac[25] = SDL_LoadBMP("./img_srcs/load75.bmp");
	surfac[26] = SDL_LoadBMP("./img_srcs/load100.bmp");
	surfac[27] = SDL_LoadBMP("./img_srcs/30sticky.bmp");
	surfac[28] = SDL_LoadBMP("./img_srcs/50sticky.bmp");
	surfac[29] = SDL_LoadBMP("./img_srcs/80sticky.bmp");
	surfac[30] = SDL_LoadBMP("./img_srcs/100sticky.bmp");
	surfac[31] = SDL_LoadBMP("./img_srcs/grey.bmp");
	surfac[32] = SDL_LoadBMP("./img_srcs/white.bmp");
	return (surfac);
}

static SDL_Surface		**open_texture2(void)
{
	SDL_Surface **surfac;

	if (!(surfac = malloc(sizeof(SDL_Surface *) * 33)))
		ft_error("\n MALLOC ERROR : open_texture2\n\n");
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
	surfac = open_texture3(surfac);
	return (surfac);
}

void					open_texture(t_sdl *s)
{
	SDL_Surface	**surfac;
	int			i;

	i = -1;
	surfac = open_texture2();
	while (++i < 33)
	{
		if (!(s->tex[i] = SDL_CreateTextureFromSurface(s->renderer, surfac[i])))
			ft_sdl_error("Texture error : ", SDL_GetError());
		SDL_FreeSurface(surfac[i]);
	}
	free(surfac);
}
