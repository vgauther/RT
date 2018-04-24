/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:51:45 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/24 16:19:11 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	save_bouton(int x, int y, t_sdl *s, t_env *e)
{
	t_rect r1;

	if (x >= SIZE_X / 4 + SIZE_X - 110 && x <= SIZE_X / 4 + SIZE_X - 20)
	{
		if (SIZE_Y / 17 <= y && y <= SIZE_Y / 12)
		{
			r1 = init_rect(COL4 + (SIZE_X / 6) * 5 + (SIZE_X / 6 + 10) / 6,
			SIZE_Y / 17, (SIZE_X / 6 + 10) / 3 * 2, SIZE_Y / 50);
			print_rect(r1, e, 1, RED);
			s->hud1.s_back->pixels = e->hud;
			if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer,
				s->hud1.s_back)) == NULL)
				ft_sdl_error("Texture error : ", SDL_GetError());
			display(s, e);
			ft_wait();
			print_rect(r1, e, 1, WHITE);
			s->hud1.s_back->pixels = e->hud;
			if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer,
				s->hud1.s_back)) == NULL)
				ft_sdl_error("Texture error : ", SDL_GetError());
			print_info(s, e, 4);
			SDL_SaveBMP(s->rendu, "save.bmp");
		}
	}
}

void	print_info(t_sdl *s, t_env *e, int i)
{
	print_text(ft_strdup(s->hud1.mess[i]), s->font.color[4], s, &s->hud1.info);
	s->hud1.info.rect = init_sdl_rect(SIZE_X / 4 + 28,
		(WIN_Y / 14) * 13.4, 500, 25);
	display(s, e);
}

void	mouse_filter_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
	{
		if (x >= SIZE_X / 4 + SIZE_X / 2 && x <= SIZE_X / 4 + SIZE_X / 2 + 40)
		{
			s->hud1.bouton[12].i = s->hud1.bouton[12].i == 8 ? 9 : 8;
			s->hud1.filter_token.sep = s->hud1.bouton[12].i == 9 ? 2 : 0;
			print_info(s, e, s->hud1.filter_token.sep == 2 ? 5 : 6);
			raytracing(e, s);
		}
		else if (x >= SIZE_X / 4 + SIZE_X / 2 + 60 &&
			x <= SIZE_X / 4 + SIZE_X / 2 + 100)
		{
			s->hud1.bouton[13].i = s->hud1.bouton[13].i == 7 ? 6 : 7;
			s->hud1.filter_token.bw = s->hud1.bouton[13].i == 7 ? 1 : 0;
			print_info(s, e, s->hud1.filter_token.bw == 1 ? 7 : 8);
			raytracing(e, s);
		}
	}
}

void	mouse_multi(int x, int y, t_sdl *s, t_env *e)
{
	int i;

	i = 0;
	if (x >= s->hud1.multi_bouton[0].x && x <= s->hud1.multi_bouton[0].x +
		s->hud1.multi_bouton[0].w)
	{
		while (i != 3)
		{
			if (y >= s->hud1.multi_bouton[i].y && y <=
				s->hud1.multi_bouton[i].y + s->hud1.multi_bouton[i].h)
			{
				(i == 0) ? s->hud1.how_much = 10 : 0;
				(i == 1) ? s->hud1.how_much = 1 : 0;
				(i == 2) ? s->hud1.how_much = 100 : 0;
				s->hud1.multi = i;
				display(s, e);
				break ;
			}
			i++;
		}
	}
}

void	mouse_light(int x, int y, t_sdl *s, t_env *e)
{
	if (y >= s->hud1.bouton[17].rect.y &&
		y <= s->hud1.bouton[17].rect.y + s->hud1.bouton[17].rect.h)
	{
		if (x >= s->hud1.bouton[17].rect.x &&
			x <= s->hud1.bouton[17].rect.x + s->hud1.bouton[17].rect.w)
		{
			s->hud1.bouton[17].i = 3;
			display(s, e);
			e->amb = (e->amb + 0.1 <= 1) ? e->amb + 0.1 : 1;
			raytracing(e, s);
			s->hud1.bouton[17].i = 1;
			display(s, e);
		}
		else if (x >= s->hud1.bouton[18].rect.x &&
			x <= s->hud1.bouton[18].rect.x + s->hud1.bouton[18].rect.w)
		{
			s->hud1.bouton[18].i = 2;
			display(s, e);
			e->amb = (e->amb - 0.1 >= 0) ? e->amb - 0.1 : 0;
			raytracing(e, s);
			s->hud1.bouton[18].i = 0;
			display(s, e);
		}
	}
}

void	main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	if (s->hud1.add_obj == 1 || s->hud1.add_obj == 2)
	{
		mouse_add_obj_select(mouse_x, mouse_y, s, e);
	}
	if (s->hud1.add_obj == 2 || s->hud1.tok.obj_select != -1)
	{
		mouse_add_obj(mouse_x, mouse_y, s, e);
	}
	if (s->hud1.selectobj == 1 && s->hud1.add_obj != 1)
	{
		mouse_obj_seletor(mouse_x, mouse_y, s, e);
	}
	if (s->hud1.pipette == 1)
	{
		mouse_pipette_color(mouse_x, mouse_y, s, e);
	}
	mouse_light(mouse_x, mouse_y, s, e);
	if (mouse_x <= COL)
		mouse_main_cam(mouse_x, mouse_y, s, e);
	mouse_multi(mouse_x, mouse_y, s, e);
	if (mouse_y <= LINE)
	{
		mouse_pipette_activate(mouse_x, mouse_y, s, e);
		mouse_filter_activate(mouse_x, mouse_y, s, e);
		if (s->hud1.add_obj != 1)
			mouse_selector_activate(mouse_x, mouse_y, s, e);
		mouse_add_obj_activate(mouse_x, mouse_y, s, e);
		save_bouton(mouse_x, mouse_y, s, e);
	}
}
