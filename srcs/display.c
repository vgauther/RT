/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:52 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 15:58:34 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	add_obj_selection_display(t_sdl *s)
{
	SDL_RenderCopy(s->renderer, s->tex[12], NULL, &s->hud1.r_add_obj[0]);
	SDL_RenderCopy(s->renderer, s->tex[13], NULL, &s->hud1.r_add_obj[1]);
	SDL_RenderCopy(s->renderer, s->tex[14], NULL, &s->hud1.r_add_obj[2]);
	SDL_RenderCopy(s->renderer, s->tex[15], NULL, &s->hud1.r_add_obj[3]);
}

void	add_obj_print_text(t_sdl *s, t_env *e, int nb)
{
	print_text(ft_itoa(e->obj[nb].pos.x), s->font.color[1], s,
	&s->hud1.add_obj_data[0]);
	print_text(ft_itoa(e->obj[nb].pos.y), s->font.color[1], s,
	&s->hud1.add_obj_data[1]);
	print_text(ft_itoa(e->obj[nb].pos.z), s->font.color[1], s,
	&s->hud1.add_obj_data[2]);
	print_text(ft_itoa(e->obj[nb].rot_to_print.x), s->font.color[1], s,
	&s->hud1.add_obj_data[3]);
	print_text(ft_itoa(e->obj[nb].rot_to_print.y), s->font.color[1], s,
	&s->hud1.add_obj_data[4]);
	print_text(ft_itoa(e->obj[nb].rot_to_print.z), s->font.color[1], s,
	&s->hud1.add_obj_data[5]);
}

void	display_add_obj_menu_bloc(t_sdl *s)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[0], NULL,
			&s->hud1.text_box[i])) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
		i++;
	}
}

void	display_add_obj_menu_data(t_sdl *s)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if ((SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[i].tex, NULL,
			&s->hud1.add_obj_data[i].rect)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
		i++;
	}
}

void	add_obj_menu(t_sdl *s, t_env *e, int nb)
{
	add_obj_print_text(s, e, nb);
	display_add_obj_menu_bloc(s);
	display_add_obj_menu_data(s);
	SDL_RenderCopy(s->renderer, s->tex[s->hud1.ok.i], NULL, &s->hud1.ok.rect);
}

void	display_cam(t_sdl *s)
{
	int		*r;
	int		i;

	if (!(r = (int*)malloc(sizeof(int) * 7)))
		ft_error("\nMalloc Error\n");
	r[0] = SDL_RenderCopy(s->renderer, s->hud1.cam.title.tex, NULL,
		&s->hud1.cam.title.rect);
	r[1] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_x.tex, NULL,
		&s->hud1.cam.pos_x.rect);
	r[2] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_y.tex, NULL,
		&s->hud1.cam.pos_y.rect);
	r[3] = SDL_RenderCopy(s->renderer, s->hud1.cam.pos_z.tex, NULL,
		&s->hud1.cam.pos_z.rect);
	r[4] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_x.tex, NULL,
		&s->hud1.cam.rot_x.rect);
	r[5] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_y.tex, NULL,
		&s->hud1.cam.rot_y.rect);
	r[6] = SDL_RenderCopy(s->renderer, s->hud1.cam.rot_z.tex, NULL,
		&s->hud1.cam.rot_z.rect);
	i = -1;
	while (++i < 7)
		if (r[i] < 0)
			ft_error("\nRender copy Error : Camera display\n");
	free(r);
}

void	display_all_bouton(t_sdl *s)
{
	int i;

	i = -1;
	while (++i != 17)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[s->hud1.bouton[i].i], NULL,
			&s->hud1.bouton[i].rect)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
	}
}

void	display_multi_text(t_sdl *s)
{
	if ((SDL_RenderCopy(s->renderer, s->hud1.multi_text[0].tex, NULL,
		&s->hud1.multi_text[0].rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.multi_text[1].tex, NULL,
		&s->hud1.multi_text[1].rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.multi_text[2].tex, NULL,
		&s->hud1.multi_text[2].rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->tex[0], NULL,
		&s->hud1.multi_bouton[s->hud1.multi])) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
}

void	display_work_space(t_sdl *s, t_env *e)
{
	if ((s->hud1.shape_img.i >= 12 && s->hud1.shape_img.i <= 15) ||
	s->hud1.add_obj == 2)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[s->hud1.shape_img.i], NULL,
			&s->hud1.shape_img.rect)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
	}
	if (s->hud1.add_obj == 1)
		add_obj_selection_display(s);
	if (s->hud1.add_obj == 2)
		add_obj_menu(s, e, e->nb - 1);
}

void	display_pipette(t_sdl *s)
{
	if (s->hud1.pipette == 1)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[16], NULL,
			&s->hud1.color_selector)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
	}
}

void	display_hud(t_sdl *s, t_env *e)
{
	SDL_RenderCopy(s->renderer, s->hud1.t_back, NULL, NULL);
	SDL_RenderCopy(s->renderer, s->hud1.info.tex, NULL, &s->hud1.info.rect);
	SDL_RenderCopy(s->renderer, s->hud1.logo.tex, NULL, &s->hud1.logo.rect);
	SDL_RenderCopy(s->renderer, s->hud1.save.tex, NULL, &s->hud1.save.rect);
	SDL_RenderCopy(s->renderer, s->hud1.workspace_text.tex, NULL,
		&s->hud1.workspace_text.rect);
	display_pipette(s);
	display_work_space(s, e);
	display_cam(s);
	display_credits(s);
	display_all_bouton(s);
	display_multi_text(s);
}

void	display(t_sdl *s, t_env *e)
{
	SDL_Rect	rendu_rect;

	SDL_RenderClear(s->renderer);
	recup_cam_to_print(s, e);
	s->rendu->pixels = e->pixels;
	rendu_rect = init_sdl_rect(SIZE_X / 4, SIZE_Y / 8, SIZE_X, SIZE_Y);
	if ((s->texture = SDL_CreateTextureFromSurface(s->renderer, s->rendu))
			== NULL)
		ft_sdl_error("Texture error : ", SDL_GetError());
	display_hud(s, e);
	if ((SDL_RenderCopy(s->renderer, s->texture, NULL, &rendu_rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	SDL_RenderPresent(s->renderer);
}
