/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/30 18:01:58 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../libft/includes/libft.h"
#include <stdint.h>
#include <time.h>

void	ft_init(t_sdl *s, char *name)
{
	char *str;

	SDL_Init(SDL_INIT_EVERYTHING);
	str = ft_strjoin("RT : Ray Tracer - ", name);
	s->window = SDL_CreateWindow(str, 100, 100, SIZE_X + SIZE_X_2, SIZE_Y + SIZE_Y_2 / 2,
			SDL_WINDOW_ALLOW_HIGHDPI);
	free(str);
	if (s->window == NULL)
		exit(1);
	if ((s->renderer = SDL_CreateRenderer(s->window, -1, 0)) == NULL)
		ft_sdl_error("Renderer error : ", SDL_GetError());
	if ((s->rendu = SDL_CreateRGBSurface(0, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
	if ((s->hud = SDL_CreateRGBSurface(0, SIZE_X + SIZE_X_2, SIZE_Y + SIZE_Y_2 / 2, 32, 0, 0, 0, 0))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
}

void	display(t_sdl *s)
{
	SDL_Rect 	test = { SIZE_X / 4, SIZE_Y / 8, SIZE_X, SIZE_Y };
	SDL_Rect 	test2 = { 15, 15, WIN_X / 7, WIN_Y / 5};
	SDL_Surface *testimg;
	SDL_Texture	*img;

	testimg = SDL_LoadBMP("./img_srcs/rtl.bmp");
	if ((s->texture = SDL_CreateTextureFromSurface(s->renderer, s->rendu))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((img = SDL_CreateTextureFromSurface(s->renderer, testimg))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (SDL_RenderClear(s->renderer) < 0)
		ft_sdl_error("Error clearing renderer : ", SDL_GetError());
	if ((s->texthud = SDL_CreateTextureFromSurface(s->renderer, s->hud))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->texthud, NULL, NULL) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->texture, NULL, &test) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, img, NULL, &test2) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	SDL_RenderPresent(s->renderer);
}

void	mouv(long key, t_env *e, t_sdl *s)
{
	ft_memset(e->pixels, 0, SIZE_X * SIZE_Y * sizeof(Uint32));
	if (key == 79)
		e->ca.pos.x--;
	if (key == 80)
		e->ca.pos.x++;
	if (key == 81)
		e->ca.pos.y--;
	if (key == 82)
		e->ca.pos.y++;
	if (key == 87)
		e->ca.pos.z++;
	if (key == 86)
		e->ca.pos.z--;
	raytracing(e, *s);
}

t_cam	init_cam(int x, int y, int z)
{
	t_cam c;

	c.pos.x = x;
	c.pos.y = y;
	c.pos.z = z;
	return (c);
}

/*
int main(int argc, char ** argv)
{
	int quit = 0;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_Window * window = SDL_CreateWindow("SDL_ttf in SDL2",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
			480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	TTF_Font * font = TTF_OpenFont("2.TTF", 100);
	const char * error = TTF_GetError();
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface * surface = TTF_RenderText_Solid(font,
			"Welcome to Programmer's Ranch", color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
			surface);

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { 0, 0, texW, texH };

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				quit = 1;
				break;
		}

		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
*/
int		main(int ac, char **av)
  {
  t_sdl	s;
  t_env	e;
  int		r;

  r = 1;
  e.ca = init_cam(0, 0, -90);
  if (ac != 2)
  ft_error("\nWrong number of arguments.\n");
  ft_init(&s, av[1]);
  free(s.rendu->pixels);
  free(s.hud->pixels);
  if (!(e.pixels = (Uint32*)malloc(sizeof(Uint32) * SIZE_X * SIZE_Y)))
  return (0);
  if (!(e.hud = (Uint32*)malloc(sizeof(Uint32) * (SIZE_X + SIZE_X_2) *
  (SIZE_Y + SIZE_Y_2 / 2))))
  return (0);
  ft_memset(e.pixels, 0, SIZE_X * SIZE_Y * sizeof(Uint32));
  ft_memset(e.hud, 0, sizeof(Uint32) * (SIZE_X + SIZE_X_2) *
  (SIZE_Y + SIZE_Y_2 / 2));
  parser(av[1], &e);
  hud_init(&s, &e);
  raytracing(&e, s);
  while (r)
  {
  while (SDL_PollEvent(&s.event))
  {
  if ((SDL_QUIT == s.event.type) ||
  (SDL_SCANCODE_ESCAPE == s.event.key.keysym.scancode))
  r = 0;
  else if ((SDL_KEYDOWN == s.event.type))
  mouv(s.event.key.keysym.scancode, &e, &s);
  else if ((SDL_MOUSEBUTTONDOWN == s.event.type))
  {
  printf("%d %d\n", s.event.button.x, s.event.button.y);
  main_mouse(s.event.button.x, s.event.button.y, &s, &e);
  display(&s);
  }
  }
  }
  SDL_DestroyWindow(s.window);
  SDL_Quit();
  return (0);
  }
