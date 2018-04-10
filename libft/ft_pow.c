/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:03:45 by fde-souz          #+#    #+#             */
/*   Updated: 2017/12/21 16:07:41 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int val, unsigned int y)
{
	int temp;

	if (y == 0)
		return (1);
	temp = ft_pow(val, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (val * temp * temp);
}
