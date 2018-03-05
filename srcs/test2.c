/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/05 12:25:47 by vgauther         ###   ########.fr       */
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

void mouv(long key, t_cam *c, t_obj o, t_sdl sdl)
{
	printf("coucou :%ld\n", key);
	if (key == 79)
		c->xr++;
	if (key == 80)
		c->xr--;
	if (key == 81)
		c->yr++;
	if (key == 82)
		c->yr--;
	if (key == 87)
		c->zr++;
	if (key == 86)
		c->zr--;
	printf("%f | %f | %f\n", c->xr, c->yr, c->zr);
	raytracing(o, sdl, *c);
}

int		main(int ac, char **av)
{
	int running;
	t_sdl s;
	t_obj obj;
	t_cam c;

	c.xr = 0;
	c.yr = 0;
	c.zr = 0;
	if (ac != 2)
		usage();
	running = 1;
	ft_init(&s);
	free(s.surface->pixels);
	s.surface->pixels = s.pixels;
	ft_memset(s.pixels, 255, SIZE_X * SIZE_Y * sizeof(Uint32));
	//draw(s.surface->pixels);
	//display(&s);
	obj = parser(av[1]);
	raytracing(obj, s, c);
	while (running)
	{
		while (SDL_PollEvent(&s.event))
		{
			printf("%s\n", "dedans");
			if(s.event.key.keysym.scancode == SDLK_MINUS)
				(void)s;
			mouv(s.event.key.keysym.scancode, &c, obj, s);
			if ((SDL_QUIT == s.event.type) || (SDL_SCANCODE_ESCAPE == s.event.key.keysym.scancode))
				running = 0;
		}
	}
	SDL_DestroyWindow(s.window);
	SDL_Quit();
	return (0);
}
