/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 00:55:44 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 11:46:17 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "../libft/includes/libft.h"
#include <stdint.h>
#include <time.h>

void	init_hud_var(t_sdl *s)
{
	s->hud1.filter_token.sep = 0;
	s->hud1.filter_token.bw = 0;
	s->hud1.selectobj = 0;
	s->hud1.pipette = 0;
	s->hud1.shape_img.i = 0;
	s->hud1.add_obj = 0;
	s->hud1.box_picked = 42;
	s->hud1.ok.i = 17;
}

void	ft_init(t_sdl *s, char *name, t_env *e)
{
	char *str;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	str = ft_strjoin("RT : Ray Tracer - ", name);
	s->window = SDL_CreateWindow(str, POS_WIN_X, POS_WIN_Y, WIN_X, WIN_Y,
			SDL_WINDOW_ALLOW_HIGHDPI);
	init_hud_var(s);
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
	if ((e->test = SDL_LoadBMP("./img_srcs/map_test.bmp"))
			== NULL)
		ft_sdl_error("Surface error : ", SDL_GetError());
	free(s->rendu->pixels);
	free(s->hud1.s_back->pixels);
	if (!(e->pixels = (Uint32*)malloc(sizeof(Uint32) * SIZE_X * SIZE_Y)))
		ft_error("\nmalloc error\n");
	parser(name, e);
	hud_init(s, e);
}

void	add_obj_selection_display(t_sdl *s, t_env *e)
{
	(void)e;
	SDL_RenderCopy(s->renderer, s->tex[12], NULL, &s->hud1.r_add_obj[0]);
	SDL_RenderCopy(s->renderer, s->tex[13], NULL, &s->hud1.r_add_obj[1]);
	SDL_RenderCopy(s->renderer, s->tex[14], NULL, &s->hud1.r_add_obj[2]);
	SDL_RenderCopy(s->renderer, s->tex[15], NULL, &s->hud1.r_add_obj[3]);
}

void	add_obj_menu(t_sdl *s, t_env *e, int nb)
{
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[0]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[1]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[2]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[3]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[4]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[5]);
	print_text(ft_itoa(e->obj[nb].pos.x), s->font.color[1], s, &s->hud1.add_obj_data[0]);
	print_text(ft_itoa(e->obj[nb].pos.y), s->font.color[1], s, &s->hud1.add_obj_data[1]);
	print_text(ft_itoa(e->obj[nb].pos.z), s->font.color[1], s, &s->hud1.add_obj_data[2]);
	print_text(ft_itoa(e->obj[nb].rot.x), s->font.color[1], s, &s->hud1.add_obj_data[3]);
	print_text(ft_itoa(e->obj[nb].rot.y), s->font.color[1], s, &s->hud1.add_obj_data[4]);
	print_text(ft_itoa(e->obj[nb].rot.z), s->font.color[1], s, &s->hud1.add_obj_data[5]);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[0].tex, NULL, &s->hud1.add_obj_data[0].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[1].tex, NULL, &s->hud1.add_obj_data[1].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[2].tex, NULL, &s->hud1.add_obj_data[2].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[3].tex, NULL, &s->hud1.add_obj_data[3].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[4].tex, NULL, &s->hud1.add_obj_data[4].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[5].tex, NULL, &s->hud1.add_obj_data[5].rect);
	SDL_RenderCopy(s->renderer, s->tex[s->hud1.ok.i], NULL, &s->hud1.ok.rect);
}

void	display_credits(t_sdl *s)
{
	if ((SDL_RenderCopy(s->renderer, s->hud1.credits.title.tex, NULL,
		&s->hud1.credits.title.rect)) < 0)
		ft_error("\nRender copy Error\n");
	if ((SDL_RenderCopy(s->renderer, s->hud1.credits.names.tex, NULL,
		&s->hud1.credits.names.rect)) < 0)
		ft_error("\nRender copy Error\n");
}

void	display(t_sdl *s, t_env *e)
{
	int			i;
	SDL_Rect	rendu_rect;
	int			*r;

	if (!(r = (int*)malloc(sizeof(int) * 34)))
		ft_error("\nMalloc Error\n");
	i = -1;
	SDL_RenderClear(s->renderer);
	recup_cam_to_print(s, e);
	s->rendu->pixels = e->pixels;
	rendu_rect = init_sdl_rect(SIZE_X / 4, SIZE_Y / 8, SIZE_X, SIZE_Y);
	if ((s->texture = SDL_CreateTextureFromSurface(s->renderer, s->rendu))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	r[0] = SDL_RenderCopy(s->renderer, s->hud1.t_back, NULL, NULL);
	r[1] = SDL_RenderCopy(s->renderer, s->hud1.cam.title.tex, NULL, &s->hud1.cam.title.rect);
	r[2] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_x.tex, NULL, &s->hud1.cam.pos_x.rect);
	r[3] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_y.tex, NULL, &s->hud1.cam.pos_y.rect);
	r[4] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_z.tex, NULL, &s->hud1.cam.pos_z.rect);
	r[5] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_x.tex, NULL, &s->hud1.cam.rot_x.rect);
	r[6] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_y.tex, NULL, &s->hud1.cam.rot_y.rect);
	r[7] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_z.tex, NULL, &s->hud1.cam.rot_z.rect);
	r[8] = SDL_RenderCopy(s->renderer, s->hud1.info.tex, NULL, &s->hud1.info.rect);
	display_credits(s);
	while (++i != 17)
		r[i + 8] = SDL_RenderCopy(s->renderer, s->tex[s->hud1.bouton[i].i], NULL, &s->hud1.bouton[i].rect);
	r[24] = SDL_RenderCopy(s->renderer, s->hud1.logo.tex, NULL, &s->hud1.logo.rect);
	r[25] = SDL_RenderCopy(s->renderer, s->texture, NULL, &rendu_rect);
	r[26] = SDL_RenderCopy(s->renderer, s->hud1.save.tex, NULL, &s->hud1.save.rect);
	if ((s->hud1.shape_img.i >= 12 && s->hud1.shape_img.i <= 15) || s->hud1.add_obj == 2)
		r[27] = SDL_RenderCopy(s->renderer, s->tex[s->hud1.shape_img.i], NULL, &s->hud1.shape_img.rect);
	else
		r[27] = 0;
	r[28] = SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.multi_bouton[s->hud1.multi]);
	r[29] = SDL_RenderCopy(s->renderer, s->hud1.multi_text[0].tex, NULL, &s->hud1.multi_text[0].rect);
	r[30] = SDL_RenderCopy(s->renderer, s->hud1.multi_text[1].tex, NULL, &s->hud1.multi_text[1].rect);
	r[31] = SDL_RenderCopy(s->renderer, s->hud1.multi_text[2].tex, NULL, &s->hud1.multi_text[2].rect);
	r[33] = SDL_RenderCopy(s->renderer, s->hud1.workspace_text.tex, NULL, &s->hud1.workspace_text.rect);
	if (s->hud1.add_obj == 1)
		add_obj_selection_display(s, e);
	if (s->hud1.add_obj == 2)
		add_obj_menu(s, e, e->nb - 1);
	if (s->hud1.pipette == 1)
		r[32] = SDL_RenderCopy(s->renderer, s->tex[16], NULL, &s->hud1.color_selector);
	else
		r[32] = 0;
	i = -1;
	while (++i < 34)
		if (r[i] < 0)
			ft_error("\nRender copy Error\n");
	free(r);
	SDL_RenderPresent(s->renderer);
}

void	del_char(t_env *e, t_sdl *s)
{
	if (s->hud1.box_picked == 0)
	{
		e->obj[e->nb - 1].pos.x = (e->obj[e->nb - 1].pos.x - (int)e->obj[e->nb - 1].pos.x % 10) / 10;
	}
	else if (s->hud1.box_picked == 1)
	{
		e->obj[e->nb - 1].pos.y = (e->obj[e->nb - 1].pos.y - (int)e->obj[e->nb - 1].pos.y % 10) / 10;
	}
	else if (s->hud1.box_picked == 2)
	{
		e->obj[e->nb - 1].pos.z = (e->obj[e->nb - 1].pos.z - (int)e->obj[e->nb - 1].pos.z % 10) / 10;
	}
	else if (s->hud1.box_picked == 3)
	{
		e->obj[e->nb - 1].rot.x = (e->obj[e->nb - 1].rot.x - (int)e->obj[e->nb - 1].rot.x % 10) / 10;
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[e->nb - 1].rot.y = (e->obj[e->nb - 1].rot.y - (int)e->obj[e->nb - 1].rot.y % 10) / 10;
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[e->nb - 1].rot.z = (e->obj[e->nb - 1].rot.z - (int)e->obj[e->nb - 1].rot.z % 10) / 10;
	}
	raytracing(e, s);
}

void	remplir_text_box(int key, t_env *e, t_sdl *s)
{
	int x;
	int y;

	y = 1;
	x = nbr_touch(key);
	if (key == 42)
	{
		del_char(e, s);
		return ;
	}
	if (x == -1)
	{
		x = 0;
		y = -1;
	}
	if (x == 42)
		return ;
	if (s->hud1.box_picked == 0)
	{
		e->obj[e->nb - 1].pos.x = (e->obj[e->nb - 1].pos.x * 10 + x) * y;
	}
	else if (s->hud1.box_picked == 1)
	{
		e->obj[e->nb - 1].pos.y = (e->obj[e->nb - 1].pos.y * 10 + x) * y;
	}
	else if (s->hud1.box_picked == 2)
	{
		e->obj[e->nb - 1].pos.z = (e->obj[e->nb - 1].pos.z * 10 + x) * y;
	}
	else if (s->hud1.box_picked == 3)
	{
		e->obj[e->nb - 1].rot.x = (e->obj[e->nb - 1].rot.x * 10 + x) * y;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot);
	}
	else if (s->hud1.box_picked == 4)
	{
		e->obj[e->nb - 1].rot.y = (e->obj[e->nb - 1].rot.y * 10 + x) * y;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot);
	}
	else if (s->hud1.box_picked == 5)
	{
		e->obj[e->nb - 1].rot.z = (e->obj[e->nb - 1].rot.z * 10 + x) * y;
		e->obj[e->nb - 1].rot = normalize_vec(e->obj[e->nb - 1].rot);
	}
	raytracing(e, s);
}

void	mouv(long key, t_env *e, t_sdl *s)
{
	if (s->hud1.box_picked != 42)
		remplir_text_box(key, e, s);
	else
	{
		if (key == CAM_LEFT)
		{
			print_info(s, e, 1);
			e->ca.pos.x -= s->hud1.how_much;
		}
		if (key == CAM_RIGHT)
		{
			print_info(s, e, 1);
			e->ca.pos.x += s->hud1.how_much;
		}
		if (key == CAM_UP)
		{
			print_info(s, e, 2);
			e->ca.pos.y -= s->hud1.how_much;
		}
		if (key == CAM_DOWN)
		{
			print_info(s, e, 2);
			e->ca.pos.y += s->hud1.how_much;
		}
		if (key == CAM_FOR)
		{
			print_info(s, e, 3);
			e->ca.pos.z += s->hud1.how_much;
		}
		if (key == CAM_BACK)
		{
			print_info(s, e, 3);
			e->ca.pos.z -= s->hud1.how_much;
		}
		if (do_we_need_to_rt(key))
			raytracing(e, s);
	}
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

	check_define();
	e.ca = init_cam(0, 0, 0);
	if ((r = 1) == 1 && ac != 2)
		ft_error("\nWrong number of arguments.\n");
	ft_init(&s, av[1], &e);
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
				main_mouse(s.event.button.x, s.event.button.y, &s, &e);
		}
	}
	quit_sdl_proprely(&s);
	return (0);
}
