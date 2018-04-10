/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/10 14:07:57 by vgauther         ###   ########.fr       */
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
	s->hud1.cam.title.rect = init_sdl_rect(40, 190, 344 / 2, 96 / 3);
	print_text(ft_strdup("Camera"), s->font.color[1], s, &s->hud1.cam.title);
	s->hud1.cam.pos_x.rect = init_sdl_rect(105, 270, 17, 10);
	print_text(ft_itoa(e->ca.pos.x), s->font.color[1], s, &s->hud1.cam.pos_x);
	s->hud1.cam.pos_y.rect = init_sdl_rect(105, 310, 17, 10);
	print_text(ft_itoa(e->ca.pos.y), s->font.color[1], s, &s->hud1.cam.pos_y);
	s->hud1.cam.pos_z.rect = init_sdl_rect(105, 350, 17, 10);
	print_text(ft_itoa(e->ca.pos.z), s->font.color[1], s, &s->hud1.cam.pos_z);
	s->hud1.cam.rot_x.rect = init_sdl_rect(200, 270, 17, 10);
	print_text(ft_itoa(e->ca.rot.x), s->font.color[1], s, &s->hud1.cam.rot_x);
	s->hud1.cam.rot_y.rect = init_sdl_rect(200, 310, 17, 10);
	print_text(ft_itoa(e->ca.rot.y), s->font.color[1], s, &s->hud1.cam.rot_y);
	s->hud1.cam.rot_z.rect = init_sdl_rect(200, 350, 17, 10);
	print_text(ft_itoa(e->ca.rot.z), s->font.color[1], s, &s->hud1.cam.rot_z);
}

void		create_bouton(t_sdl *s)
{
	int x;
	int y;
	int i;
	int t;

	i = 0;
	x = 70;
	y = 265;
	t = 0;
	while (i != 12)
	{
		s->hud1.bouton[i].i = t;
		i++;
		if (i == 3 || i== 9)
			t = 1;
		else if(i == 6)
			t = 0;
	}
	i = 0;
	while (i != 12)
	{
		s->hud1.bouton[i].rect = init_sdl_rect(x, y, 20, 20);
		i++;
		y += 40;
		if (i ==3||i == 9)
			x -= 25;
		if (i == 6)
			x = 165;
		if (i == 3 || i == 9 || i == 6)
			y = 265;
	}
}


void	horizontal_trait(t_point p1, t_point p2, int color, t_env *e)
{
	if (p1.x > p2.x)
		ft_error("\nhorizontal_trait error\n");
	while (p1.x != p2.x)
	{
		ft_put_pixel_hud(e->hud, p1.x, p1.y, color);
		p1.x++;
	}
}

void	vertical_trait(t_point p1, t_point p2, int color, t_env *e)
{
	if (p1.y > p2.y)
		ft_error("\nvertical_trait error\n");
	while (p1.y != p2.y)
	{
		ft_put_pixel_hud(e->hud, p1.x, p1.y, color);
		p1.y++;
	}
}

void	init_info_messages(t_sdl *s)
{
	s->hud1.mess = malloc(sizeof(char *) * 5);
	s->hud1.mess[0] = ft_strdup("Last   Info   :   RT   succesfully   launched.");
	s->hud1.mess[1] = ft_strdup("Last  Info  :  Camera  just  mooved  on  x  axis");
	s->hud1.mess[2] = ft_strdup("Last  Info  :  Camera  just  mooved  on  y  axis");
	s->hud1.mess[3] = ft_strdup("Last  Info  :  Camera  just  mooved  on  z  axis");
	s->hud1.mess[4] = ft_strdup("Last  Info  :  Your  work  has  been  saved.");

}

void	ornement(SDL_Rect p, int color, int size, t_env *e)
{
	t_point p1;
	t_point p2;
	int l;

	l = p.h / 2 + p.y;
	p2.y = l;
	p1.y = l;
	p1.x = p.x - size;
	p2.x = p.x - 10;
	horizontal_trait(p1, p2, color, e);
	p1.x = p.x + p.w + 10;
	p2.x = p.x + p.w + size;
	horizontal_trait(p1, p2, color, e);
}

void 	bloc_save(t_env *e, t_sdl *s)
{
	t_point p1;
	t_point p2;
	t_rect	r1;

	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 9, 0);
	p2 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 9, SIZE_Y / 8);
	vertical_trait(p1, p2, WHITE, e);
	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 9 - 150, 0);
	p2 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 9 - 150, SIZE_Y / 8);
	vertical_trait(p1, p2, WHITE, e);
	r1 = init_rect(SIZE_X / 4 + SIZE_X - 110, SIZE_Y / 17, SIZE_X / 4 + SIZE_X - 20, SIZE_Y / 12);
	print_rect(r1, e, 1, WHITE);
	print_text(ft_strdup("save"), s->font.color[4], s, &s->hud1.save);
	s->hud1.save.rect = init_sdl_rect(SIZE_X / 4 + SIZE_X - 90, 10 ,50, 15);
	ornement(s->hud1.save.rect, WHITE, 20, e);
}

void	bloc_credits(t_env *e, t_sdl *s)
{
	t_point p1;
	t_point p2;

	print_text(ft_strdup("Credits"), s->font.color[4], s, &s->hud1.credits.title);
	s->hud1.credits.title.rect = init_sdl_rect(SIZE_X / 4 / 2 - 40, SIZE_Y + SIZE_Y / 8 - 5, 50, 20);
	print_text(ft_strdup("ebertin/fde-souz/ppetit/vgauther"), s->font.color[4], s, &s->hud1.credits.names);
	s->hud1.credits.names.rect = init_sdl_rect(7, SIZE_Y + SIZE_Y / 6, 230, 18);
	p1 = init_point_2_coord(0, WIN_Y / 8 * 7);
	p2 = init_point_2_coord(SIZE_X / 4, WIN_Y / 8 * 7);
	horizontal_trait(p1, p2, WHITE, e);
	p1 = init_point_2_coord(SIZE_X / 4 - 10, SIZE_Y);
	p2 = init_point_2_coord(SIZE_X / 4 - 10, WIN_Y);
	vertical_trait(p1, p2, WHITE, e);
	ornement(s->hud1.credits.title.rect, WHITE, 20, e);
}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	t_point p1;
	t_point p2;

	init_font(s);
	create_bouton(s);
	open_texture(s);
	init_info_messages(s);
	s->hud1.s_logo = SDL_LoadBMP("./img_srcs/rtl.bmp");
	s->hud1.r_logo = init_sdl_rect(2, 0, (SIZE_X / 4) - (WIN_X / 100) ,SIZE_Y / 4);
	if ((s->hud1.t_logo = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_logo)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (!(e->hud = (Uint32*)malloc(sizeof(Uint32) * WIN_X * WIN_Y)))
		ft_error("MALLOC ERROR");
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	print_rect(r1, e, 1, COLOR_BACK);
	r1 = init_rect(WIN_X / 100, 200, (SIZE_X / 4) - (WIN_X / 100), 400);
	empty_rect(r1, e, 1, WHITE);
	r1 = init_rect(WIN_X / 67, 190, (SIZE_X / 4) - (WIN_X / 70), 210);
	print_rect(r1, e, 1, COLOR_BACK);
	r1 = init_rect(SIZE_X / 4 - 10, SIZE_Y / 8 - 10, SIZE_X / 4 + SIZE_X + 10, SIZE_Y / 8 + SIZE_Y + 10);
	print_rect(r1, e, 1, WHITE);
	bloc_save(e, s);
	bloc_credits(e,s);
	p1 = init_point_2_coord(SIZE_X / 4 - 10, 0);
	p2 = init_point_2_coord(SIZE_X / 4 - 10, SIZE_Y / 8);
	vertical_trait(p1, p2, WHITE, e);
	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 9, SIZE_Y);
	p2 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 9, WIN_Y);
	vertical_trait(p1, p2, WHITE, e);
	s->hud1.s_back->pixels = e->hud;
	if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	print_text(ft_strdup(s->hud1.mess[0]), s->font.color[4], s, &s->hud1.info);
	s->hud1.info.rect = init_sdl_rect(SIZE_X / 4 + 28, (WIN_Y / 14) * 13.4 ,500, 25);
}
