/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/05 16:11:27 by fde-souz         ###   ########.fr       */
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
	s->hud1.cam.title.rect = init_sdl_rect(40, 190, 344/2, 96/3);
	print_text("Camera", s->font.color[1], s, &s->hud1.cam.title);
	s->hud1.cam.pos_x.rect = init_sdl_rect(170, 250, 17, 10);
	print_text(ft_itoa(e->ca.pos.x), s->font.color[1], s, &s->hud1.cam.pos_x);
	s->hud1.cam.pos_y.rect = init_sdl_rect(170, 270, 17, 10);
	print_text(ft_itoa(e->ca.pos.y), s->font.color[1], s, &s->hud1.cam.pos_y);
	s->hud1.cam.pos_z.rect = init_sdl_rect(170, 290, 17, 10);
	print_text(ft_itoa(e->ca.pos.z), s->font.color[1], s, &s->hud1.cam.pos_z);
	s->hud1.cam.rot_x.rect = init_sdl_rect(210, 250, 17, 10);
	print_text(ft_itoa(e->ca.rot.x), s->font.color[1], s, &s->hud1.cam.rot_x);
	s->hud1.cam.rot_y.rect = init_sdl_rect(210, 270, 17, 10);
	print_text(ft_itoa(e->ca.rot.y), s->font.color[1], s, &s->hud1.cam.rot_y);
	s->hud1.cam.rot_z.rect = init_sdl_rect(210, 290, 17, 10);
	print_text(ft_itoa(e->ca.rot.z), s->font.color[1], s, &s->hud1.cam.rot_z);
	/*print_text(ft_itoa(e->ca.pos.y), s->font.color[1], s, &s->hud1.cam.pos_y);
	print_text(ft_itoa(e->ca.pos.z), s->font.color[1], s, &s->hud1.cam.pos_z);
	print_text(ft_itoa(e->ca.pos.x), s->font.color[1], s, &s->hud1.cam.rot_x);
	print_text(ft_itoa(e->ca.pos.x), s->font.color[1], s, &s->hud1.cam.rot_y);
	print_text(ft_itoa(e->ca.pos.x), s->font.color[1], s, &s->hud1.cam.rot_z);*/


}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	t_rect	r2;
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
	init_font(s);
	s->hud1.s_logo = SDL_LoadBMP("./img_srcs/rtl.bmp");
	s->hud1.r_logo = init_sdl_rect(WIN_X / 100, 0, (SIZE_X / 4) - (WIN_X / 100) ,SIZE_Y / 4);
	if ((s->hud1.t_logo = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_logo))
		== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (!(e->hud = (Uint32*)malloc(sizeof(Uint32) * WIN_X * WIN_Y)))
		ft_error("MALLOC ERROR");
	//ft_memset(e->hud, 255, sizeof(Uint32) * WIN_X * WIN_Y);
	r2 = init_rect(WIN_X / 100, 200, (SIZE_X / 4) - (WIN_X / 100), 400);
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	print_rect(r1, e, 1, COLOR_BACK);
	empty_rect(r2, e, 1, WHITE);
	r1 = init_rect(WIN_X / 67, 190, (SIZE_X / 4) - (WIN_X / 70), 210);
	print_rect(r1, e, 1, COLOR_BACK);
	s->hud1.s_back->pixels = e->hud;
	if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	//r2 = init_rect(800, 180, 930, 350);
	//empty_rect(r2, e, 1, 0xFFFFFF);
	/*init_font(s);
	if (SDL_RenderCopy(s->renderer, img, NULL, &test) < 0)
			ft_sdl_error("Error copying renderer : ", SDL_GetError());
	print_text("COUCOU", s->font.color[3], s);
	s->hud->pixels = e->hud;*/
}
