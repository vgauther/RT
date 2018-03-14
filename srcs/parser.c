/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:13:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/14 13:23:55 by fde-souz         ###   ########.fr       */
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
	if(check_pipe(7, str) != 0 || only_number(str) != 0)
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
		obj->sphere[0].rayon_pow = obj->sphere[0].rayon * obj->sphere[0].rayon;

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
			tmp_sphere[i].rayon_pow = obj->sphere[i].rayon_pow;
			i++;
		}
		tmp_sphere[i].pos.x = ft_atoi(tmp[0]);
		tmp_sphere[i].pos.y = ft_atoi(tmp[1]);
		tmp_sphere[i].pos.z = ft_atoi(tmp[2]);
		tmp_sphere[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_sphere[i].rayon = ft_atoi(tmp[4]);
		tmp_sphere[i].rayon_pow = tmp_sphere[i].rayon * tmp_sphere[i].rayon;
		tmp_sphere[i].mat = ft_atoi(tmp[5]);
		free(obj->sphere);
		obj->sphere = tmp_sphere;
	}
}

void	pars_cone(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
	char **tmp;
	int i;
	t_cone *tmp_cone;

	i = 0;
	str = ft_cap(str);
	if(check_pipe(11, str) != 0 || only_number(str) != 0)
		exit(0);
	tmp = ft_strsplit(str, '|');
	obj->nb.cone++;
	if(obj->nb.cone == 1)
	{
		if(!(obj->cone = malloc(sizeof(t_cone))))
			exit(0);
		obj->cone[0].pos.x = ft_atoi(tmp[0]);
		obj->cone[0].pos.y = ft_atoi(tmp[1]);
		obj->cone[0].pos.z = ft_atoi(tmp[2]);
		obj->cone[0].color = ft_atoi_color(only_color(tmp[3]));
		obj->cone[0].rayon = ft_atoi(tmp[4]);
		obj->cone[0].hauteur = ft_atoi(tmp[5]);
		obj->cone[0].mat = ft_atoi(tmp[6]);
		obj->cone[0].rot.x = ft_atoi(tmp[7]);
		obj->cone[0].rot.y = ft_atoi(tmp[8]);
		obj->cone[0].rot.z = ft_atoi(tmp[9]);

	}
	else
	{
		if(!(tmp_cone = malloc(sizeof(t_cone) * obj->nb.cone)))
			exit(0);
		while(i != obj->nb.cone - 1)
		{
			tmp_cone[i].hauteur = obj->cone[i].hauteur;
			tmp_cone[i].rayon = obj->cone[i].rayon;
			tmp_cone[i].color = obj->cone[i].color;
			tmp_cone[i].mat = obj->cone[i].mat;
			tmp_cone[i].pos = obj->cone[i].pos;
			tmp_cone[i].rot = obj->cone[i].rot;
			i++;
		}
		tmp_cone[i].pos.x = ft_atoi(tmp[0]);
		tmp_cone[i].pos.y = ft_atoi(tmp[1]);
		tmp_cone[i].pos.z = ft_atoi(tmp[2]);
		tmp_cone[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_cone[i].rayon = ft_atoi(tmp[4]);
		tmp_cone[i].hauteur = ft_atoi(tmp[5]);
		tmp_cone[i].mat = ft_atoi(tmp[6]);
		tmp_cone[i].rot.x = ft_atoi(tmp[7]);
		tmp_cone[i].rot.y = ft_atoi(tmp[8]);
		tmp_cone[i].rot.z = ft_atoi(tmp[9]);
		free(obj->cone);
		obj->cone = tmp_cone;
	}
}

void	pars_cylindre(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
	char **tmp;
	int i;
	t_cylindre *tmp_cylindre;

	i = 0;
	str = ft_cap(str);
	if(check_pipe(11, str) != 0 || only_number(str) != 0)
		exit(0);
	tmp = ft_strsplit(str, '|');
	obj->nb.cylindre++;
	if(obj->nb.cylindre == 1)
	{
		if(!(obj->cylindre = malloc(sizeof(t_cylindre))))
			exit(0);
		obj->cylindre[0].pos.x = ft_atoi(tmp[0]);
		obj->cylindre[0].pos.y = ft_atoi(tmp[1]);
		obj->cylindre[0].pos.z = ft_atoi(tmp[2]);
		obj->cylindre[0].color = ft_atoi_color(only_color(tmp[3]));
		obj->cylindre[0].rayon = ft_atoi(tmp[4]);
		obj->cylindre[0].hauteur = ft_atoi(tmp[5]);
		obj->cylindre[0].mat = ft_atoi(tmp[6]);
		obj->cylindre[0].rot.x = ft_atoi(tmp[7]);
		obj->cylindre[0].rot.y = ft_atoi(tmp[8]);
		obj->cylindre[0].rot.z = ft_atoi(tmp[9]);

	}
	else
	{
		if(!(tmp_cylindre = malloc(sizeof(t_cylindre) * obj->nb.cylindre)))
			exit(0);
		while(i != obj->nb.cylindre - 1)
		{
			tmp_cylindre[i].hauteur = obj->cylindre[i].hauteur;
			tmp_cylindre[i].rayon = obj->cylindre[i].rayon;
			tmp_cylindre[i].color = obj->cylindre[i].color;
			tmp_cylindre[i].mat = obj->cylindre[i].mat;
			tmp_cylindre[i].pos = obj->cylindre[i].pos;
			tmp_cylindre[i].rot = obj->cylindre[i].rot;
			i++;
		}
		tmp_cylindre[i].pos.x = ft_atoi(tmp[0]);
		tmp_cylindre[i].pos.y = ft_atoi(tmp[1]);
		tmp_cylindre[i].pos.z = ft_atoi(tmp[2]);
		tmp_cylindre[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_cylindre[i].rayon = ft_atoi(tmp[4]);
		tmp_cylindre[i].hauteur = ft_atoi(tmp[5]);
		tmp_cylindre[i].mat = ft_atoi(tmp[6]);
		tmp_cylindre[i].rot.x = ft_atoi(tmp[7]);
		tmp_cylindre[i].rot.y = ft_atoi(tmp[8]);
		tmp_cylindre[i].rot.z = ft_atoi(tmp[9]);
		free(obj->cylindre);
		obj->cylindre = tmp_cylindre;
	}
}

void	pars_plan(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
	char **tmp;
	int i;
	t_plan *tmp_plan;

	i = 0;
	str = ft_cap(str);
	if(check_pipe(11, str) != 0 || only_number(str) != 0)
		exit(0);
	tmp = ft_strsplit(str, '|');
	obj->nb.plan++;
	if(obj->nb.plan == 1)
	{
		if(!(obj->plan = malloc(sizeof(t_plan))))
			exit(0);
		obj->plan[0].pos.x = ft_atoi(tmp[0]);
		obj->plan[0].pos.y = ft_atoi(tmp[1]);
		obj->plan[0].pos.z = ft_atoi(tmp[2]);
		obj->plan[0].color = ft_atoi_color(only_color(tmp[3]));
		obj->plan[0].largeur = ft_atoi(tmp[4]);
		obj->plan[0].longueur = ft_atoi(tmp[5]);
		obj->plan[0].mat = ft_atoi(tmp[6]);
		obj->plan[0].rot.x = ft_atoi(tmp[7]);
		obj->plan[0].rot.y = ft_atoi(tmp[8]);
		obj->plan[0].rot.z = ft_atoi(tmp[9]);

	}
	else
	{
		if(!(tmp_plan = malloc(sizeof(t_plan) * obj->nb.plan)))
			exit(0);
		while(i != obj->nb.plan - 1)
		{
			tmp_plan[i].longueur = obj->plan[i].longueur;
			tmp_plan[i].largeur = obj->plan[i].largeur;
			tmp_plan[i].color = obj->plan[i].color;
			tmp_plan[i].mat = obj->plan[i].mat;
			tmp_plan[i].pos = obj->plan[i].pos;
			tmp_plan[i].rot = obj->plan[i].rot;
			i++;
		}
		tmp_plan[i].pos.x = ft_atoi(tmp[0]);
		tmp_plan[i].pos.y = ft_atoi(tmp[1]);
		tmp_plan[i].pos.z = ft_atoi(tmp[2]);
		tmp_plan[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_plan[i].largeur = ft_atoi(tmp[4]);
		tmp_plan[i].longueur = ft_atoi(tmp[5]);
		tmp_plan[i].mat = ft_atoi(tmp[6]);
		tmp_plan[i].rot.x = ft_atoi(tmp[7]);
		tmp_plan[i].rot.y = ft_atoi(tmp[8]);
		tmp_plan[i].rot.z = ft_atoi(tmp[9]);
		free(obj->plan);
		obj->plan = tmp_plan;
	}
}

void	pars_spot(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
	char **tmp;
	int i;
	t_spot *tmp_spot;

	i = 0;
	str = ft_cap(str);
	if(check_pipe(8, str) != 0 || only_number(str) != 0)
		exit(0);
	tmp = ft_strsplit(str, '|');
	obj->nb.spot++;
	if(obj->nb.spot == 1)
	{
		if(!(obj->spot = malloc(sizeof(t_spot))))
			exit(0);
		obj->spot[0].pos.x = ft_atoi(tmp[0]);
		obj->spot[0].pos.y = ft_atoi(tmp[1]);
		obj->spot[0].pos.z = ft_atoi(tmp[2]);
		obj->spot[0].color = ft_atoi_color(only_color(tmp[3]));
		obj->spot[0].rot.x = ft_atoi(tmp[4]);
		obj->spot[0].rot.y = ft_atoi(tmp[5]);
		obj->spot[0].rot.z = ft_atoi(tmp[6]);

	}
	else
	{
		if(!(tmp_spot = malloc(sizeof(t_spot) * obj->nb.spot)))
			exit(0);
		while(i != obj->nb.spot - 1)
		{
			tmp_spot[i].rot = obj->spot[i].rot;
			tmp_spot[i].color = obj->spot[i].color;
			tmp_spot[i].pos = obj->spot[i].pos;
			i++;
		}
		tmp_spot[i].pos.x = ft_atoi(tmp[0]);
		tmp_spot[i].pos.y = ft_atoi(tmp[1]);
		tmp_spot[i].pos.z = ft_atoi(tmp[2]);
		tmp_spot[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_spot[i].rot.x = ft_atoi(tmp[4]);
		tmp_spot[i].rot.y = ft_atoi(tmp[5]);
		tmp_spot[i].rot.z = ft_atoi(tmp[6]);
		free(obj->spot);
		obj->spot = tmp_spot;
	}
}

void	pars_pyramide(t_obj *obj, char *str)
{
	(void)obj;
	(void)str;
	char **tmp;
	int i;
	t_pyramide *tmp_pyramide;

	i = 0;
	str = ft_cap(str);
	if(check_pipe(12, str) != 0 ||only_number(str) != 0)
		exit(0);
	tmp = ft_strsplit(str, '|');
	obj->nb.pyramide++;
	if(obj->nb.pyramide == 1)
	{
		if(!(obj->pyramide = malloc(sizeof(t_pyramide))))
			exit(0);
		obj->pyramide[0].pos.x = ft_atoi(tmp[0]);
		obj->pyramide[0].pos.y = ft_atoi(tmp[1]);
		obj->pyramide[0].pos.z = ft_atoi(tmp[2]);
		obj->pyramide[0].color = ft_atoi_color(only_color(tmp[3]));
		obj->pyramide[0].hauteur = ft_atoi(tmp[4]);
		obj->pyramide[0].longueur = ft_atoi(tmp[5]);
		obj->pyramide[0].largeur = ft_atoi(tmp[6]);
		obj->pyramide[0].mat = ft_atoi(tmp[7]);
		obj->pyramide[0].rot.x = ft_atoi(tmp[8]);
		obj->pyramide[0].rot.y = ft_atoi(tmp[9]);
		obj->pyramide[0].rot.z = ft_atoi(tmp[10]);
	}
	else
	{
		if(!(tmp_pyramide = malloc(sizeof(t_pyramide) * obj->nb.pyramide)))
			exit(0);
		while(i != obj->nb.pyramide - 1)
		{
			tmp_pyramide[i].color = obj->pyramide[i].color;
			tmp_pyramide[i].mat = obj->pyramide[i].mat;
			tmp_pyramide[i].hauteur = obj->pyramide[i].hauteur;
			tmp_pyramide[i].longueur = obj->pyramide[i].longueur;
			tmp_pyramide[i].largeur = obj->pyramide[i].largeur;
			tmp_pyramide[i].rot = obj->pyramide[i].rot;
			tmp_pyramide[i].pos = obj->pyramide[i].pos;
			i++;
		}
		tmp_pyramide[i].pos.x = ft_atoi(tmp[0]);
		tmp_pyramide[i].pos.y = ft_atoi(tmp[1]);
		tmp_pyramide[i].pos.z = ft_atoi(tmp[2]);
		tmp_pyramide[i].color = ft_atoi_color(only_color(tmp[3]));
		tmp_pyramide[i].hauteur = ft_atoi(tmp[4]);
		tmp_pyramide[i].longueur = ft_atoi(tmp[5]);
		tmp_pyramide[i].largeur = ft_atoi(tmp[6]);
		tmp_pyramide[i].mat = ft_atoi(tmp[7]);
		tmp_pyramide[i].rot.x = ft_atoi(tmp[8]);
		tmp_pyramide[i].rot.y = ft_atoi(tmp[9]);
		tmp_pyramide[i].rot.z = ft_atoi(tmp[10]);
		free(obj->pyramide);
		obj->pyramide = tmp_pyramide;
	}
}

void		obj_name(t_obj *obj, char *str, char *data)
{
	if (ft_strcmp("sphere", str) == 0)
	{
		pars_sphere(obj, data);
		//printf("%d|%d\n", obj->sphere[0].color, obj->sphere[1].color);
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
