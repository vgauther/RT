/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:57:02 by fde-souz          #+#    #+#             */
/*   Updated: 2018/02/16 11:24:10 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "mke_src.h"

static void		fstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			ft_putstr(_R);
		if (str[i] == 'Z')
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

	fd = open("Mke_src/leloup", O_RDONLY);
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
