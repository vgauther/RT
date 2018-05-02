/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:25:55 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/02 17:43:13 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_obj	realloc_plan(t_env *e, int i)
{
	t_obj ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.color = e->obj[i].color;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.material = e->obj[i].material;
	ret.type = 4;
	ret.num = e->obj[i].num;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	realloc_cone(t_env *e, int i)
{
	t_obj ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.angle = e->obj[i].angle;
	ret.angletan = e->obj[i].angletan;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot = normalize_vec(ret.rot);
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 3;
	ret.num = e->obj[i].num;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	realloc_cylindre(t_env *e, int i)
{
	t_obj ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.rayon = e->obj[i].rayon;
	ret.rayon_2 = e->obj[i].rayon_2;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.rot = normalize_vec(ret.rot);
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 2;
	ret.num = e->obj[i].num;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	realloc_disque(t_env *e, int i)
{
	t_obj ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.rayon = e->obj[i].rayon;
	ret.rayon_2 = e->obj[i].rayon_2;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.transp = e->obj[i].transp;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.rot = normalize_vec(ret.rot);
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 5;
	ret.num = e->obj[i].num;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	return (ret);
}

t_obj	*realloc_obj(t_env *e)
{
	t_obj	*new;
	int		i;

	i = 0;
	e->nb++;
	if (!(new = (t_obj *)malloc(sizeof(t_obj) * e->nb)))
		ft_error("malloc error\n");
	while (i != e->nb - 1)
	{
		if (e->obj[i].type == 2)
			new[i] = realloc_cylindre(e, i);
		else if (e->obj[i].type == 3)
			new[i] = realloc_cone(e, i);
		else if (e->obj[i].type == 4)
			new[i] = realloc_plan(e, i);
		else if (e->obj[i].type == 1)
			new[i] = realloc_sphere(e, i);
		else if (e->obj[i].type == 5)
			new[i] = realloc_disque(e, i);
		else
			ft_error("realloc error\n");
		i++;
	}
	free(e->obj);
	return (new);
}
