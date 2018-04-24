/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetit <ppetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:34:11 by ppetit            #+#    #+#             */
/*   Updated: 2018/04/24 12:03:19 by fde-souz         ###   ########.fr       */
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
	else if (e->obj[nbr].type == 2)
		tmp = ray_cylindre(e, dir, ori, nbr);
	else if (e->obj[nbr].type == 4)
		tmp = ray_plan(e, dir, ori, nbr);
	else
		tmp = ray_cone(e, dir, ori, nbr);
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

void		raytracing(t_env *e, t_sdl *s)
{
	t_thread_st var[NB_THREAD];
	pthread_t	thread[NB_THREAD];
	int			ret[NB_THREAD];
	int			i;
	int			x;

	x = 0;
	i = -1;
	while (++i < NB_THREAD)
	{
		var[i].x = x;
		var[i].e = e;
		var[i].s = s;
		x += SIZE_X / NB_THREAD;
	}
	i = -1;
	while (++i < NB_THREAD)
		if ((ret[i] = pthread_create(&thread[i], NULL, threadt, &var[i])))
			ft_error("\nThread error.\n");
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(thread[i], NULL);
	s->rendu->pixels = e->pixels;
	display(s, e);
}

int			ray_shadow(t_env *e, t_inter pt, t_obj spot, int nb)
{
	int		j;
	t_vec	dir;
	t_inter tmp;
	double	dist;

	j = 0;
	(void)nb;
	dir = vector_init(pt.pos.x - spot.pos.x,
	pt.pos.y - spot.pos.y, pt.pos.z - spot.pos.z);
	dist = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	dir = normalize_vec(dir);
	while (j < e->nb)
	{
		tmp = shape_redirection(e, dir, spot.pos, j);
		if (dist - 1 > tmp.dist && tmp.dist > 0)
			return (1);
		j++;
	}
	return (0);
}
