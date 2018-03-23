/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 01:10:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/03/23 14:59:46 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../lib/SDL/include/SDL2/SDL.h"
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <dirent.h>
# include <stdio.h>

# define SIZE_X 600
# define SIZE_Y 600
# define RAD (M_PI / 180.00)

typedef struct		s_color
{
	int			r;
	int			g;
	int			b;
}					t_color;

typedef struct		s_polynome
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		x1;
	double		x2;
}					t_polynome;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_cam
{
	double			xr;
	double			yr;
	double			zr;
}					t_cam;

typedef struct		s_obj
{
	t_vec			pos;
	double			rayon;
	int				material;
	int				type;
	int				color;
	t_vec			rot;
}					t_obj;

typedef struct		s_env
{
	int				nb_spot;
	int				nb;
	t_obj			*spot;
	t_obj			*obj;
	t_obj			*first;
	Uint32			*pixels;
	t_cam			cam;
	t_cam			ca;
}					t_env;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		*surface;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_inter
{
	double			x;
	double			y;
	double			z;
	double			dist;
	int				nb;
}					t_inter;

int					check_value(char *nbr);
void				display(t_sdl *s);
double				lux(t_env *e, t_inter pt);
int					ft_tablen(void **tab);

/*
** tools
*/

double				dot(t_vec v1, t_vec v2);
t_vec				vector_init(double x, double y, double z);
t_vec				normalize_vec(t_vec ret, double norm);

t_point				init_point(double x, double y, double z);
void				intersection_point(t_inter *pt, t_cam ca, t_vec v);

void				ft_free_tab(char **tab);
int					ft_tablen(void **tab);

/*
** shapes's raycasting
*/

void				raytracing(t_env *e, t_cam c, t_sdl s);
t_inter				ray_sphere(t_env *e, int i, int j, t_cam ca, int nbr);
t_inter				ray_cylindre(t_env *e, int i, int j, t_cam ca, int nbr);

/*
** parser
*/

void				parser(char *name, t_env *e);
void				add_obj(t_env *e, char *line);
void				check_line1(char *line, t_env *e);
void				check_line2(char *line, t_env *e);
int					check_file(char *argument);
int					check_value(char *nbr);
void				add_sphere(t_env *e, char **sp);
void				add_spot(t_env *e, char **sp);
void				add_cylindre(t_env *e, char **sp);
void				count_spot(char *str, t_env *e);
void				select_add_spot(char *str, t_env *e);

/*
** color
*/

char				*only_color(char *str);
int					ft_atoi_color(char *str);
t_color				split_color(int full);

/*
** error
*/

void				parser_error(int err);
void				ft_sdl_error(char *msg, const char *error);
void				ft_error(char *msg);

#endif
