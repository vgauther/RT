/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:44:34 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/10 11:27:51 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (s && f)
	{
		if ((ret = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1))
		== NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = f(s[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
