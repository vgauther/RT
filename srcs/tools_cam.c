/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:02:18 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 14:02:51 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_cam	init_cam(int x, int y, int z)
{
	t_cam c;

	c.pos.x = x;
	c.pos.y = y;
	c.pos.z = z;
	c.rot.x = CAM_ROT_X;
	c.rot.y = CAM_ROT_Y;
	c.rot.z = CAM_ROT_Z;
	return (c);
}
