/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:08:10 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 12:20:50 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s;

	s = (char*)str;
	i = 0;
	k = 0;
	if (*to_find == '\0')
		return (s);
	while (str[i] != '\0' && i < len)
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k] && j < len)
		{
			j++;
			k++;
			if (to_find[k] == '\0')
				return (&s[i]);
		}
		i++;
	}
	return (0);
}
