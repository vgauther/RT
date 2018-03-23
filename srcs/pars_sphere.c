/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:31:23 by ppetit            #+#    #+#             */
/*   Updated: 2018/03/23 14:25:29 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 7)
		ret = 0;
	else if (!check_value(sp[5]))
		ret = 0;
	return (ret);
}

void		add_sphere(t_env *e, char **sp)
{
	if (!check_param(sp))
		ft_error("Wrong sphere parameters.");
	e->obj[e->nb].pos = vector_init(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
	e->obj[e->nb].rayon = ft_atoi(sp[5]);
	e->obj[e->nb].material = ft_atoi(sp[6]);
	e->obj[e->nb].color = ft_atoi_color(only_color(sp[4]));
	e->obj[e->nb].type = 1;
}
