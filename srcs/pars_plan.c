/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:31:27 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/19 12:20:47 by ppetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 8)
		ret = 0;
	// else if (!check_value(sp[5]))
	// 	ret = 0;
	return (ret);
}

void		add_plan(t_env *e, char **sp)
{
	t_obj	*new;
	t_vec 	norm;

	if (!check_param(sp))
		ft_error("Wrong plan parameters.");
	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		ft_error("Failed to malloc new plan.");
	new->pos = vector_init(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
	new->color = ft_atoi_color(only_color(sp[4]));
	norm = vector_init(ft_atoi(sp[5]), ft_atoi(sp[6]), ft_atoi(sp[7]));
	new->norm = normalize_vec(norm);
	new->type = 4;
	e->obj[e->nb] = *new;
	free(new);
}
