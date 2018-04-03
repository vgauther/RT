/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/03 13:13:15 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_inter		shape_redirection(t_env *e, t_vec dir, t_point ori, int nbr)
{
	t_inter tmp;

	if (e->obj[nbr].type == 1)
	{
		tmp = ray_sphere(e, dir, ori, nbr);
	}
	else if (e->obj[nbr].type == 2)
	{
		tmp = ray_cylindre(e, dir, ori, nbr);
	}
	else//if (e->obj[nbr].type == 3)
	{
		tmp = ray_cone(e, dir, ori, nbr);
	}
	return (tmp);
}

void	raytracing(t_env *e, t_sdl *s)
{
	int			x;
	int			y;
	int			nbr;
	t_inter		pt;
	t_inter		tmp;
	t_vec		dir;

	x = 0;
	while (x != SIZE_X)
	{
		y = 0;
		while (y != SIZE_Y)
		{
			nbr = 0;
			pt.dist = MAX_DIST;
			while (nbr < e->nb)
			{
				dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
				tmp = shape_redirection(e, dir, e->ca.pos, nbr);
				if (tmp.dist < pt.dist)
				{
					pt.dist = tmp.dist;
					pt.pos.x = tmp.pos.x;
					pt.pos.y = tmp.pos.y;
					pt.pos.z = tmp.pos.z;
					pt.nb = nbr;
				}
				nbr++;
			}
			if (pt.dist != MAX_DIST)
				ft_put_pixel_winrend(e->pixels, x, y, lux(e, pt));
			else
				ft_put_pixel_winrend(e->pixels, x, y, 0);
			y++;
		}
		x++;
	}
	s->rendu->pixels = e->pixels;
	display(s);
}

int			ray_shadow(t_env *e, t_point pt, t_obj spot, int nb)
{
	int		j;
	t_vec	dir;
	t_inter tmp;

	j = 0;
	dir = normalize_vec(vector_init(pt.x - spot.pos.x,
	pt.y - spot.pos.y, pt.z - spot.pos.z));
	while (j < e->nb)
	{
		tmp = shape_redirection(e, dir, spot.pos, j);
		if (j != nb)
		{
			if (tmp.delta >= 0 && tmp.dist > 0)
				return (1);
		}
		j++;
	}
	return (0);
}
