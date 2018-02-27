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

void	ft_init(t_sdl *s)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	s->window = SDL_CreateWindow("Hello SDL World", 0, 0, 800, 600,
		SDL_WINDOW_ALLOW_HIGHDPI);
	if (s->window == NULL)
		exit(1);
	if ((s->renderer = SDL_CreateRenderer(s->window, -1, 0)) == NULL)
		ft_error("Renderer error : ", SDL_GetError());
	if ((s->surface = SDL_CreateRGBSurface(0, 800, 600, 32, 0, 0, 0, 0))
		== NULL)
	    ft_error("Surface error : ", SDL_GetError());
}

void	display(t_sdl *s)
{
	if ((s->texture = SDL_CreateTextureFromSurface(s->renderer, s->surface)) == NULL)
		ft_error("Texture error : ", SDL_GetError());
	if (SDL_RenderClear(s->renderer) < 0)
		ft_error("Error clearing renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->texture, NULL, NULL) < 0)
		ft_error("Error copying renderer : ", SDL_GetError());
	SDL_RenderPresent(s->renderer);
}

void	draw(Uint32 *pixels)
{
	int x;
	int y;

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
}

int		main(void)
{
	int running = 1;
	int a;
	int b;
	t_sdl s;
	Uint32 pixels[800 * 600];

	ft_init(&s);
	s.surface->pixels = pixels;
	ft_memset(pixels, 0, 800 * 600 * sizeof(Uint32));
	memset(pixels, 0, 800 * 600 * sizeof(Uint32));
	a = clock();
	draw(s.surface->pixels);
	display(&s);
	b = clock();
	printf("%d\n", b - a);
	while (running)
	{
		while (SDL_PollEvent(&s.event))
			if ((SDL_QUIT == s.event.type) || (SDL_SCANCODE_ESCAPE == s.event.key.keysym.scancode))
				running = 0;
	}
	SDL_DestroyWindow(s.window);
	SDL_Quit();
	return (0);
}