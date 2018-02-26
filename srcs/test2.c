/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/02/26 18:27:17 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include <stdint.h>
#include <time.h>

int main(void)
{
	int running = 1;
	int a;
	int b;
	SDL_Event event;
	Uint32 pixels[800 * 600];
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Surface *surface;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hello SDL World", 0, 0, 800, 600
	, SDL_WINDOW_ALLOW_HIGHDPI);
	renderer = SDL_CreateRenderer(window, -1, 0);
	surface = SDL_CreateRGBSurface(0, 800, 600, 32, 0, 0, 0, 0);
	surface->pixels = pixels;
	memset(pixels, 255, 800 * 600 * sizeof(Uint32));
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (NULL == window)
		exit(1);
	a = clock();
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	b = clock();
	printf("%d\n", b - a);
	while (running)
	{
		while (SDL_PollEvent(&event))
			if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				running = 0;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
