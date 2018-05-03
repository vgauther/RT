/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:30:51 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/03 15:31:45 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 14)
		ret = 0;
	else if (!check_value(sp[5]))
		ret = 0;
	return (ret);
}

void		add_cylindre(t_env *e, char **sp)
{
	if (!check_param(sp))
		ft_error("Wrong cylindre parameters.");
	e->obj[e->nb].pos = init_point(ft_atoi(sp[1]), ft_atoi(sp[2]),
	ft_atoi(sp[3]));
	e->obj[e->nb].rayon = ft_atoi(sp[5]);
	e->obj[e->nb].rayon_2 = e->obj[e->nb].rayon * e->obj[e->nb].rayon;
	e->obj[e->nb].rot.x = ft_atoi(sp[6]);
	e->obj[e->nb].rot.y = ft_atoi(sp[7]);
	e->obj[e->nb].rot.z = ft_atoi(sp[8]);
	e->obj[e->nb].rot_to_print = e->obj[e->nb].rot;
	e->obj[e->nb].rot = normalize_vec(e->obj[e->nb].rot);
	e->obj[e->nb].material = ft_atoi(sp[9]);
	e->obj[e->nb].color = ft_atoi_color(only_color(sp[4]));
	e->obj[e->nb].type = 2;
	e->obj[e->nb].num = e->nb;
	e->obj[e->nb].reflex = ft_atoi(sp[10]);
	e->obj[e->nb].transp = ft_atoi(sp[11]);
	e->obj[e->nb].fin = ft_atoi(sp[12]);
	e->obj[e->nb].taille = ft_atoi(sp[13]);
}
