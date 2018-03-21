/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:57:20 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 18:10:41 by vgauther         ###   ########.fr       */
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
	else
	{
		free(line);
		e->nb++;
	}
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

void 	check_spot(char *str, t_env *e)
{
	int i;

	i = 0;
	if (str[0] == 's')
		i++;
	if (str[1] == 'p')
		i++;
	if (str[2] == 'o')
		i++;
	if (str[3] == 't')
		i++;
	if (i == 4)
		e->nb_spot++;
	free(str);
}

void 	check_spot2(char *str, t_env *e)
{
	int i;

	i = 0;
	if (str[0] == 's')
		i++;
	if (str[1] == 'p')
		i++;
	if (str[2] == 'o')
		i++;
	if (str[3] == 't')
		i++;
	if (i == 4)
	{
		add_obj(e, str);
		e->nb_spot++;
	}
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
