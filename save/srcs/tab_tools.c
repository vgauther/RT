/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:57:29 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/20 17:59:15 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_free_tab(char **tab)
{
	int					i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}

int			ft_tablen(void **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
