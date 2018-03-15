/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:30:47 by ppetit            #+#    #+#             */
/*   Updated: 2018/03/15 12:31:51 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 8)
		ret = 0;
	else if (!check_value(sp[5]))
		ret = 0;
	return (ret);
}

void		add_spot(t_env *e, char **sp)
{
	t_obj			*new;

	if (!check_param(sp))
		ft_error("Wrong spot parameters.");
	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		ft_error("Failed to malloc new spot.");
	new->pos = new_vec(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
	new->rot = new_vec(ft_atoi(sp[5]), ft_atoi(sp[6]), ft_atoi(sp[7]));
	new->color = ft_atoi_color(only_color(sp[4]));
	e->obj[e->nb] = *new;
	free(new);
}
