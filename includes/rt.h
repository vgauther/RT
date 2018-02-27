/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 01:10:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/02/27 12:32:56 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SDL2.framework/Headers/SDL.h"
#include <stdlib.h>
#include "../libft/includes/libft.h"

typedef struct	s_pos
{
	int			x;
	int			y;
	int			z;
}				t_pos;

typedef struct		s_sphere
{
	int				rayon;
	int				color;
	t_pos			pos;
}					t_sphere;

typedef struct		s_cylindre
{
	int				color;
	t_pos			pos;
}					t_cylindre;

typedef struct		s_cone
{
	int				color;
	t_pos			pos;
}					t_cone;

typedef struct		s_pyramide
{
	int				color;
	t_pos			pos;
}					t_pyramide;

typedef struct		s_plan
{
	int				color;
	t_pos			pos;
}					t_plan;

typedef struct		s_spot
{
	int				color;
	t_pos			pos;
}					t_spot;

typedef struct		s_obj
{
	t_sphere		sphere;
	t_cylindre		cylindre;
	t_cone			cone;
	t_plan			plan;
	t_pyramide		pyramide;
	t_spot			spot;
}					t_obj;
