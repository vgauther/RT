/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:39:23 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/19 19:41:32 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	check_define(void)
{
	int t;

	t = 0;
	if (SIZE_X / 2 != SIZE_X_2)
		ft_error("SIZE_X != SIZE_X_2");
	else if (SIZE_Y / 2 != SIZE_Y_2)
		ft_error("SIZE_Y != SIZE_Y_2");
	if (SIZE_X != 1000 || SIZE_Y != 600)
	{
		ft_putstr("\nVous avez choisis de modifier les parametres de bases.");
		ft_putstr("Il se peut que des erreurs visuel ");
		ft_putstr("et systeme apparaissent.\n");
	}
}
