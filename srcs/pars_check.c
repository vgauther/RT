/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:57:20 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/26 15:07:18 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	check_line2(char *line, t_env *e)
{
	if (!ft_isalpha(line[0]) || !line[0])
		ft_strdel(&line);
	else
	{
		add_obj(e, line);
	}
}

void	check_line1(char *line, t_env *e)
{
	if (!ft_isalpha(line[0]) || !line[0])
		ft_strdel(&line);
	else if (ft_strncmp(line, "spot", 4) == 0)
	{
		free(line);
		e->nb_spot++;
	}
	else
	{
		free(line);
		e->nb++;
	}
}

void	select_add_spot(char *str, t_env *e)
{
	if (ft_strncmp(str, "spot", 4) == 0)
		add_obj(e, str);
}

void	count_spot(char *str, t_env *e)
{
	if (ft_strncmp(str, "spot", 4) == 0)
		e->nb_spot++;
}

int		check_value(char *nbr)
{
	int		ret;
	int		nb;

	ret = 0;
	nb = ft_atoi(nbr);
	if (nb > 0)
		ret = 1;
	return (ret);
}

int		check_file(char *argument)
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
