/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:02:25 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/13 10:57:28 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	if ((s = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= size + 1)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
