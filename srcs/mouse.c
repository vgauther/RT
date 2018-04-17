/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:51:45 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/17 12:18:07 by vgauther         ###   ########.fr       */
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
			r1 = init_rect(SIZE_X / 4 + SIZE_X - 110,
				SIZE_Y / 17, SIZE_X / 4 + SIZE_X - 20, SIZE_Y / 12);
			print_rect(r1, e, 1, RED);
			s->hud1.s_back->pixels = e->hud;
			if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer,
				s->hud1.s_back)) == NULL)
				ft_sdl_error("Texture error : ", SDL_GetError());
			display(s, e);
			ft_wait();
			r1 = init_rect(SIZE_X / 4 + SIZE_X - 110,
				SIZE_Y / 17, SIZE_X / 4 + SIZE_X - 20, SIZE_Y / 12);
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
		print_info(s, e, 0);
		s->hud1.bouton[i].i = 1;
		if (i == 9)
			e->ca.rot.x++;
		else if (i == 10)
			e->ca.rot.y++;
		else
			e->ca.rot.z++;
	}
	else
	{
		s->hud1.bouton[i].i = 2;
		print_info(s, e, 0);
		s->hud1.bouton[i].i = 0;
		if (i == 6)
			e->ca.rot.x--;
		else if (i == 7)
			e->ca.rot.y--;
		else
			e->ca.rot.z--;
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
			e->ca.pos.x++;
		else if (i == 4)
			e->ca.pos.y++;
		else
			e->ca.pos.z++;
	}
	else
	{
		s->hud1.bouton[i].i = 2;
		print_info(s, e, i);
		s->hud1.bouton[i].i = 0;
		if (i == 0)
			e->ca.pos.x--;
		else if (i == 1)
			e->ca.pos.y--;
		else
			e->ca.pos.z--;
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
			display(s, e);
			raytracing(e, s);
		}
		else if (x >= SIZE_X / 4 + SIZE_X / 2 + 60 &&
			x <= SIZE_X / 4 + SIZE_X / 2 + 100)
		{
			s->hud1.bouton[13].i = s->hud1.bouton[13].i == 7 ? 6 : 7;
			s->hud1.filter_token.bw = s->hud1.bouton[13].i == 7 ? 1 : 0;
			display(s, e);
			raytracing(e, s);
		}
	}
}

void	print_data_obj(t_sdl *s, t_env *e, int nbr)
{
	(void)s;
	(void)e;
	(void)nbr;
	SDL_Rect rect;

	rect = init_sdl_rect(SIZE_X / 4 + SIZE_X + (SIZE_X / 4 / 8), SIZE_Y / 8 + SIZE_Y / 16, 50, 50);
	if (e->obj[nbr].type == 1)
		ft_putstr("sphere\n");
	if (e->obj[nbr].type == 2)
		ft_putstr("cylindre\n");
	if (e->obj[nbr].type == 3)
		ft_putstr("cone\n");
}

void	mouse_obj_seletor(int x, int y, t_sdl *s, t_env *e)
{
	int			nbr;
	t_inter		pt;
	t_inter		tmp;
	t_vec		dir;

	if (x > SIZE_X / 4 && x < SIZE_X / 4 + SIZE_X)
	{
		if (y > SIZE_Y / 8 && y < SIZE_Y / 8 + SIZE_Y)
		{
			x -= SIZE_X / 4;
			y -= SIZE_Y / 8;
			nbr = 0;
			pt.dist = MAX_DIST;
			while (nbr < e->nb)
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
				nbr++;
			}
			if (pt.dist != MAX_DIST && s->hud1.selectobj)
				print_data_obj(s, e, pt.nb);
		}
	}
	(void)s;
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

void	main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	if (s->hud1.selectobj == 1)
		mouse_obj_seletor(mouse_x, mouse_y, s, e);
	save_bouton(mouse_x, mouse_y, s, e);
	mouse_cam_rot(mouse_x, mouse_y, s, e);
	mouse_cam_trans(mouse_x, mouse_y, s, e);
	mouse_filter_activate(mouse_x, mouse_y, s, e);
	mouse_selector_activate(mouse_x, mouse_y, s, e);
	//printf("%d|%d\n", mouse_x, mouse_y);
}
