/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:13:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/02/28 18:22:09 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char *ft_cap(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int ft_atoi_color(char *str)
{
	int i[2];
	int color;
	long int *num;

	i[0] = 0;
	color = 0;
	i[1] = 0;
	printf("%s\n", str);
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

int		check_pipe(int nb, char *str)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (str[i])
	{
		if(str[i] == '|')
			x++;
		i++;
	}
	printf("%d\n", nb - x);
	return (nb - x);
}

void	init_nbr(t_nbr *nb)
{
	nb->sphere = 0;
	nb->cone = 0;
	nb->cylindre = 0;
	nb->plan = 0;
	nb->pyramide = 0;
	nb->spot = 0;

}

int		only_number(char *str)
{
	int i;
	int p;
	int c;

	c = 0;
	i = 0;
	p = 0;
	while(str[i])
	{
		if (str[i] == '|')
		{
			p++;
			if (str[i+1] == '|')
				return (1);
			while(str[i] != '|' && str[i] != 0 && p != 4)
			{
				if (str[i] < '0' || str[i] > '9')
					return(1);
				i++;
			}
			if(p == 4)
			{
				i++;
				if(str[i] != '0' || str[i+1] != 'x')
					return (1);
				i += 2;
				while(str[i] != '|' && str[i] != 0)
				{
					if(!((str[i] >= 'A' && str[i] <= 'F') || (str[i] >= '0' && str[i] <= '9')))
						return (1);
					c++;
					i++;
				}
				if(c != 6)
					return (1);
			}
		}
		i++;
	}
	return(0);
}
char *only_color(char *str)
{
	char *ret;
	int i;
	int x;

	i = 0;
	x = 0;
	if (!(ret = malloc(sizeof(char) * (7))))
		exit (0);
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


void	pars_sphere(t_obj *obj, char *str)
{
	char **tmp;
	int i;
	t_sphere *tmp_sphere;

	i = 0;
	str = ft_cap(str);
	if(check_pipe(7, str) != 0 ||only_number(str) != 0)
		exit(0);
	tmp = ft_strsplit(str, '|');
	obj->nb.sphere++;
	if(obj->nb.sphere == 1)
	{
		if(!(obj->sphere = malloc(sizeof(t_sphere))))
			exit(0);
		obj->sphere[0].pos.x = ft_atoi(tmp[0]);
		obj->sphere[0].pos.y = ft_atoi(tmp[1]);
		obj->sphere[0].pos.z = ft_atoi(tmp[2]);
		obj->sphere[0].color = ft_atoi_color(only_color(tmp[3]));
		obj->sphere[0].rayon = ft_atoi(tmp[4]);
		obj->sphere[0].mat = ft_atoi(tmp[5]);

	}
	else
	{
		if(!(tmp_sphere = malloc(sizeof(t_sphere) * obj->nb.sphere)))
			exit(0);
		while(i != obj->nb.sphere - 1)
		{
			tmp_sphere[i].rayon = obj->sphere[i].rayon;
			tmp_sphere[i].color = obj->sphere[i].color;
			tmp_sphere[i].mat = obj->sphere[i].mat;
			tmp_sphere[i].pos = obj->sphere[i].pos;
			i++;
		}
		tmp_sphere[i].pos.x = ft_atoi(tmp[0]);
		tmp_sphere[i].pos.y = ft_atoi(tmp[1]);
		tmp_sphere[i].pos.z = ft_atoi(tmp[2]);
		tmp_sphere[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_sphere[i].rayon = ft_atoi(tmp[4]);
		tmp_sphere[i].mat = ft_atoi(tmp[5]);
	free(obj->sphere);
	obj->sphere = tmp_sphere;
	}

}

void	pars_cone(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;

}

void	pars_cylindre(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
}

void	pars_plan(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
}

void	pars_spot(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
}

void	pars_pyramide(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
}

void		obj_name(t_obj *obj, char *str, char *data)
{
	if (ft_strcmp("sphere", str) == 0)
	{
		pars_sphere(obj, data);
		printf("%d|%d\n", obj->sphere[0].color, obj->sphere[1].color);
	}
	else if (ft_strcmp("cone", str) == 0)
	{
		pars_cone(obj, data);
	}
	else if (ft_strcmp("cylindre", str) == 0)
	{
		pars_cylindre(obj, data);
	}
	else if (ft_strcmp("plan", str) == 0)
	{
		pars_plan(obj, data);
	}
	else if (ft_strcmp("spot", str) == 0)
	{
		pars_spot(obj, data);
	}
	else if (ft_strcmp("pyramide", str) == 0)
	{
		pars_pyramide(obj, data);
	}
	else
		parser_error(0);
}

t_obj parser(char *name)
{
	int		fd;
	char	*line;
	t_obj	obj;
	char	**tmp;

	init_nbr(&obj.nb);
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
