/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:31:23 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/25 14:01:00 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	check_param(char **sp)
{
	int			ret;

	ret = 1;
	if (ft_tablen((void **)sp) != 9)
		ret = 0;
	else if (!check_value(sp[5]))
		ret = 0;
	return (ret);
}

SDL_Surface	*load_texture(char *texture)
{
	SDL_Surface *surf;

	if ((surf = SDL_LoadBMP(texture)) == NULL)
		ft_error("\n Texture load error\n");
	return (surf);
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
	if (e->obj[e->nb].material == 2)
		e->obj[e->nb].tex = load_texture(sp[8]);
	e->obj[e->nb].color = ft_atoi_color(only_color(sp[8]));
	e->obj[e->nb].type = 1;
	e->obj[e->nb].num = e->nb;
	e->obj[e->nb].rot = vector_init(0, 0, 0);
	e->obj[e->nb].rot = normalize_vec(e->obj[e->nb].rot);
	e->obj[e->nb].rot_to_print = e->obj[e->nb].rot;
	e->obj[e->nb].reflex = ft_atoi(sp[7]);
}
