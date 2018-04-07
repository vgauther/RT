/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/06 17:36:21 by vgauther         ###   ########.fr       */
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

void	open_texture(t_sdl *s)
{
	SDL_Surface *surface[6];
	int i;
	i = 0;
	surface[0] = SDL_LoadBMP("./img_srcs/-.bmp");
	surface[1] = SDL_LoadBMP("./img_srcs/+.bmp");
	surface[2] = SDL_LoadBMP("./img_srcs/-2.bmp");
	surface[3] = SDL_LoadBMP("./img_srcs/+2.bmp");
	surface[4] = SDL_LoadBMP("./img_srcs/m.bmp");
	surface[5] = SDL_LoadBMP("./img_srcs/m2.bmp");
	if ((s->tex[0] = SDL_CreateTextureFromSurface(s->renderer, surface[0])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[1] = SDL_CreateTextureFromSurface(s->renderer, surface[1])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[2] = SDL_CreateTextureFromSurface(s->renderer, surface[2])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[3] = SDL_CreateTextureFromSurface(s->renderer, surface[3])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[4] = SDL_CreateTextureFromSurface(s->renderer, surface[4])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((s->tex[5] = SDL_CreateTextureFromSurface(s->renderer, surface[5])) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	while(i != 6)
	{
		SDL_FreeSurface(surface[i]);
		i++;
	}
}

void	vertical_trait(t_point p1, t_point p2, int color, t_env *e)
{
	if (p1.x > p2.x)
		ft_error("\nvertical_trait error\n");
	while (p1.x != p2.x)
	{
		ft_put_pixel_hud(e->hud, p1.x, p1.y, color);
		p1.x++;
	}
}

void	horizontal_trait(t_point p1, t_point p2, int color, t_env *e)
{
	if (p1.y > p2.y)
		ft_error("\nhorizontal_trait error\n");
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
	s->hud1.mess[1] = ft_strdup("Last Info : Camera just mooved on x axis");
	s->hud1.mess[2] = ft_strdup("Last Info : Camera just mooved on y axis");
	s->hud1.mess[3] = ft_strdup("Last Info : Camera just mooved on z axis");
	s->hud1.mess[4] = ft_strdup("Last Info : Your work has been saved.");

}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;

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
	/*r1 = init_rect(SIZE_X / 4 - 10, SIZE_Y / 8 - 10, SIZE_X / 4 + SIZE_X + 10, SIZE_Y / 8 + SIZE_Y + 10);
	print_rect(r1, e, 1, WHITE);
	r1 = init_rect(SIZE_X / 4 - 10, SIZE_Y / 8 + SIZE_Y + 10, SIZE_X + SIZE_X / 4 + 9, WIN_Y);
	empty_rect(r1, e, 1, WHITE);
	r1 = init_rect(SIZE_X / 4 + SIZE_X - 150, -1, SIZE_X + SIZE_X / 4 + 9, SIZE_Y / 8);
	empty_rect(r1, e, 1, WHITE);
	r1 = init_rect(0, SIZE_Y / 6 * 5.5 , SIZE_X / 4 - 10, WIN_Y);
	empty_rect(r1, e, 1, WHITE);*/
	s->hud1.s_back->pixels = e->hud;
	if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	printf("%s\n", "test");
	print_text(ft_strdup(s->hud1.mess[0]), s->font.color[4], s, &s->hud1.info);
	printf("%s\n", "test");

	s->hud1.info.rect = init_sdl_rect(SIZE_X / 4 + 28, (WIN_Y / 14) * 13.4 ,500, 25);
}
