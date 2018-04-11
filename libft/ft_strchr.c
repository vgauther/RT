/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:40:50 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/09 13:19:22 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*a;

	a = (char*)str;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == c)
			return (&a[i]);
		i++;
	}
	if (c == '\0')
		return (&a[i]);
	return (NULL);
}
