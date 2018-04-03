/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:57:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/28 12:46:59 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*
** free of a char **
*/

void		ft_free_tab(char **tab)
{
	int					i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}

/*
** height counter of a **tab
*/

int			ft_tablen(void **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}
