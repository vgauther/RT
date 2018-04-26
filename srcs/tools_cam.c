/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:02:18 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/26 12:14:28 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_cam	init_cam(void)
{
	t_cam c;

	c.pos.x = CAM_POS_X;
	c.pos.y = CAM_POS_Y;
	c.pos.z = CAM_POS_Z;
	c.rot.x = CAM_ROT_X;
	c.rot.y = CAM_ROT_Y;
	c.rot.z = CAM_ROT_Z;
	return (c);
}
