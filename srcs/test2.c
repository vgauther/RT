/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/02/27 14:46:32 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../libft/includes/libft.h"
#include <stdint.h>
#include <time.h>

int main(void)
{
	int running = 1;
	int a;
	int b;
	int	x;
	int	y;
	SDL_Event event;
	Uint32 pixels[800 * 600];
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Surface *surface;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hello SDL World", 0, 0, 800, 600
	, SDL_WINDOW_ALLOW_HIGHDPI);
	if ((renderer = SDL_CreateRenderer(window, -1, 0)) == NULL)
		ft_error("Renderer error : ", SDL_GetError());
	if ((surface = SDL_CreateRGBSurface(0, 800, 600, 32, 0, 0, 0, 0)) == NULL)
	    ft_error("Surface error : ", SDL_GetError());
	surface->pixels = pixels;
	ft_memset(pixels, 0, 800 * 600 * sizeof(Uint32));
	memset(pixels, 0, 800 * 600 * sizeof(Uint32));
	if (NULL == window)
		exit(1);
	a = clock();
	x = 400;
	while (x < 600)
	{
		y = 300;
		while (y < 500)
		{
			pixels[(y * 800 + x)] = 0x0000ff;
			y++;
		}
		x++;
	}
	if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
		ft_error("Texture error : ", SDL_GetError());
	if (SDL_RenderClear(renderer) < 0)
		ft_error("Error clearing renderer : ", SDL_GetError());
	if (SDL_RenderCopy(renderer, texture, NULL, NULL) < 0)
		ft_error("Error copying renderer : ", SDL_GetError());
	SDL_RenderPresent(renderer);
	b = clock();
	printf("%d\n", b - a);
	while (running)
	{
		while (SDL_PollEvent(&event))
			if ((SDL_QUIT == event.type) || (SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				running = 0;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
