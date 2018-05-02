/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:51:45 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 16:09:49 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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

void	mouse_color_obj(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= SIZE_X + COL4 + 20 && x <= SIZE_X + COL4 + 60)
	{
		if (y >= WIN_Y / 2 + LINE + 100 && y <= WIN_Y / 2 + LINE + 140)
			s->hud1.tok.change_color_obj =
			s->hud1.tok.change_color_obj == 1 ? 0 : 1;
	}
	(void)e;
}

void	mouse_color_obj_change(int x, int y, t_sdl *s, t_env *e)
{
	mouse_pipette_color(x, y, s, e);
	e->obj[s->hud1.tok.obj_select].color = s->hud1.color;
	raytracing(e, s);
}

void	mouse_change_reflect_trans(int x, int y, t_sdl *s, t_env *e)
{
	if (x >= s->hud1.option[0].rect.x && x <=
		s->hud1.option[0].rect.x + s->hud1.option[0].rect.w)
	{
		if (y >= s->hud1.option[0].rect.y && y <=
			s->hud1.option[0].rect.y + s->hud1.option[0].rect.h)
		{
			e->obj[s->hud1.tok.obj_select].reflex =
			e->obj[s->hud1.tok.obj_select].reflex == 1 ? 0 : 1;
			raytracing(e, s);
		}
	}
	if (x >= s->hud1.option[1].rect.x && x <=
		s->hud1.option[1].rect.x + s->hud1.option[1].rect.w)
	{
		if (y >= s->hud1.option[1].rect.y && y <=
			s->hud1.option[1].rect.y + s->hud1.option[1].rect.h)
		{
			e->obj[s->hud1.tok.obj_select].transp =
			e->obj[s->hud1.tok.obj_select].transp == 1 ? 0 : 1;
			raytracing(e, s);
		}
	}
}

void	main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	if (s->hud1.add_obj == 1 || s->hud1.add_obj == 2)
		mouse_add_obj_select(mouse_x, mouse_y, s, e);
	if (s->hud1.add_obj == 2 || s->hud1.tok.obj_select != -1)
		mouse_add_obj(mouse_x, mouse_y, s, e);
	if (s->hud1.selectobj == 1 && s->hud1.add_obj != 1 && s->hud1.pipette != 1)
		mouse_obj_seletor(mouse_x, mouse_y, s, e);
	if (s->hud1.pipette == 1 && s->hud1.tok.change_color_obj != 1)
		mouse_pipette_color(mouse_x, mouse_y, s, e);
	else if (s->hud1.tok.change_color_obj == 1 && s->hud1.pipette == 1)
		mouse_color_obj_change(mouse_x, mouse_y, s, e);
	if (s->hud1.tok.obj_select != -1)
	{
		mouse_change_reflect_trans(mouse_x, mouse_y, s, e);
		mouse_modify_ray_angle(mouse_x, mouse_y, s, e);
	}
	mouse_color_obj(mouse_x, mouse_y, s, e);
	mouse_light(mouse_x, mouse_y, s, e);
	if (mouse_x <= COL)
		mouse_main_cam(mouse_x, mouse_y, s, e);
	mouse_multi(mouse_x, mouse_y, s, e);
	if (mouse_y <= LINE)
		mouse_switch(mouse_x, mouse_y, s, e);
}
