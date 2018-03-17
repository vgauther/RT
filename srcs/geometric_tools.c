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
