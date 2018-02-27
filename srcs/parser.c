/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:13:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/02/27 20:37:07 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	pars_sphere(t_obj *obj, char *str)
{

}

void	pars_cone(t_obj *obj, char *str)
{

}

void	pars_cylindre(t_obj *obj, char *str)
{

}

void	pars_plan(t_obj *obj, char *str)
{

}

void	pars_spot(t_obj *obj, char *str)
{

}

void	pars_pyramide(t_obj *obj, char *str)
{

}

void		obj_name(t_obj *obj, char *str, char *data)
{
	if (ft_strcmp("sphere", str))
	{
		pars_sphere(obj, data);
	}
	else if (ft_strcmp("cone", str))
	{
		pars_cone(obj, data);
	}
	else if (ft_strcmp("cylindre", str))
	{
		pars_cylindre(obj, data);
	}
	else if (ft_strcmp("plan", str))
	{
		pars_plan(obj, data);
	}
	else if (ft_strcmp("spot", str))
	{
		pars_spot(obj, data);
	}
	else if (ft_strcmp("pyramide", str))
	{
		pars_pyramide(obj, data);
	}
	else
		parser_error(0);
}

t_obj parser(char *name)
{
	int		fd;
	int		id;
	char	*line;
	t_obj	obj;
	char	**tmp;

	obj.cone = NULL;
	if((fd = open(name, O_RDONLY)) == 0)
		exit(0);
	while(get_next_line(fd, &line))
	{
		if(!(line[0] == '\\' && line[1] == '\\'))
		{
			tmp = ft_strsplit(line, ' ');
			obj_name(&obj, tmp[0], tmp[2]);
		}
	}
	return (obj);
}
