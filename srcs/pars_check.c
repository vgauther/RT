/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:57:20 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/03 13:33:51 by fde-souz         ###   ########.fr       */
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

int		ft_check_end(char *argument, char *end)
{
	int a;
	int b;

	a = ft_strlen(argument);
	b = ft_strlen(end);
	a -= b;
	b = 0;
	while (argument[a])
	{
		if (argument[a] != end[b])
			return (0);
		a++;
		b++;
	}
	return (1);
}

int		check_file(char *argument)
{
	int					fd;

	if (!(ft_check_end(argument, ".RT")))
		ft_error("Wrong file extension");
	if ((fd = open(argument, O_RDONLY)) == 1)
		ft_error("Error reading scene file.");
	return (fd);
}
