/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 17:42:46 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		empty_rect(t_rect b, t_env *e, int t, int color)
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

SDL_Rect	init_sdl_rect(int x, int y, int w, int h)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}

void		recup_cam_to_print(t_sdl *s, t_env *e)
{
	(void)e;
	print_text("CAMERA", s->font.color[1], s, &s->hud.cam.title);
}

void		hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	t_rect	r2;

	init_font(s);
	s->hud.s_logo = SDL_LoadBMP("./img_srcs/rtl.bmp");
	s->hud.r_logo = init_sdl_rect(WIN_X / 100, 0, (SIZE_X / 4) - (WIN_X / 100) ,SIZE_Y / 4);
	if ((s->hud.t_logo = SDL_CreateTextureFromSurface(s->renderer, s->hud.s_logo))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (!(e->hud = (Uint32*)malloc(sizeof(Uint32) * WIN_X * WIN_Y)))
		ft_error("MALLOC ERROR");
	r2 = init_rect(WIN_X / 100, 200, (SIZE_X / 4) - (WIN_X / 100), 400);
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	print_rect(r1, e, 1, COLOR_BACK);
	empty_rect(r2, e, 1, WHITE);
	r1 = init_rect(WIN_X / 67, 190, (SIZE_X / 4) - (WIN_X / 70), 210);
	print_rect(r1, e, 1, COLOR_BACK);
	if ((s->hud.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	s->hud.s_back->pixels = e->hud;
	//recup_cam_to_print(s, e);
	/*init_font(s);
	if (SDL_RenderCopy(s->renderer, img, NULL, &test) < 0)
			ft_sdl_error("Error copying renderer : ", SDL_GetError());
	print_text("COUCOU", s->font.color[3], s);
	s->hud->pixels = e->hud;*/
}
