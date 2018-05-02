/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <ebertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:42:57 by ebertin           #+#    #+#             */
/*   Updated: 2018/05/02 17:44:46 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_obj	realloc_sphere(t_env *e, int i)
{
	t_obj ret;

	ret.pos = init_point(e->obj[i].pos.x, e->obj[i].pos.y, e->obj[i].pos.z);
	ret.rayon = e->obj[i].rayon;
	ret.rayon_2 = e->obj[i].rayon_2;
	ret.material = e->obj[i].material;
	ret.color = e->obj[i].color;
	ret.type = 1;
	ret.num = e->obj[i].num;
	ret.rot.x = e->obj[i].rot.x;
	ret.rot.y = e->obj[i].rot.y;
	ret.rot.z = e->obj[i].rot.z;
	ret.rot = normalize_vec(ret.rot);
	ret.rot_to_print = e->obj[i].rot_to_print;
	ret.reflex = e->obj[i].reflex;
	ret.transp = e->obj[i].transp;
	if (ret.material == 2)
	{
		ret.name = ft_strdup(e->obj[i].name);
		free(e->obj[i].name);
		ret.tex = load_texture(ret.name);
		SDL_FreeSurface(e->obj[i].tex);
	}
	return (ret);
}
