/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:04:37 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/17 14:08:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_point		init_point(double x, double y, double z)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

void	intersection_point(t_inter *pt, t_cam ca, t_vec v)
{
	pt->x = ca.xr + v.x * pt->dist;
	pt->y = ca.yr + v.y * pt->dist;
	pt->z = ca.zr + v.z * pt->dist;
}
