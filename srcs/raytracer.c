/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/17 13:33:58 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		get_closest(t_env *e, t_inter *pt, int x, int y)
{
	int		nbr;
	t_inter	tmp;
	t_vec	dir;

	nbr = 0;
	pt->dist = MAX_DIST;
	while (nbr < e->nb)
	{
		dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
		dir = ft_rotate(dir, e->ca.rot.x, e->ca.rot.y, e->ca.rot.z);
		dir = normalize_vec(dir);
		tmp = shape_redirection(e, dir, e->ca.pos, nbr);
		if (tmp.dist < pt->dist && tmp.dist > 0)
		{
			pt->dist = tmp.dist;
			pt->pos = init_point(tmp.pos.x, tmp.pos.y, tmp.pos.z);
			pt->normal = tmp.normal;
			pt->nb = nbr;
		}
		nbr++;
	}
}

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
	t_inter		pt;
	Uint32		color;

	x = 0;
	while (x != SIZE_X)
	{
		y = 0;
		while (y != SIZE_Y)
		{
			get_closest(e, &pt, x, y);
			if (pt.dist != MAX_DIST)
			{
				color = filtre(s, lux(e, pt));
				ft_put_pixel_winrend(e->pixels, x, y, color);
			}
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
		if (dist - 1 > tmp.dist && tmp.dist > 0)
			return (1);
		j++;
	}
	return (0);
}
