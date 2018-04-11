/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:27:12 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/13 15:19:44 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t cnt)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char*)dest;
	b = (unsigned char*)src;
	while (i < cnt)
	{
		a[i] = b[i];
		if (b[i] == (unsigned char)c)
			return (a + i + 1);
		i++;
	}
	return (NULL);
}
