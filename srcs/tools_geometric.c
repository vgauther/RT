/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_geometric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:04:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/30 14:01:30 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*
** initialization of a point (norm funct)
*/

t_point		init_point(double x, double y, double z)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

/*
** we determinate coordonnates of the intersection between a ray and the shape
*/

void	intersection_point(t_inter *pt, t_point ca, t_vec v)
{
	pt->pos.x = ca.x + v.x * pt->dist;
	pt->pos.y = ca.y + v.y * pt->dist;
	pt->pos.z = ca.z + v.z * pt->dist;
}

t_rect	init_rect(int x1, int x2, int x3, int x4)
{
	t_rect r;

	r.x_begin = x1;
	r.y_begin = x2;
	r.x_end = x3;
	r.y_end = x4;
	return (r);
}

void	print_rect(t_rect b, t_env *e, int t, int color)
{
	int save;

	if (b.y_begin > b.y_end || b.x_begin > b.x_end)
		ft_error("\nbouton error\n");
	save = b.x_begin;
	while (b.y_begin < b.y_end)
	{
		b.x_begin = save;
		while (b.x_begin < b.x_end)
		{
			t == 1 ? ft_put_pixel_hud(e->hud, b.x_begin, b.y_begin, color) :
			ft_put_pixel_winrend(e->pixels, b.x_begin, b.y_begin, color);
			b.x_begin++;
		}
		b.y_begin++;
	}
}
