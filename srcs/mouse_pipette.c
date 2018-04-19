
#include "../includes/rt.h"

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
	(void)x;
	(void)y;
	(void)s;
	(void)e;
	/*Uint32 color;
	char *tab;

//	x -= WIN_X / 2 - 125;
	//y -= WIN_Y / 2 - 125;
	printf("%d|%d\n",x, y);
	if (x >= 0 && x <= 256)
	{
		if (y >= 0 && y <= 256)
		{
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
	//}*/
}
