/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 01:10:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/14 14:25:25 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../lib/SDL/include/SDL2/SDL.h"
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>

# define SIZE_X 1200
# define SIZE_Y 800
# define VIEW_X 500
# define VIEW_Y 340
# define RAD (M_PI / 180.00)

typedef struct	s_polynome
{
	double a;
	double b;
	double c;
	double delta;
	double x1;
	double x2;
}				t_polynome;

typedef struct	s_3dvector
{
	double		x;
	double		y;
	double		z;
}				t_3dvector;

typedef struct	s_inter
{
	int			x;
	int			y;
	int			z;
	double		dist;
	int			nb;
}				t_inter;

typedef struct	s_rot
{
	int			x;
	int			y;
	int			z;
}				t_rot;

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
	int				mat;
	int				rayon_pow;
	t_pos			pos;
}					t_sphere;

typedef struct		s_cylindre
{
	int				rayon;
	int				hauteur;
	int				color;
	int				mat;
	t_pos			pos;
	t_rot			rot;
}					t_cylindre;

typedef struct		s_cone
{
	int				hauteur;
	int				rayon;
	int				color;
	int				mat;
	t_pos			pos;
	t_rot			rot;
}					t_cone;

typedef struct		s_pyramide
{
	int				color;
	int				hauteur;
	int				longueur;
	int				largeur;
	int				mat;
	t_pos			pos;
	t_rot			rot;
}					t_pyramide;

typedef struct		s_plan
{
	int				longueur;
	int				largeur;
	int				color;
	int				mat;
	t_pos			pos;
	t_rot			rot;
}					t_plan;

typedef struct		s_spot
{
	int				color;
	t_pos			pos;
	t_rot			rot;
}					t_spot;

typedef struct		s_nbr
{
	int				sphere;
	int				cylindre;
	int				cone;
	int				plan;
	int				pyramide;
	int				spot;
}					t_nbr;

typedef struct		s_obj
{
	t_nbr			nb;
	t_sphere		*sphere;
	t_cylindre		*cylindre;
	t_cone			*cone;
	t_plan			*plan;
	t_pyramide		*pyramide;
	t_spot			*spot;
}					t_obj;

typedef struct		s_cam
{
	double xr;
	double yr;
	double zr;
}					t_cam;

typedef struct		s_sdl
{
	Uint32			*pixels;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		*surface;
	SDL_Event		event;
}					t_sdl;

void				ft_error(char *msg, const char *error);
void				usage(void);
void				parser_error(int err);
t_obj				parser(char *name);
void				raytracing(t_obj obj, t_sdl s, t_cam c);
void				display(t_sdl *s);
void				plan(t_obj obj, t_sdl s, t_cam c);
double				lux(t_obj obj, int color, t_inter pt, int nb);

#endif
