/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnega.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:58:25 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 12:58:45 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnega(int *num, int *len)
{
	int temp;

	temp = *num;
	while (temp)
	{
		*len = *len + 1;
		temp /= 10;
	}
	if (*num < 0)
	{
		*num *= -1;
		*len += 1;
		return (1);
	}
	return (0);
}
