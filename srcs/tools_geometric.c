/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_geometric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:04:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/28 15:12:48 by vgauther         ###   ########.fr       */
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

void	intersection_point(t_inter *pt, t_cam ca, t_vec v)
{
	pt->x = ca.x + v.x * pt->dist;
	pt->y = ca.y + v.y * pt->dist;
	pt->z = ca.z + v.z * pt->dist;
}
