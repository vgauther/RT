/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:13:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/15 12:30:04 by fde-souz         ###   ########.fr       */
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

int			ft_atoi_color(char *str)
{
	int			i[2];
	int			color;
	long int	*num;

	i[0] = 0;
	color = 0;
	i[1] = 0;
	if (!(num = malloc(sizeof(long int *) * ft_strlen(str))))
		exit(0);
	while (str[i[1]])
	{
		if (str[i[1]] >= 'A' && str[i[1]] <= 'F')
			num[i[1]] = (str[i[1]] - 'A' + 10);
		else
			num[i[1]] = (str[i[1]] - '0');
		i[1]++;
	}
	while (--i[1] >= 0)
	{
		color += num[i[1]] * ft_pow(16, i[0]);
		i[0]++;
	}
	free(num);
	free(str);
	return (color);
}

char		*only_color(char *str)
{
	char	*ret;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!(ret = malloc(sizeof(char) * (7))))
		exit(0);
	i = 2;
	while (str[i])
	{
		ret[x] = str[i];
		x++;
		i++;
	}
	ret[x] = 0;
	return (ret);
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

t_vec		new_vec(int x, int y, int z)
{
	t_vec	new;

	new.x = (float)x;
	new.y = (float)y;
	new.z = (float)z;
	return (new);
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
