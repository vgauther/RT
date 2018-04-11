/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:34:14 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/13 17:08:35 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t				i;
	size_t				j;
	char				*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char*)s);
	if (!j)
		return (ft_strnew(1));
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
		i++;
	if (i == j + 1)
		return (ft_strnew(1));
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\0')
		j--;
	if (!(str = ft_strsub((char*)s, i, (j - i + 1))))
		return (NULL);
	return (str);
}
