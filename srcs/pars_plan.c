/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:31:27 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/26 15:35:54 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 11)
		ret = 0;
	return (ret);
}

void		add_plan(t_env *e, char **sp)
{
	t_obj	*new;
	t_vec	norm;

	if (!check_param(sp))
		ft_error("Wrong plan parameters.");
	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		ft_error("Failed to malloc new plan.");
	new->pos = vector_init(ft_atoi(sp[1]), ft_atoi(sp[2]), ft_atoi(sp[3]));
	new->color = ft_atoi_color(only_color(sp[4]));
	norm = vector_init(ft_atoi(sp[5]), ft_atoi(sp[6]), ft_atoi(sp[7]));
	new->rot = normalize_vec(norm);
	new->type = 4;
	e->obj[e->nb] = *new;
	e->obj[e->nb].num = e->nb;
	e->obj[e->nb].material = ft_atoi(sp[8]);
	e->obj[e->nb].reflex = ft_atoi(sp[9]);
	e->obj[e->nb].transp = ft_atoi(sp[10]);
	e->obj[e->nb].rot_to_print = vector_init(ft_atoi(sp[5]), ft_atoi(sp[6]),
	ft_atoi(sp[7]));
	free(new);
}
