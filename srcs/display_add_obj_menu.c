/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_add_obj_menu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:23:48 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/30 19:25:28 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			add_obj_selection_display(t_sdl *s)
{
	SDL_RenderCopy(s->renderer, s->tex[12], NULL, &s->hud1.r_add_obj[0]);
	SDL_RenderCopy(s->renderer, s->tex[13], NULL, &s->hud1.r_add_obj[1]);
	SDL_RenderCopy(s->renderer, s->tex[14], NULL, &s->hud1.r_add_obj[2]);
	SDL_RenderCopy(s->renderer, s->tex[15], NULL, &s->hud1.r_add_obj[3]);
}

static void		add_obj_print_text(t_sdl *s, t_env *e, int nb)
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
	if (e->obj[s->hud1.tok.obj_select].type == 1 ||
		e->obj[s->hud1.tok.obj_select].type == 2)
		print_text(ft_itoa(e->obj[nb].rayon), s->font.color[1], s,
		&s->hud1.add_obj_data[6]);
	else if (e->obj[s->hud1.tok.obj_select].type == 3)
		print_text(ft_itoa(e->obj[nb].angle), s->font.color[1], s,
		&s->hud1.add_obj_data[6]);
}

static void		display_add_obj_menu_bloc(t_sdl *s, t_env *e, int nb)
{
	int i;
	int stop;

	i = 0;
	stop = e->obj[nb].type == 1 ? 3 : 6;
	while (i < stop)
	{
		if ((SDL_RenderCopy(s->renderer, s->tex[0], NULL,
			&s->hud1.text_box[i])) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
		i++;
	}
}

static void		display_add_obj_menu_data(t_sdl *s, t_env *e, int nb)
{
	int i;
	int stop;

	i = 0;
	stop = e->obj[nb].type == 1 ? 3 : 6;
	while (i < stop)
	{
		if ((SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[i].tex, NULL,
			&s->hud1.add_obj_data[i].rect)) < 0)
			ft_sdl_error("Texture error : ", SDL_GetError());
		i++;
	}
	if ((SDL_RenderCopy(s->renderer, s->hud1.color_text.tex, NULL,
		&s->hud1.color_text.rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.reflex_text.tex, NULL,
		&s->hud1.reflex_text.rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
	if ((SDL_RenderCopy(s->renderer, s->hud1.transpa_text.tex, NULL,
		&s->hud1.transpa_text.rect)) < 0)
		ft_sdl_error("Texture error : ", SDL_GetError());
}

void			add_obj_menu(t_sdl *s, t_env *e, int nb)
{
	add_obj_print_text(s, e, nb);
	display_add_obj_menu_bloc(s, e, nb);
	display_add_obj_menu_data(s, e, nb);
}
