/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:26:25 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/27 16:26:34 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	x(double *y, double *z, double rot_x)
{
	*y = cos(rot_x * RAD) * *y - sin(rot_x * RAD) * *z;
	*z = sin(rot_x * RAD) * *y + cos(rot_x * RAD) * *z;
}

void	y(double *x, double *z, double rot_y)
{
	*x = cos(rot_y * RAD) * *x + sin(rot_y * RAD) * *z;
	*z = -sin(rot_y * RAD) * *x + cos(rot_y * RAD) * *z;
}

void	z(double *x, double *y, double rot_z)
{
	*x = cos(rot_z * RAD) * *x - sin(rot_z * RAD) * *y;
	*y = sin(rot_z * RAD) * *x + cos(rot_z * RAD) * *y;
}

t_vec			ft_rotate(t_vec p, double rot_x, double rot_y, double rot_z)
{
	int					x;
	int					y;
	int					z;
	t_vec				v;

	v.x = p.x;
	v.y = p.y;
	v.z = p.z;
	x = v.x;
	z = v.z;
	v.x = cos(rot_y * RAD) * x + sin(rot_y * RAD) * z;
	v.z = -sin(rot_y * RAD) * x + cos(rot_y * RAD) * z;
	y = v.y;
	z = v.z;
	v.y = cos(rot_x * RAD) * y - sin(rot_x * RAD) * z;
	v.z = sin(rot_x * RAD) * y + cos(rot_x * RAD) * z;
	x = v.x;
	y = v.y;
	v.x = cos(rot_z * RAD) * x - sin(rot_z * RAD) * y;
	v.y = sin(rot_z * RAD) * x + cos(rot_z * RAD) * y;
	return (v);
}
