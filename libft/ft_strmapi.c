/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:21:24 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/10 11:33:18 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;

	if (s && f)
	{
		if ((ret = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1))
		== NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = f(i, s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
