/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:35:56 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/15 14:44:41 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*temp;
	size_t		len1;
	size_t		len2;

	if (s1 && s2)
	{
		len1 = ft_strlen((char*)s1);
		len2 = ft_strlen((char*)s2);
		if ((temp = (char*)malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
			return (NULL);
		temp[0] = 0;
		ft_strcat(temp, (char*)s1);
		ft_strcat(temp, (char*)s2);
		return (temp);
	}
	return (NULL);
}
