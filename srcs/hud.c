/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/18 16:45:40 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	empty_rect(t_rect b, t_env *e, int t, int color)
{
	int i;

	i = b.x;
	while (i != b.x + b.len)
	{
		t == 1 ? ft_put_pixel_hud(e->hud, i, b.y, color) :
		ft_put_pixel_winrend(e->pixels, i, b.y, color);
		t == 1 ? ft_put_pixel_hud(e->hud, i, b.y + b.hei, color) :
		ft_put_pixel_winrend(e->pixels, i, b.y + b.hei, color);
		i++;
	}
	i = b.y;
	while (i != b.y + b.hei)
	{
		t == 1 ? ft_put_pixel_hud(e->hud, b.x, i, color) :
		ft_put_pixel_winrend(e->pixels, b.x, i, color);
		t == 1 ? ft_put_pixel_hud(e->hud, b.x + b.len, i, color) :
		ft_put_pixel_winrend(e->pixels, b.x + b.len, i, color);
		i++;
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
	s->hud1.cam.title.rect = init_sdl_rect((SIZE_X / 4 - 10) / 2 -
	((SIZE_X / 6 - (WIN_X / 50) - 10) / 2), SIZE_Y / 3 - 10, SIZE_X / 6 -
	(WIN_X / 50) - 10, 20);
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

void		create_bouton_cam(t_sdl *s)
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
		s->hud1.bouton[i].rect = init_sdl_rect(x, y, 20, 20);
		i++;
		y += 40;
		if (i == 3 || i == 9)
		{
			t = 1;
			x -= 25;
		}
		t = i == 6 ? 0 : t;
		x = i == 6 ? 165 : x;
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
	s->hud1.mess = malloc(sizeof(char *) * 12);
	s->hud1.mess[0] =
	ft_strdup("Last   Info   :   RT   succesfully   launched.");
	s->hud1.mess[1] =
	ft_strdup("Last  Info  :  Camera  just  mooved  on  x  axis");
	s->hud1.mess[2] =
	ft_strdup("Last  Info  :  Camera  just  mooved  on  y  axis");
	s->hud1.mess[3] =
	ft_strdup("Last  Info  :  Camera  just  mooved  on  z  axis");
	s->hud1.mess[4] =
	ft_strdup("Last  Info  :  Your  work  has  been  saved.");
	s->hud1.mess[5] =
	ft_strdup("Last  Info  :  Sepia filter actived.");
	s->hud1.mess[6] =
	ft_strdup("Last  Info  :  Sepia filter disabled.");
	s->hud1.mess[7] =
	ft_strdup("Last  Info  :  Black and white filter actived.");
	s->hud1.mess[8] =
	ft_strdup("Last  Info  :  Black and whit filter disabled.");
	s->hud1.mess[9] =
	ft_strdup("Last  Info  :  Camera just rotated on x axis.");
	s->hud1.mess[10] =
	ft_strdup("Last  Info  :  Camera just rotated on y axis.");
	s->hud1.mess[11] =
	ft_strdup("Last  Info  :  Camera just rotated on z axis.");
}

void	ornement(SDL_Rect p, int color, int size, t_env *e)
{
	t_point	p1;
	t_point	p2;
	int		l;

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

void	bloc_save(t_env *e, t_sdl *s)
{
	t_point p1;
	t_point p2;
	t_rect	r1;

	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 10, 0);
	p2 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 10, SIZE_Y / 8);
	vertical_trait(p1, p2, WHITE, e);
	p1 = init_point_2_coord(SIZE_X / 4 + (SIZE_X / 6) * 5 - 5, 0);
	p2 = init_point_2_coord(SIZE_X / 4 + (SIZE_X / 6) * 5 - 5, SIZE_Y / 8);
	vertical_trait(p1, p2, WHITE, e);
	r1 = init_rect(SIZE_X / 4 + (SIZE_X / 6) * 5 + (SIZE_X / 6 + 10) / 6, SIZE_Y / 17,
		(SIZE_X / 6 + 10) / 3 * 2, SIZE_Y / 50);
	print_rect(r1, e, 1, WHITE);
	print_text(ft_strdup("Save"), s->font.color[4], s, &s->hud1.save);
	s->hud1.save.rect = init_sdl_rect(SIZE_X / 4 + (SIZE_X / 6) * 5 + (SIZE_X / 6 + 10) / 8, SIZE_Y / 80,
	((SIZE_X / 6 + 10) / 4) * 3, 15);
	ornement(s->hud1.save.rect, WHITE, 15, e);
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

void	create_bouton_tool_bar(t_sdl *s)
{
	s->hud1.bouton[12].i = 8;
	s->hud1.bouton[12].rect = init_sdl_rect(SIZE_X / 2 + SIZE_X / 4,
		SIZE_Y / 16 - 20, 40, 40);
	s->hud1.bouton[13].i = 6;
	s->hud1.bouton[13].rect = init_sdl_rect(SIZE_X / 2 + SIZE_X / 4 + 60,
		SIZE_Y / 16 - 20, 40, 40);
	s->hud1.bouton[14].i = 4;
	s->hud1.bouton[14].rect = init_sdl_rect(SIZE_X / 4 + 60, SIZE_Y / 16 - 20,
		40, 40);
	s->hud1.bouton[15].i = 4;
	s->hud1.bouton[15].rect = init_sdl_rect(SIZE_X / 4 + 120, SIZE_Y / 16 - 20,
		40, 40);
}

void	bloc_camera(t_env *e, t_sdl *s)
{
	t_rect	r1;

	r1 = init_rect(WIN_X / 100, SIZE_Y / 3, SIZE_X / 4 - (WIN_X / 50) - 10, SIZE_Y / 3);
	empty_rect(r1, e, 1, CONTRAST);
	r1 = init_rect(WIN_X / 100 + ((SIZE_X / 4 - (WIN_X / 50) - 10) / 8), (SIZE_Y / 3) - 2,
	 ((SIZE_X / 4 - (WIN_X / 50) - 10) / 8 ) * 6, 4);
	print_rect(r1, e, 1, COLOR_BACK);
	(void)s;
}

void	bloc_multiplier(t_env *e, t_sdl *s)
{
	t_rect rect;

	rect = init_rect((SIZE_X / 4 + 10) / 8, WIN_Y / 2 + WIN_Y / 4, (SIZE_X / 4 + 10) / 9, (SIZE_X / 4 + 10) / 9);
	print_rect(rect, e, 1, CONTRAST);
	rect = init_rect((SIZE_X / 4 + 10) / 8, WIN_Y / 2 + WIN_Y / 4 - ((SIZE_X / 4 + 10) / 9 ) * 1.5, (SIZE_X / 4 + 10) / 9, (SIZE_X / 4 + 10) / 9);
	print_rect(rect, e, 1, CONTRAST);
	rect = init_rect((SIZE_X / 4 + 10) / 8, WIN_Y / 2 + WIN_Y / 4 + ((SIZE_X / 4 + 10) / 9 ) * 1.5, (SIZE_X / 4 + 10) / 9, (SIZE_X / 4 + 10) / 9);
	print_rect(rect, e, 1, CONTRAST);
	s->hud1.multi_bouton[0] = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5, WIN_Y / 2 + WIN_Y / 4 + 5 , (SIZE_X / 4 + 10) / 9 - 10, (SIZE_X / 4 + 10) / 9 - 10);
	s->hud1.multi_bouton[1] = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5, WIN_Y / 2 + WIN_Y / 4 - ((SIZE_X / 4 + 10) / 9)
	* 1.5 + 5, (SIZE_X / 4 + 10) / 9 - 10, (SIZE_X / 4 + 10) / 9 - 10);
	s->hud1.multi_bouton[2] = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5, WIN_Y / 2 + WIN_Y / 4 + ((SIZE_X / 4 + 10) / 9 ) * 1.5 + 5,
	(SIZE_X / 4 + 10) / 9 - 10, (SIZE_X / 4 + 10) / 9 - 10);
	s->hud1.multi = 1;
	s->hud1.how_much = 1;
	print_text(ft_strdup("+ 1"), s->font.color[1], s, &s->hud1.multi_text[1]);
	s->hud1.multi_text[0].rect = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5 + ((SIZE_X / 4 + 10) / 9 - 10) * 2,
	WIN_Y / 2 + WIN_Y / 4 + 5 , ((SIZE_X / 4 + 10) / 9), (SIZE_X / 4 + 10) / 9 - 10);
	print_text(ft_strdup("+ 10"), s->font.color[1], s, &s->hud1.multi_text[0]);
	s->hud1.multi_text[1].rect = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5 + ((SIZE_X / 4 + 10) / 9 - 10) * 2,
	WIN_Y / 2 + WIN_Y / 4 + 5 - ((SIZE_X / 4 + 10) / 9)
	* 1.5, ((SIZE_X / 4 + 10) / 9 - 10), (SIZE_X / 4 + 10) / 9 - 10);
	print_text(ft_strdup("+ 100"), s->font.color[1], s, &s->hud1.multi_text[2]);
	s->hud1.multi_text[2].rect = init_sdl_rect((SIZE_X / 4 + 10) / 8 + 5 + ((SIZE_X / 4 + 10) / 9 - 10) * 2,
	WIN_Y / 2 + WIN_Y / 4 + 5 + ((SIZE_X / 4 + 10) / 9)
	* 1.5, ((SIZE_X / 4 + 10) / 9 + 10), (SIZE_X / 4 + 10) / 9 - 10);
	(void)s;
}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	t_point p1;
	t_point p2;

	init_font(s);
	open_texture(s);
	create_bouton_cam(s);
	init_info_messages(s);
	create_bouton_tool_bar(s);
	s->hud1.s_logo = SDL_LoadBMP("./img_srcs/rtl.bmp");
	s->hud1.r_logo = init_sdl_rect(2, 0, (SIZE_X / 4) - (WIN_X / 100) ,SIZE_Y / 4);
	if ((s->hud1.t_logo = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_logo)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if (!(e->hud = (Uint32*)malloc(sizeof(Uint32) * WIN_X * WIN_Y)))
		ft_error("MALLOC ERROR");
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	print_rect(r1, e, 1, COLOR_BACK);
	r1 = init_rect(SIZE_X / 4 - 10, SIZE_Y / 8 - 10, SIZE_X + 20, SIZE_Y + 20);
	print_rect(r1, e, 1, CONTRAST);
	bloc_camera(e, s);
	bloc_save(e, s);
	bloc_credits(e, s);
	bloc_multiplier(e, s);
	p1 = init_point_2_coord(SIZE_X / 4 - 10, 0);
	p2 = init_point_2_coord(SIZE_X / 4 - 10, SIZE_Y / 8);
	vertical_trait(p1, p2, WHITE, e);
	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 10, SIZE_Y);
	p2 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 10, WIN_Y);
	vertical_trait(p1, p2, WHITE, e);
	s->hud1.s_back->pixels = e->hud;
	if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	print_text(ft_strdup(s->hud1.mess[0]), s->font.color[4], s, &s->hud1.info);
	s->hud1.info.rect = init_sdl_rect(SIZE_X / 4 + 28, (WIN_Y / 14) * 13.4 , 500, 25);
	s->hud1.color_selector = init_sdl_rect(0 , 0, 999, 999);
	s->hud1.color_selector_surf = SDL_LoadBMP("./img_srcs/color.bmp");
}
