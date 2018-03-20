/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:44:03 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 17:50:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color		split_color(int full)
{
	t_color color;

	color.r = (full >> 16) & 0xFF;
	color.g = (full >> 8) & 0xFF;
	color.b = full & 0xFF;
	return (color);
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
