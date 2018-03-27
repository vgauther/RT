/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:13:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/27 17:16:26 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		add_obj(t_env *e, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (ft_strequ("sphere", split[0]))
	{
		add_sphere(e, split);
		e->nb++;
	}
	else if (ft_strequ("spot", split[0]))
	{
		add_spot(e, split);
		e->nb_spot++;
	}
	else if (ft_strequ("cylindre", split[0]))
	{
		add_cylindre(e, split);
		e->nb++;
	}
	else if (ft_strequ("cone", split[0]))
	{
		add_cone(e, split);
		e->nb++;
	}
	else
		ft_error("Error with scene file.");
	ft_free_tab(split);
	ft_strdel(&line);
}

void		parser(char *name, t_env *e)
{
	int		fd;
	char	*line;

	fd = check_file(name);
	e->nb = 0;
	e->nb_spot = 0;
	while (get_next_line(fd, &line))
		check_line1(line, e);
	if (!(e->obj = (t_obj*)malloc(sizeof(t_obj) * e->nb)))
		ft_error("Error with object malloc.");
	if (!(e->spot = (t_obj*)malloc(sizeof(t_obj) * e->nb_spot)))
		ft_error("Error with object malloc.");
	e->nb = 0;
	e->nb_spot = 0;
	close(fd);
	fd = check_file(name);
	while (get_next_line(fd, &line))
		check_line2(line, e);
}
