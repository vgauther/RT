/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 12:14:51 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	empty_rect(t_rect b, t_env *e, int t, int color)
{
	int save;
	int save2;

	if (b.y_begin > b.y_end || b.x_begin > b.x_end)
		ft_error("\nrect error\n");
	save = b.x_begin;
	save2 = b.y_begin;
	while (b.y_begin <= b.y_end)
	{
		b.x_begin = save;
		while (b.x_begin < b.x_end && (b.y_begin == b.y_end || b.y_begin == save2))
		{
			t == 1 ? ft_put_pixel_hud(e->hud, b.x_begin, b.y_begin, color) :
			ft_put_pixel_winrend(e->pixels, b.x_begin, b.y_begin, color);
			b.x_begin++;
		}
		t == 1 ? ft_put_pixel_hud(e->hud, b.x_begin, b.y_begin, color) :
		ft_put_pixel_winrend(e->pixels, b.x_begin, b.y_begin, color);
		t == 1 ? ft_put_pixel_hud(e->hud, b.x_end, b.y_begin, color) :
		ft_put_pixel_winrend(e->pixels, b.x_end, b.y_begin, color);
		b.y_begin++;
	}
}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	//t_rect	r2;
	//SDL_Surface *testimg;
	//SDL_Texture	*img;
	//SDL_Rect 	test = { 0, 200 / 8, 400, 400 };

	//int		color;
	//testimg = SDL_LoadBMP("./img_srcs/rtl.bmp");

	//color = 0x3f3f3f;
	//if ((img = SDL_CreateTextureFromSurface(s->renderer, testimg))
		//	== NULL)
		//ft_sdl_error("Texture error : ", SDL_GetError());
	if (!(e->hud = (Uint32*)malloc(sizeof(Uint32) * WIN_X * WIN_Y)))
		ft_error("MALLOC ERROR");
	//ft_memset(e->hud, 255, sizeof(Uint32) * WIN_X * WIN_Y);
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	print_rect(r1, e, 1, 0x202225);
	s->hud->pixels = e->hud;
	if ((s->texthud = SDL_CreateTextureFromSurface(s->renderer, s->hud)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	//r2 = init_rect(800, 180, 930, 350);
	//empty_rect(r2, e, 1, 0xFFFFFF);
	/*init_font(s);
	if (SDL_RenderCopy(s->renderer, img, NULL, &test) < 0)
			ft_sdl_error("Error copying renderer : ", SDL_GetError());
	print_text("COUCOU", s->font.color[3], s);
	s->hud->pixels = e->hud;*/
}
