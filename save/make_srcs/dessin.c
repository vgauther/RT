/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:57:02 by fde-souz          #+#    #+#             */
/*   Updated: 2018/02/19 01:06:10 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mke_src.h"
#include <unistd.h>
#include "../libft/includes/libft.h"
#include <fcntl.h>

static void		fstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_' || str[i] == '\\' || str[i] == '|' || str[i] == '~' 
		|| str[i] == '/')
			ft_putstr(_R);
		if (str[i] == ':')
			ft_putstr(_G);
		write(1, &str[i], 1);
		i++;
		ft_putstr(_RE);
	}
}

int				main(void)
{
	int		fd;
	int		ret;
	char	**tab;
	char	buf[5000];

	fd = open("make_srcs/dessin", O_RDONLY);
	ret = read(fd, buf, 5000);
	buf[ret] = 0;
	tab = ft_strsplit(buf, '\n');
	fd = 0;
	while (tab[fd])
	{
		fstr(tab[fd]);
		if (tab[fd + 1])
			write(1, "\n", 1);
		fd++;
	}
	ft_putstr(_RE);
	return (0);
}
