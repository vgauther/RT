/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:14:56 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/14 16:56:54 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(dest);
	if (n <= len)
		return (ft_strlen(src) + n);
	ft_strncat(dest, src, n - len - 1);
	return (ft_strlen(src) + len);
}
