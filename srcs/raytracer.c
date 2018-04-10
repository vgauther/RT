/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/10 13:36:41 by vgauther         ###   ########.fr       */
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
				dir = normalize_vec(dir);
				tmp = shape_redirection(e, dir, e->ca.pos, nbr);
				if (tmp.dist < pt.dist)
				{
					pt.dist = tmp.dist;
					pt.pos.x = tmp.pos.x;
					pt.pos.y = tmp.pos.y;
					pt.pos.z = tmp.pos.z;
					pt.normal = tmp.normal;
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
	display(s, e);
}

int			ray_shadow(t_env *e, t_inter pt, t_obj spot, int nb)
{
	int		j;
	t_vec	dir;
	t_inter tmp;
	double	dist;

	j = 0;
	(void)nb;
	dir = vector_init(pt.pos.x - spot.pos.x,
	pt.pos.y - spot.pos.y, pt.pos.z - spot.pos.z);
	dist = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	dir = normalize_vec(dir);
	while (j < e->nb)
	{
		tmp = shape_redirection(e, dir, spot.pos, j);
		if (tmp.dist > 0 && tmp.dist < dist)
			if (dist - 1 > tmp.dist)
				return (1);
		j++;
	}
	return (0);
}
