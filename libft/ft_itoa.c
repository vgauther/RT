/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:03:31 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 12:59:31 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int num)
{
	int		len;
	int		temp;
	char	*str;
	int		neg;

	if (num == 0)
		return (ft_strdup("0"));
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1;
	neg = ft_isnega(&num, &len);
	temp = num;
	if ((str = (ft_strnew(sizeof(char) * len - 1))) == NULL)
		return (0);
	while (len--)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
