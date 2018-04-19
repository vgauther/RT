/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_geometric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:04:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/17 15:48:57 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*
** initialization of a point (norm funct)
*/

t_vec		init_point(double x, double y, double z)
{
	t_vec p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

/*
** initialization of a point but only on x and y(norm funct)
*/

t_vec		init_point_2_coord(int x, int y)
{
	t_vec p;

	p.x = x;
	p.y = y;
	return (p);
}

/*
** we determinate coordonnates of the intersection between a ray and the shape
*/

void		intersection_point(t_inter *pt, t_vec ca, t_vec v)
{
	pt->pos.x = ca.x + v.x * pt->dist;
	pt->pos.y = ca.y + v.y * pt->dist;
	pt->pos.z = ca.z + v.z * pt->dist;
}

t_rect		init_rect(int x1, int x2, int x3, int x4)
{
	t_rect r;

	r.x = x1;
	r.y = x2;
	r.len = x3;
	r.hei = x4;
	return (r);
}

void		print_rect(t_rect b, t_env *e, int t, int color)
{
	int i;
	int j;
	int save;

	i = b.y + b.hei;
	j = b.x + b.len;
	save = b.x;
	while (i > b.y)
	{
		b.x = save;
		while (j > b.x)
		{
			t == 1 ? ft_put_pixel_hud(e->hud, b.x, b.y, color) :
			ft_put_pixel_winrend(e->pixels, b.x, b.y, color);
			b.x++;
		}
		b.y++;
	}
}
