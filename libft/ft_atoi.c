/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:34:54 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 12:50:15 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		neg;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * neg);
}
