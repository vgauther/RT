/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vector_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:44:39 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/24 11:46:04 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		get_normal(t_env *e, t_inter pt, t_vec ori)
{
	t_vec norm;

	if (e->obj[pt.nb].type == 1)
		norm = sphere_normal_at(pt, e->obj[pt.nb]);
	else if (e->obj[pt.nb].type == 2)
		norm = cylindre_normal_at(pt, e->obj[pt.nb], ori);
	else if (e->obj[pt.nb].type == 4)
		norm = plan_normal_at(pt, e->obj[pt.nb], ori);
	else
		norm = cone_normal_at(pt, e->obj[pt.nb], ori);
	return (norm);
}

t_vec		add_vec(t_vec v1, t_vec v2)
{
	return (vector_init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}
