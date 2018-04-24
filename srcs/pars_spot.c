/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:30:47 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/24 13:52:44 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int		ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 8)
		ret = 0;
//else if (!check_value(sp[5]))
//ret = 0;
	return (ret);
}

void		add_spot(t_env *e, char **sp)
{
	if (!check_param(sp))
		ft_error("Wrong spot parameters.");
	e->spot[e->nb_spot].pos = init_point(ft_atoi(sp[1]),
	ft_atoi(sp[2]), ft_atoi(sp[3]));
	e->spot[e->nb_spot].rot = vector_init(ft_atoi(sp[5]),
	ft_atoi(sp[6]), ft_atoi(sp[7]));
	e->spot[e->nb_spot].color = ft_atoi_color(only_color(sp[4]));
}
