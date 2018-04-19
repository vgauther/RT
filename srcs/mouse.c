/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:51:45 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/19 11:52:23 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_wait(void)
{
	int i;

	i = 0;
	while (i != 80000000)
		i++;
}

void	save_bouton(int x, int y, t_sdl *s, t_env *e)
{
	t_rect r1;

	if (x >= SIZE_X / 4 + SIZE_X - 110 && x <= SIZE_X / 4 + SIZE_X - 20)
	{
		if (SIZE_Y / 17 <= y && y <= SIZE_Y / 12)
		{
			r1 = init_rect(SIZE_X / 4 + (SIZE_X / 6) * 5 + (SIZE_X / 6 + 10) / 6, SIZE_Y / 17,
				(SIZE_X / 6 + 10) / 3 * 2, SIZE_Y / 50);
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

void	mouse_cam_rot2(int i, t_sdl *s, t_env *e)
{
	if (i >= 9 && i < 12)
	{
		s->hud1.bouton[i].i = 3;
		print_info(s, e, i);
		s->hud1.bouton[i].i = 1;
		if (i == 9)
			e->ca.rot.x += s->hud1.how_much;
		else if (i == 10)
			e->ca.rot.y += s->hud1.how_much;
		else
			e->ca.rot.z += s->hud1.how_much;
	}
	else
	{
		s->hud1.bouton[i].i = 2;
		print_info(s, e, i + 3);
		s->hud1.bouton[i].i = 0;
		if (i == 6)
			e->ca.rot.x -= s->hud1.how_much;
		else if (i == 7)
			e->ca.rot.y -= s->hud1.how_much;
		else
			e->ca.rot.z -= s->hud1.how_much;
	}
	raytracing(e, s);
}

void	mouse_cam_rot(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	int i;

	i = 6;
	while (i != 12)
	{
		if (mouse_x > s->hud1.bouton[i].rect.x && mouse_x
			< s->hud1.bouton[i].rect.x + s->hud1.bouton[i].rect.w)
		{
			if (mouse_y > s->hud1.bouton[i].rect.y && mouse_y
				< s->hud1.bouton[i].rect.y + s->hud1.bouton[i].rect.h)
				mouse_cam_rot2(i, s, e);
		}
		i++;
	}
}

void	mouse_cam_trans2(int i, t_sdl *s, t_env *e)
{
	if (i > 2 && i < 6)
	{
		s->hud1.bouton[i].i = 3;
		print_info(s, e, i - 2);
		s->hud1.bouton[i].i = 1;
		if (i == 3)
			e->ca.pos.x += s->hud1.how_much;
		else if (i == 4)
			e->ca.pos.y += s->hud1.how_much;
		else
			e->ca.pos.z += s->hud1.how_much;
	}
	else
	{
		s->hud1.bouton[i].i = 2;
		print_info(s, e, i);
		s->hud1.bouton[i].i = 0;
		if (i == 0)
			e->ca.pos.x -= s->hud1.how_much;
		else if (i == 1)
			e->ca.pos.y -= s->hud1.how_much;
		else
			e->ca.pos.z -= s->hud1.how_much;
	}
	raytracing(e, s);
}

void	mouse_cam_trans(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	int i;

	i = 0;
	while (i != 6)
	{
		if (mouse_x > s->hud1.bouton[i].rect.x && mouse_x
			< s->hud1.bouton[i].rect.x + s->hud1.bouton[i].rect.w)
		{
			if (mouse_y > s->hud1.bouton[i].rect.y && mouse_y
				< s->hud1.bouton[i].rect.y + s->hud1.bouton[i].rect.h)
				mouse_cam_trans2(i, s, e);
		}
		i++;
	}
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

void	print_data_obj(t_sdl *s, t_env *e, int nbr)
{
	s->hud1.shape_img.rect = init_sdl_rect(SIZE_X / 4 + SIZE_X +
		(SIZE_X / 4 / 8), SIZE_Y / 8 + SIZE_Y / 16, SIZE_X / 5, SIZE_X / 5);
	if (e->obj[nbr].type == 1)
		s->hud1.shape_img.i = 12;
	if (e->obj[nbr].type == 2)
		s->hud1.shape_img.i = 14;
	if (e->obj[nbr].type == 3)
		s->hud1.shape_img.i = 13;
	if (e->obj[nbr].type == 4)
		s->hud1.shape_img.i = 15;
	display(s, e);
}

void	mouse_obj_seletor(int x, int y, t_sdl *s, t_env *e)
{
	int			nbr;
	t_inter		pt;
	t_inter		tmp;
	t_vec		dir;

	if (x > SIZE_X / 4 && x < SIZE_X / 4 + SIZE_X && (x -= SIZE_X / 4) >= 0)
	{
		if (y > SIZE_Y / 8 && y < SIZE_Y / 8 + SIZE_Y && (y -= SIZE_Y / 8) >= 0)
		{
			nbr = -1;
			pt.dist = MAX_DIST;
			while (++nbr < e->nb)
			{
				dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
				dir = ft_rotate(dir, e->ca.rot.x, e->ca.rot.y, e->ca.rot.z);
				dir = normalize_vec(dir);
				tmp = shape_redirection(e, dir, e->ca.pos, nbr);
				if (tmp.dist < pt.dist && tmp.dist > 0)
				{
					pt.dist = tmp.dist;
					pt.pos = init_point(tmp.pos.x, tmp.pos.y, tmp.pos.z);
					pt.normal = tmp.normal;
					pt.nb = nbr;
				}
			}
			if (pt.dist != MAX_DIST && s->hud1.selectobj)
				print_data_obj(s, e, pt.nb);
		}
	}
}

void	mouse_selector_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= SIZE_X / 4 + 60 && x <= SIZE_X / 4 + 100)
	{
		if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
		{
			s->hud1.bouton[14].i = s->hud1.bouton[14].i == 5 ? 4 : 5;
			display(s, e);
			s->hud1.selectobj = s->hud1.selectobj == 1 ? 0 : 1;
		}
	}
}

void	mouse_multi(int x, int y, t_sdl *s, t_env *e)
{
	int i;

	i = 0;
	if (x >= s->hud1.multi_bouton[0].x && x <= s->hud1.multi_bouton[0].x + s->hud1.multi_bouton[0].w)
	{
		while (i != 3)
		{
			if (y >= s->hud1.multi_bouton[i].y && y <= s->hud1.multi_bouton[i].y + s->hud1.multi_bouton[i].h)
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

void	mouse_pipette_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= SIZE_X / 4 + 120 && x <= SIZE_X / 4 + 160)
	{
		if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
		{
			s->hud1.bouton[15].i = s->hud1.bouton[15].i == 11 ? 10 : 11;
			s->hud1.pipette = s->hud1.pipette == 1 ? 0 : 1;
			display(s, e);
		}
	}
}

void	mouse_pipette_color(int x, int y, t_sdl *s, t_env *e)
{
	Uint32 color;
	char *tab;

//	x -= WIN_X / 2 - 125;
	//y -= WIN_Y / 2 - 125;
	printf("%d|%d\n",x, y);
	/*if (x >= 0 && x <= 256)
	{
		if (y >= 0 && y <= 256)
		{*/
			tab = (char *)s->hud1.color_selector_surf->pixels;
			color = tab[x * (s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w) +
			s->hud1.color_selector_surf->w * (s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w) * y];
			color += tab[x * (s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w) + s->hud1.color_selector_surf->w
			* (s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w) * y + 1] * 256;
			color += tab[x * (s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w) + s->hud1.color_selector_surf->w
			* (s->hud1.color_selector_surf->pitch / s->hud1.color_selector_surf->w) * y + 2]
			* 256 * 256;
			(void)x;
			(void)y;
			(void)s;
			(void)e;
			//color = color & 0xffffff;
			e->obj[0].color = color;
			printf("%u\n", color);
		//}
	//}
}

void	mouse_add_obj_activate(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= SIZE_X / 4 + 180 && x <= SIZE_X / 4 + 220)
	{
		if (y >= SIZE_Y / 16 - 20 && y <= SIZE_Y / 16 + 20)
		{
			s->hud1.bouton[16].i = s->hud1.bouton[16].i == 1 ? 3 : 1;
			s->hud1.add_obj = s->hud1.add_obj == 1 ? 0 : 1;
			s->hud1.bouton[14].i = 4;
			s->hud1.shape_img.i = 0;
			display(s, e);
		}
	}
}

void	main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	if (s->hud1.selectobj == 1)
		mouse_obj_seletor(mouse_x, mouse_y, s, e);
	if (s->hud1.pipette == 1)
		mouse_pipette_color(mouse_x, mouse_y, s, e);
//	mouse_pipette_activate(mouse_x, mouse_y, s, e);
	save_bouton(mouse_x, mouse_y, s, e);
	mouse_cam_rot(mouse_x, mouse_y, s, e);
	mouse_cam_trans(mouse_x, mouse_y, s, e);
	mouse_filter_activate(mouse_x, mouse_y, s, e);
	mouse_selector_activate(mouse_x, mouse_y, s, e);
	mouse_add_obj_activate(mouse_x, mouse_y, s, e);
	mouse_multi(mouse_x, mouse_y, s, e);
}
