/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:29:57 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 16:04:51 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		do_we_need_to_rt(int t)
{
	if (t == CAM_LEFT || t == CAM_RIGHT || t == CAM_DOWN ||
		t == CAM_UP || t == CAM_FOR || t == CAM_BACK)
		return (1);
	return (0);
}

int		nbr_touch(int key)
{
	if (key == 39 || key == 98)
		return (0);
	else if (key == 30 || key == 89)
		return (1);
	else if (key == 31 || key == 90)
		return (2);
	else if (key == 32 || key == 91)
		return (3);
	else if (key == 33 || key == 92)
		return (4);
	else if (key == 34 || key == 93)
		return (5);
	else if (key == 35 || key == 94)
		return (6);
	else if (key == 36 || key == 95)
		return (7);
	else if (key == 37 || key == 96)
		return (8);
	else if (key == 38 || key == 97)
		return (9);
	else if (key == 86 || key == 45)
		return (-1);
	return (42);
}
