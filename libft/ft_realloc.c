/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:55:26 by fde-souz          #+#    #+#             */
/*   Updated: 2017/12/08 11:55:40 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, int size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		free(ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		free(ptr);
	}
	return (newptr);
}
