/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:05:50 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/27 15:44:24 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double	dot(t_vec v1, t_vec v2)
{
	double x;

	x = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (x);
}

t_vec	vector_init(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	normalize_vec(t_vec ret)
{
	double norm;

	norm = sqrt(dot(ret, ret));
	ret.x /= norm;
	ret.y /= norm;
	ret.z /= norm;
	return (ret);
}
