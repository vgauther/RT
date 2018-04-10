/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:03:31 by fde-souz          #+#    #+#             */
/*   Updated: 2018/04/05 16:48:23 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		i;

	i = (n < 0) ? 2 : 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char		*ret;
	int			len;
	int			cpy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cpy = n;
	len = ft_intlen(n);
	if ((n < 0 ? 1 : 0))
		cpy = -n;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	len--;
	while (len >= 0)
	{
		ret[len--] = '0' + cpy % 10;
		cpy = cpy / 10;
	}
	if ((n < 0 ? 1 : 0))
		ret[0] = '-';
	return (ret);
}
