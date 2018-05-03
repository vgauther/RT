/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:35:11 by fde-souz          #+#    #+#             */
/*   Updated: 2018/05/03 13:35:33 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_end(char *argument, char *end)
{
	int a;
	int b;

	a = ft_strlen(argument);
	b = ft_strlen(end);
	a -= b;
	b = 0;
	while (argument[a])
	{
		if (argument[a] != end[b])
			return (0);
		a++;
		b++;
	}
	return (1);
}
