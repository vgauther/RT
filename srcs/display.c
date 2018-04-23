/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:52 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 14:58:15 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	add_obj_selection_display(t_sdl *s, t_env *e)
{
	(void)e;
	SDL_RenderCopy(s->renderer, s->tex[12], NULL, &s->hud1.r_add_obj[0]);
	SDL_RenderCopy(s->renderer, s->tex[13], NULL, &s->hud1.r_add_obj[1]);
	SDL_RenderCopy(s->renderer, s->tex[14], NULL, &s->hud1.r_add_obj[2]);
	SDL_RenderCopy(s->renderer, s->tex[15], NULL, &s->hud1.r_add_obj[3]);
}

void 	add_obj_print_text(t_sdl *s, t_env *e, int nb)
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

void	add_obj_menu(t_sdl *s, t_env *e, int nb)
{
	add_obj_print_text(s, e, nb);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[0]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[1]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[2]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[3]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[4]);
	SDL_RenderCopy(s->renderer, s->tex[0], NULL, &s->hud1.text_box[5]);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[0].tex, NULL, &s->hud1.add_obj_data[0].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[1].tex, NULL, &s->hud1.add_obj_data[1].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[2].tex, NULL, &s->hud1.add_obj_data[2].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[3].tex, NULL, &s->hud1.add_obj_data[3].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[4].tex, NULL, &s->hud1.add_obj_data[4].rect);
	SDL_RenderCopy(s->renderer, s->hud1.add_obj_data[5].tex, NULL, &s->hud1.add_obj_data[5].rect);
	SDL_RenderCopy(s->renderer, s->tex[s->hud1.ok.i], NULL, &s->hud1.ok.rect);
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
