/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:08:58 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 12:00:46 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int value, size_t num)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char*)src;
	while (i < num)
	{
		if (a[i] == (unsigned char)value)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
