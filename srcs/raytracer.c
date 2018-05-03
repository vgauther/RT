/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/05/03 15:39:08 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		get_closest(t_env *e, t_inter *pt, t_vec dir, t_vec ori)
{
	int		nbr;
	t_inter	tmp;

	nbr = 0;
	pt->dist = MAX_DIST;
	while (nbr < e->nb)
	{
		tmp = shape_redirection(e, dir, ori, nbr);
		if (tmp.dist < pt->dist && tmp.dist > 0)
		{
			pt->dist = tmp.dist;
			pt->pos = init_point(tmp.pos.x, tmp.pos.y, tmp.pos.z);
			pt->normal = tmp.normal;
			pt->nb = nbr;
			pt->normal = get_normal(e, *pt, e->ca.pos);
		}
		nbr++;
	}
}

t_inter		shape_redirection(t_env *e, t_vec dir, t_vec ori, int nbr)
{
	t_inter tmp;

	if (e->obj[nbr].type == 1)
		tmp = ray_sphere(e, dir, ori, nbr);
	else if (e->obj[nbr].type == 3)
		tmp = ray_cone(e, dir, ori, nbr);
	else if (e->obj[nbr].type == 4)
		tmp = ray_plan(e, dir, ori, nbr);
	else if (e->obj[nbr].type == 5)
		tmp = ray_disque(e, dir, ori, nbr);
	else if (e->obj[nbr].type == 2 && !e->obj[nbr].fin)
		tmp = ray_cylindre(e, dir, ori, nbr);
	else
		tmp = ray_cylindre_fin(e, dir, ori, nbr);
	return (tmp);
}

void		*threadt(void *param)
{
	t_thread_st		*var;
	t_inter			pt;
	int				xlim;
	int				y;
	int				depth;

	var = (t_thread_st*)param;
	xlim = var->x + (SIZE_X / NB_THREAD);
	while (var->x < xlim)
	{
		y = 0;
		while (++y < SIZE_Y)
		{
			depth = 0;
			get_closest(var->e, &pt, calc_dir_vec(var->x, y, var->e),
			var->e->ca.pos);
			if (pt.dist != MAX_DIST)
				ft_put_pixel_winrend(var->e->pixels, var->x, y,
					proces_color(var->e, var->s, pt));
			else
				ft_put_pixel_winrend(var->e->pixels, var->x, y, 0);
		}
		var->x++;
	}
	return (NULL);
}

static void	init_util_thread(t_env *e, t_sdl *s, t_thread_util *util_th)
{
	int				x;
	int				i;

	i = 0;
	x = 0;
	while (i < NB_THREAD)
	{
		util_th[i].thread_param.x = x;
		util_th[i].thread_param.e = e;
		util_th[i].thread_param.s = s;
		x += SIZE_X / NB_THREAD;
		i++;
	}
}

void		raytracing(t_env *e, t_sdl *s)
{
	t_thread_util	*util_th;
	int				i;

	if (!(util_th = (t_thread_util*)malloc(sizeof(t_thread_util) * NB_THREAD)))
		ft_error("\n Malloc error.\n");
	loading_screen(4, s);
	init_util_thread(e, s, util_th);
	i = -1;
	while (++i < NB_THREAD)
		if ((util_th[i].ret = pthread_create(&util_th[i].thread,
			NULL, threadt, &util_th[i].thread_param)))
			ft_error("\nThread error.\n");
	i = -1;
	loading_screen(5, s);
	while (++i < NB_THREAD)
		pthread_join(util_th[i].thread, NULL);
	s->rendu->pixels = e->pixels;
	loading_screen(7, s);
	free(util_th);
	display(s, e);
}
