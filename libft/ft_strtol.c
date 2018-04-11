/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:04:31 by fde-souz          #+#    #+#             */
/*   Updated: 2017/12/21 16:08:30 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

long int	ft_strtol(char *line)
{
	t_struct_atol var;

	var.cmp = 0;
	var.power = 0;
	var.rslt = 0;
	var.hexa = (long int*)malloc(sizeof(long int) * ft_strlen(line));
	while (line[var.cmp])
	{
		if (line[var.cmp] >= 'A' && line[var.cmp] <= 'F')
			var.hexa[var.cmp] = line[var.cmp] - 'A' + 10;
		if (line[var.cmp] >= 'a' && line[var.cmp] <= 'f')
			var.hexa[var.cmp] = line[var.cmp] - 'a' + 10;
		else if (line[var.cmp] >= '0' && line[var.cmp] <= '9')
			var.hexa[var.cmp] = line[var.cmp] - '0';
		var.cmp++;
	}
	while (--var.cmp >= 0)
	{
		var.rslt += var.hexa[var.cmp] * ft_pow(16, var.power);
		var.power++;
	}
	free(var.hexa);
	return (var.rslt);
}
