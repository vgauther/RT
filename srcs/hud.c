/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:47:14 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/24 13:32:33 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

void	create_bouton_tool_bar(t_sdl *s)
{
	s->hud1.bouton[12].i = 8;
	s->hud1.bouton[12].rect = init_sdl_rect(SIZE_X / 2 + COL4,
		SIZE_Y / 16 - 20, 40, 40);
	s->hud1.bouton[13].i = 6;
	s->hud1.bouton[13].rect = init_sdl_rect(SIZE_X / 2 + COL4 + 60,
		SIZE_Y / 16 - 20, 40, 40);
	s->hud1.bouton[14].i = 4;
	s->hud1.bouton[14].rect = init_sdl_rect(COL4 + 60, SIZE_Y / 16 - 20,
		40, 40);
	s->hud1.bouton[15].i = 10;
	s->hud1.bouton[15].rect = init_sdl_rect(COL4 + 120, SIZE_Y / 16 - 20,
		40, 40);
	s->hud1.bouton[16].i = 1;
	s->hud1.bouton[16].rect = init_sdl_rect(COL4 + 180, SIZE_Y / 16 - 20,
			40, 40);
	s->hud1.bouton[17].i = 10;
	s->hud1.bouton[17].rect = init_sdl_rect(COL + SIZE_X / 2 + 60, SIZE_Y / 16 - 15,
			30, 30);
	s->hud1.bouton[18].i = 10;
	s->hud1.bouton[18].rect = init_sdl_rect(COL + SIZE_X / 2 + 60, SIZE_Y / 16 - 15,
							30, 30);
}

void	bloc_work_space(t_env *e, t_sdl *s)
{
	t_vec	p1;
	t_vec	p2;

	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X, SIZE_Y / 8);
	p2 = init_point_2_coord(WIN_X, SIZE_Y / 8);
	horizontal_trait(p1, p2, CONTRAST, e);
	s->hud1.workspace_text.rect = init_sdl_rect(COL + SIZE_X, (SIZE_Y - 10) /
	16 - 10, COL - 20, 20);
	print_text(ft_strdup("Workspace"), s->font.color[4], s,
	&s->hud1.workspace_text);
}

void	call_blocs(t_env *e, t_sdl *s)
{
	bloc_logo(s);
	bloc_camera(e, s);
	bloc_save(e, s);
	bloc_credits(e, s);
	bloc_multiplier(e, s);
	bloc_work_space(e, s);
}

void	hud_init(t_sdl *s, t_env *e)
{
	t_rect	r1;
	t_vec	p1;
	t_vec	p2;

	init_font(s);
	open_texture(s);
	create_bouton_cam(s);
	init_info_messages(s);
	create_bouton_tool_bar(s);
	init_add_obj_text_box(s);
	init_add_obj_selection_rect(s);
	s->hud1.shape_img.rect = init_sdl_rect(SIZE_X / 4 + SIZE_X +
		(SIZE_X / 4 / 8), SIZE_Y / 8 + SIZE_Y / 16, SIZE_X / 5, SIZE_X / 5);
	if (!(e->hud = (Uint32*)malloc(sizeof(Uint32) * WIN_X * WIN_Y)))
		ft_error("MALLOC ERROR");
	r1 = init_rect(0, 0, WIN_X, WIN_Y);
	print_rect(r1, e, 1, COLOR_BACK);
	r1 = init_rect(SIZE_X / 4 - 10, SIZE_Y / 8 - 10, SIZE_X + 20, SIZE_Y + 20);
	print_rect(r1, e, 1, CONTRAST);
	call_blocs(e, s);
	p1 = init_point_2_coord(SIZE_X / 4 - 10, 0);
	p2 = init_point_2_coord(SIZE_X / 4 - 10, SIZE_Y / 8);
	vertical_trait(p1, p2, CONTRAST, e);
	p1 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 10, SIZE_Y);
	p2 = init_point_2_coord(SIZE_X / 4 + SIZE_X + 10, WIN_Y);
	vertical_trait(p1, p2, CONTRAST, e);
	s->hud1.s_back->pixels = e->hud;
	if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	print_text(ft_strdup(s->hud1.mess[0]), s->font.color[4], s, &s->hud1.info);
	s->hud1.info.rect = init_sdl_rect(SIZE_X / 4 + 28, (WIN_Y / 14) * 13.4 , 500, 25);
	s->hud1.color_selector = init_sdl_rect((WIN_X / 2) - 128 , (WIN_Y / 2) - 128, 256, 256);
	s->hud1.color_selector_surf = SDL_LoadBMP("./img_srcs/selector.bmp");
	s->hud1.ok.rect = init_sdl_rect(SIZE_X / 4 + SIZE_X + COL / 2 - 20, WIN_Y - SIZE_Y / 8, 40, 40);
}
