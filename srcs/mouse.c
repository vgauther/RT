/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:51:45 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/06 16:50:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void 	save_bouton(int x, int y, t_sdl *s, t_env *e)
{
	t_rect r1;

	if (x >= SIZE_X / 4 + SIZE_X - 110 && x <= SIZE_X / 4 + SIZE_X - 20)
	{
		printf("%s\n", "flute");
			if (SIZE_Y / 17 <= y && y <= SIZE_Y / 12)
			{
				printf("%s\n", "flute");

				r1 = init_rect(SIZE_X / 4 + SIZE_X - 110, SIZE_Y / 17, SIZE_X / 4 + SIZE_X - 20, SIZE_Y / 12);
				print_rect(r1, e, 1, RED);
				s->hud1.s_back->pixels = e->hud;
				if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
					ft_sdl_error("Texture error : ", SDL_GetError());
				display(s, e);
				r1 = init_rect(SIZE_X / 4 + SIZE_X - 110, SIZE_Y / 17, SIZE_X / 4 + SIZE_X - 20, SIZE_Y / 12);
				print_rect(r1, e, 1, WHITE);
				s->hud1.s_back->pixels = e->hud;
				if ((s->hud1.t_back = SDL_CreateTextureFromSurface(s->renderer, s->hud1.s_back)) == NULL)
					ft_sdl_error("Texture error : ", SDL_GetError());
				display(s, e);
				SDL_SaveBMP(s->rendu, "save.bmp");
			}
	}
}

void	main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e)
{
	save_bouton(mouse_x, mouse_y, s, e);
	/*t_rect r1;

	if (mouse_x >= SIZE_X / 4 + SIZE_X - 110 && mouse_x <= SIZE_X / 4 + SIZE_X - 20)
	{
		printf("%s\n", "flute");
			if (SIZE_Y / 17 <= mouse_y && mouse_y <= SIZE_Y / 12)
			{
				printf("%s\n", "flute");

				r1 = init_rect(SIZE_X / 4 + SIZE_X - 110, SIZE_Y / 17, SIZE_X / 4 + SIZE_X - 20, SIZE_Y / 12);
				print_rect(r1, e, 1, RED);
				s->hud1.s_back->pixels = e->hud;
				display(s, e);
				SDL_SaveBMP(s->rendu, "save.bmp");
			}
	}*/
	printf("%d|%d\n", mouse_x, mouse_y);
	if (mouse_x > 45 && mouse_x < 65)
	{
		if (mouse_y > 265 && mouse_y < 285)
		{
			s->hud1.bouton[3].i = 3;
			display(s, e);
			s->hud1.bouton[3].i = 1;
			e->ca.pos.x++;
		}
		if (mouse_y > 305 && mouse_y < 325)
		{
			s->hud1.bouton[4].i = 3;
			display(s, e);
			s->hud1.bouton[4].i = 1;
			e->ca.pos.y++;
		}
		if (mouse_y > 345 && mouse_y < 365)
		{
			s->hud1.bouton[5].i = 3;
			display(s, e);
			s->hud1.bouton[5].i = 1;
			e->ca.pos.z++;
		}
		raytracing(e, s);
	}
	else if (mouse_x > 70 && mouse_x < 90)
	{
		if (mouse_y > 265 && mouse_y < 285)
		{
			s->hud1.bouton[0].i = 2;
			display(s, e);
			s->hud1.bouton[0].i = 0;
			e->ca.pos.x--;
		}
		if (mouse_y > 305 && mouse_y < 325)
		{
			s->hud1.bouton[1].i = 2;
			display(s, e);
			s->hud1.bouton[1].i = 0;
			e->ca.pos.y--;
		}
		if (mouse_y > 345 && mouse_y < 365)
		{
			s->hud1.bouton[2].i = 2;
			display(s, e);
			s->hud1.bouton[2].i = 0;
			e->ca.pos.z--;
		}
		raytracing(e, s);
	}
	else if (mouse_x > 165 && mouse_x < 185)
	{
		if (mouse_y > 265 && mouse_y < 285)
		{
			s->hud1.bouton[6].i = 2;
			display(s, e);
			s->hud1.bouton[6].i = 0;
			e->ca.rot.x--;
		}
		if (mouse_y > 305 && mouse_y < 325)
		{
			s->hud1.bouton[7].i = 2;
			display(s, e);
			s->hud1.bouton[7].i = 0;
			e->ca.rot.y--;
		}
		if (mouse_y > 345 && mouse_y < 365)
		{
			s->hud1.bouton[8].i = 2;
			display(s, e);
			s->hud1.bouton[8].i = 0;
			e->ca.rot.z--;
		}
		raytracing(e, s);
	}
	else if (mouse_x > 140 && mouse_x < 160)
	{
		if (mouse_y > 265 && mouse_y < 285)
		{
			s->hud1.bouton[9].i = 3;
			display(s, e);
			s->hud1.bouton[9].i = 1;
			e->ca.rot.x++;
		}
		if (mouse_y > 305 && mouse_y < 325)
		{
			s->hud1.bouton[10].i = 3;
			display(s, e);
			s->hud1.bouton[10].i = 1;
			e->ca.rot.y++;
		}
		if (mouse_y > 345 && mouse_y < 365)
		{
			s->hud1.bouton[11].i = 3;
			display(s, e);
			s->hud1.bouton[11].i = 1;
			e->ca.rot.z++;
		}
		raytracing(e, s);
	}

}
