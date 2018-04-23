/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:31:23 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/23 12:02:15 by vgauther         ###   ########.fr       */
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
	e->obj[e->nb].pos = init_point(ft_atoi(sp[1]),
	ft_atoi(sp[2]), ft_atoi(sp[3]));
	e->obj[e->nb].rayon = ft_atoi(sp[5]);
	e->obj[e->nb].rayon_2 = e->obj[e->nb].rayon * e->obj[e->nb].rayon;
	e->obj[e->nb].material = ft_atoi(sp[6]);
	e->obj[e->nb].color = ft_atoi_color(only_color(sp[4]));
	e->obj[e->nb].type = 1;
	e->obj[e->nb].num = e->nb;
	e->obj[e->nb].rot = vector_init(0, 0, 0);
	e->obj[e->nb].rot = normalize_vec(e->obj[e->nb].rot);
	e->obj[e->nb].rot_to_print = e->obj[e->nb].rot;
}
