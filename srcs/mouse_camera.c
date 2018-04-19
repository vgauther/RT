
#include "../includes/rt.h"

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

void mouse_main_cam(int x, int y, t_sdl *s, t_env *e)
{
  mouse_cam_trans(x, y, s, e);
  mouse_cam_rot(x, y, s, e);
}
