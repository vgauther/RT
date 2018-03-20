/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:13:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 17:55:33 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_free_tab(char **tab)
{
	int					i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}

int			check_value(char *nbr)
{
	int		ret;
	int		nb;

	ret = 0;
	nb = ft_atoi(nbr);
	if (nb > 0)
		ret = 1;
	return (ret);
}

int			ft_tablen(void **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

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
		e->nb++;
	}
	else if (ft_strequ("cylindre", split[0]))
	{
		add_cylindre(e, split);
		e->nb++;
	}
	else
		ft_error("Error with scene file.");
	ft_free_tab(split);
	ft_strdel(&line);
}

static void	check_line2(char *line, t_env *e)
{
	if (!ft_isalpha(line[0]) || !line[0])
		ft_strdel(&line);
	else
	{
		add_obj(e, line);
	}
}

static void	check_line1(char *line, t_env *e)
{
	if (!ft_isalpha(line[0]) || !line[0])
		ft_strdel(&line);
	else
	{
		free(line);
		e->nb++;
	}
}

static int	check_file(char *argument)
{
	DIR					*test;
	int					fd;

	if ((test = opendir(argument)))
	{
		closedir(test);
		ft_error("Argument is a folder.");
	}
	if ((fd = open(argument, O_RDONLY)) == -1)
		ft_error("Error with scene file.");
	return (fd);
}

void		parser(char *name, t_env *e)
{
	int		fd;
	char	*line;

	fd = check_file(name);
	e->nb = 0;
	while (get_next_line(fd, &line))
		check_line1(line, e);
	if (!(e->obj = (t_obj*)malloc(sizeof(t_obj) * e->nb)))
		ft_error("Error with object malloc.");
	e->nb = 0;
	close(fd);
	fd = check_file(name);
	while (get_next_line(fd, &line))
		check_line2(line, e);
}
