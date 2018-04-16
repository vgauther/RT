/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:05:50 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/16 13:29:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*
** classic dot product
*/

double	dot(t_vec v1, t_vec v2)
{
	double x;

	x = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (x);
}

/*
** square of a classic dot product (optimization)
*/

double	dot_2(t_vec v1, t_vec v2)
{
	double x;

	x = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	x *= x;
	return (x);
}

/*
** creation of a vector (norm function)
*/

t_vec	vector_init(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

/*
** classic normalization of a vector
*/

t_vec	normalize_vec(t_vec ret)
{
	double norm;

	norm = sqrt(dot(ret, ret));
	ret.x /= norm;
	ret.y /= norm;
	ret.z /= norm;
	return (ret);
}
