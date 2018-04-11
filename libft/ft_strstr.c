/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:32:51 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 12:17:44 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	i = 0;
	k = 0;
	s = (char*)str;
	while (str[i] != '\0')
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k])
		{
			j++;
			k++;
			if (to_find[k] == '\0')
				return (&s[i]);
		}
		i++;
	}
	if (*to_find == 0)
		return (s);
	return (0);
}
