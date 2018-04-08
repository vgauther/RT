/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/06 18:00:13 by fde-souz         ###   ########.fr       */
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
	TTF_Init();
	str = ft_strjoin("RT : Ray Tracer - ", name);
	s->window = SDL_CreateWindow(str, POS_WIN_X, POS_WIN_Y, WIN_X, WIN_Y,
			SDL_WINDOW_ALLOW_HIGHDPI);
	free(str);
	if (s->window == NULL)
		exit(1);
	if ((s->renderer = SDL_CreateRenderer(s->window, -1, 0)) == NULL)
		ft_sdl_error("Renderer error : ", SDL_GetError());
	if ((s->rendu = SDL_CreateRGBSurface(0, SIZE_X, SIZE_Y, 32, 0, 0, 0, 0))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
	if ((s->hud1.s_back = SDL_CreateRGBSurface(0, WIN_X, WIN_Y, 32, 0, 0, 0, 0))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
}

void	display(t_sdl *s, t_env *e)
{
	SDL_Rect 	test = { SIZE_X / 4, SIZE_Y / 8, SIZE_X, SIZE_Y};
	int i;

	i = 0;
	(void)e;
	(void)test;
	SDL_RenderClear(s->renderer);
	recup_cam_to_print(s, e);
	if ((s->texture = SDL_CreateTextureFromSurface(s->renderer, s->rendu))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.t_back, NULL, NULL) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.title.tex, NULL, &s->hud1.cam.title.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.pos_x.tex, NULL, &s->hud1.cam.pos_x.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.pos_y.tex, NULL, &s->hud1.cam.pos_y.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.pos_z.tex, NULL, &s->hud1.cam.pos_z.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.rot_x.tex, NULL, &s->hud1.cam.rot_x.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.rot_y.tex, NULL, &s->hud1.cam.rot_y.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.cam.rot_z.tex, NULL, &s->hud1.cam.rot_z.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.info.tex, NULL, &s->hud1.info.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	while (i != 12)
	{
		if (SDL_RenderCopy(s->renderer, s->tex[s->hud1.bouton[i].i], NULL, &s->hud1.bouton[i].rect) < 0)
			ft_sdl_error("Error copying renderer : ", SDL_GetError());
		i++;
	}
	if (SDL_RenderCopy(s->renderer, s->hud1.t_logo, NULL, &s->hud1.r_logo) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->texture, NULL, &test) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	if (SDL_RenderCopy(s->renderer, s->hud1.save.tex, NULL, &s->hud1.save.rect) < 0)
		ft_sdl_error("Error copying renderer : ", SDL_GetError());
	SDL_RenderPresent(s->renderer);
	//SDL_SaveBMP(s->rendu, "test.bmp");
}

void	mouv(long key, t_env *e, t_sdl *s)
{
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
	raytracing(e, s);
}

t_cam	init_cam(int x, int y, int z)
{
	t_cam c;

	c.pos.x = x;
	c.pos.y = y;
	c.pos.z = z;
	c.rot.x = 0;
	c.rot.y = 0;
	c.rot.z = 0;
	return (c);
}

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
	free(s.hud1.s_back->pixels);
	if (!(e.pixels = (Uint32*)malloc(sizeof(Uint32) * SIZE_X * SIZE_Y)))
		return (0);
	parser(av[1], &e);
	hud_init(&s, &e);
	raytracing(&e, &s);
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
				main_mouse(s.event.button.x, s.event.button.y, &s, &e);
			}
		}
	}
	SDL_DestroyWindow(s.window);
	TTF_Quit();
	SDL_Quit();
	return (0);
}
