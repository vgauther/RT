/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:30:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/03 16:11:09 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 10)
		ret = 0;
	else if (!check_value(sp[5]))
		ret = 0;
	return (ret);
}

void		add_cone(t_env *e, char **sp)
{
	if (!check_param(sp))
		ft_error("Wrong cone parameters.");
	e->obj[e->nb].pos = init_point(ft_atoi(sp[1]),
	ft_atoi(sp[2]), ft_atoi(sp[3]));
	e->obj[e->nb].angle = ft_atoi(sp[5]);
	e->obj[e->nb].angle = tan((e->obj[e->nb].angle / 2) * RAD);
	e->obj[e->nb].rot.x = ft_atoi(sp[6]);
	e->obj[e->nb].rot.y = ft_atoi(sp[7]);
	e->obj[e->nb].rot.z = ft_atoi(sp[8]);
	e->obj[e->nb].material = ft_atoi(sp[9]);
	e->obj[e->nb].color = ft_atoi_color(only_color(sp[4]));
	e->obj[e->nb].type = 3;
}
