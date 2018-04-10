/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:01:02 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/13 16:57:44 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	if ((temp = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (s)
	{
		while (i < len)
		{
			temp[i] = s[start + i];
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
