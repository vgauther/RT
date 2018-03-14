/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:17:10 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 17:57:02 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fill(char const *s, char **tab, int *tab1, char c)
{
	int j;
	int x;

	j = 0;
	x = tab1[0];
	while (s[tab1[0]] != c && s[tab1[0]] != '\0')
		tab1[0] += 1;
	if (!(tab[tab1[1]] = (char *)malloc(sizeof(char) * tab1[0] - x + 1)))
		return (0);
	while (x < tab1[0])
	{
		tab[tab1[1]][j] = s[x];
		j++;
		x++;
	}
	tab[tab1[1]][j] = '\0';
	return (tab1[0]);
}
