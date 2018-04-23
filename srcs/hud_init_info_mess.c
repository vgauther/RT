/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_init_info_mess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:55:02 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 19:55:23 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_info_messages(t_sdl *s)
{
	s->hud1.mess = malloc(sizeof(char *) * 12);
	s->hud1.mess[0] =
	ft_strdup("Last   Info   :   RT   succesfully   launched.");
	s->hud1.mess[1] =
	ft_strdup("Last  Info  :  Camera  just  mooved  on  x  axis");
	s->hud1.mess[2] =
	ft_strdup("Last  Info  :  Camera  just  mooved  on  y  axis");
	s->hud1.mess[3] =
	ft_strdup("Last  Info  :  Camera  just  mooved  on  z  axis");
	s->hud1.mess[4] =
	ft_strdup("Last  Info  :  Your  work  has  been  saved.");
	s->hud1.mess[5] =
	ft_strdup("Last  Info  :  Sepia filter actived.");
	s->hud1.mess[6] =
	ft_strdup("Last  Info  :  Sepia filter disabled.");
	s->hud1.mess[7] =
	ft_strdup("Last  Info  :  Black and white filter actived.");
	s->hud1.mess[8] =
	ft_strdup("Last  Info  :  Black and whit filter disabled.");
	s->hud1.mess[9] =
	ft_strdup("Last  Info  :  Camera just rotated on x axis.");
	s->hud1.mess[10] =
	ft_strdup("Last  Info  :  Camera just rotated on y axis.");
	s->hud1.mess[11] =
	ft_strdup("Last  Info  :  Camera just rotated on z axis.");
}
