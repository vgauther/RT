/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/03/29 15:50:29 by fde-souz         ###   ########.fr       */
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

void	raytracing(t_env *e, t_sdl s)
{
	int			x;
	int			y;
	int			nbr;
	int			token;
	t_inter		pt;
	t_inter		tmp;
	t_vec		dir;

	token = 42;
	x = 0;
	while (x != SIZE_X)
	{
		y = 0;
		while (y != SIZE_Y)
		{
			nbr = 0;
			token = 42;
			while (nbr < e->nb)
			{
				dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
				tmp = shape_redirection(e, dir, e->ca.pos, nbr);
				if (((tmp.dist < pt.dist || pt.dist < 0) && tmp.dist >= 0) || token == 42)
				{
					pt.dist = tmp.dist;
					pt.x = tmp.x;
					pt.y = tmp.y;
					pt.z = tmp.z;
					pt.nb = nbr;
					token = 0;
				}
				nbr++;
			}
			if (pt.dist >= 0)
				ft_put_pixel_winrend(e->pixels, x, y, lux(e, pt));
			y++;
		}
		x++;
	}
	s.rendu->pixels = e->pixels;
	display(&s);
}

/*int			ray_shadow(t_env *e, t_sdl s, t_point ori)
{
	int		nbr;
	t_vec	dir;
	t_inter	p;

	nbr = 0;
	while (nbr < e->nb)
	{
		dir = vector_init(x - SIZE_X_2, y - SIZE_Y_2, SIZE_X_2 / TAN30);
		p = shape_redirection(e, dir, e->ca.pos, nbr);
		if (((tmp.dist < pt.dist || pt.dist < 0) && tmp.dist >= 0) || token == 42)
		{
			pt.dist = tmp.dist;
			pt.x = tmp.x;
			pt.y = tmp.y;
			pt.z = tmp.z;
			pt.nb = nbr;
			token = 0;
		}
		nbr++;
	}

}*/
