/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 01:10:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/23 18:08:29 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"
# include "../libft/includes/libft.h"
# include "define_color.h"
# include "define_rt.h"
# include "define_key.h"
# include "hud.h"

# include <fcntl.h>
# include <dirent.h>
# include <stdio.h>
# include <time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
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

typedef struct		s_cam
{
	t_vec			rot;
	t_vec			pos;
}					t_cam;

typedef struct		s_obj
{
	t_vec			pos;
	double			rayon;
	double			rayon_2;
	int				material;
	int				type;
	int				color;
	t_color			color_rgb;
	t_vec			rot;
	double			angle;
	double			angletan;
	t_vec			rot_to_print;
	int				num;
	int				reflex;
	int				is_neg[6];
}					t_obj;

typedef struct		s_env
{
	int				nb_spot;
	int				nb;
	t_obj			*spot;
	t_obj			*obj;
	t_obj			*first;
	Uint32			*pixels;
	Uint32			*hud;
	SDL_Surface		*test;
	t_cam			ca;
}					t_env;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		*rendu;
	SDL_Event		event;
	t_hud			hud1;
	t_font			font;
	SDL_Texture		*tex[19];
}					t_sdl;

typedef struct		s_inter
{
	t_vec			pos;
	double			dist;
	int				nb;
	double			delta;
	t_vec			normal;
	t_color			color_rgb;
}					t_inter;

typedef struct		s_texture_calc
{
	double			x;
	double			y;
	double			theta;
	double			phi;
	char			*pixels;
	Uint32			color;
	t_vec			vp;
	t_vec			pl;
	t_vec			eq;
}					t_texture_calc;

typedef struct		s_spec_dif
{
	int				i;
	double			specular;
	double			difuse;
}					t_spec_dif;

typedef struct		s_thread_st
{
	t_env				*e;
	t_sdl				*s;
	int					x;
}					t_thread_st;

Uint32				get_reflect(t_env *e, t_inter pt, int depth, Uint32 color);
void				get_closest(t_env *e, t_inter *pt, t_vec dir, t_vec ori);
t_vec				v_scale(double c, t_vec *v);
double				toon(t_env *e, t_inter pt);
int					check_value(char *nbr);
void				display(t_sdl *s, t_env *e);
int					ft_tablen(void **tab);
void				ft_put_pixel(Uint32 *tab, int x, int y, int color);
void				open_texture(t_sdl *s);
void				print_info(t_sdl *s, t_env *e, int i);
t_vec				ft_rotate(t_vec p, double rot_x, double rot_y,
					double rot_z);
Uint32				get_texture_pixel(t_env *e, t_inter pt, t_obj obj);
t_inter				shape_redirection(t_env *e, t_vec dir,
					t_vec ori, int nbr);
t_vec				vec3_cross(t_vec va, t_vec vb);
void				resolve_poly(t_polynome *p, t_inter *t,
					t_vec v, t_vec ori);
t_obj				*realloc_obj(t_env *e);
void				ft_wait(void);
void				bloc_multiplier(t_env *e, t_sdl *s);
t_vec				get_normal(t_env *e, t_inter pt, t_vec ori);
void				print_data_obj(t_sdl *s, t_env *e, int nbr);
t_obj				*realloc_obj(t_env *e);
t_cam				init_cam(int x, int y, int z);
void				mouv(long key, t_env *e, t_sdl *s);
void				init_is_neg(t_env *e);
void				remplir_text_box(int key, t_env *e, t_sdl *s, int n);

/*
** mouse functions
*/

void				mouse_main_cam(int x, int y, t_sdl *s, t_env *e);
void				mouse_pipette_color(int x, int y, t_sdl *s, t_env *e);
void				mouse_pipette_activate(int x, int y, t_sdl *s, t_env *e);
void				mouse_add_obj_select(int x, int y, t_sdl *s, t_env *e);
void				mouse_add_obj_activate(int x, int y, t_sdl *s, t_env *e);
void				mouse_add_obj(int x, int y, t_sdl *s, t_env *e);
void				main_mouse(int mouse_x, int mouse_y, t_sdl *s, t_env *e);
void				mouse_obj_seletor(int x, int y, t_sdl *s, t_env *e);
void				mouse_selector_activate(int x, int y, t_sdl *s, t_env *e);

/*
** display
*/

void				display_credits(t_sdl *s);

/*
** lux light lumiere
*/

double				lux(t_env *e, t_inter pt);
int					ray_shadow(t_env *e, t_inter ori, t_obj spot, int nb);

/*
** tools
*/

double				dot(t_vec v1, t_vec v2);
double				dot_2(t_vec v1, t_vec v2);
t_vec				vector_init(double x, double y, double z);
t_vec				normalize_vec(t_vec ret);
t_vec				sub_vec(t_vec v1, t_vec v2);

t_vec				init_point(double x, double y, double z);
t_vec				init_point_2_coord(int x, int y);
void				intersection_point(t_inter *pt, t_vec ca, t_vec v);
t_rect				init_rect(int x1, int x2, int x3, int x4);
void				print_rect(t_rect b, t_env *e, int t, int color);

void				ft_free_tab(char **tab);
int					ft_tablen(void **tab);

SDL_Rect			init_sdl_rect(int x, int y, int w, int h);
void				quit_sdl_proprely(t_sdl *s);

int					nbr_touch(int key);
int					do_we_need_to_rt(int t);

/*
** text and font
*/

void				init_font(t_sdl *s);
void				print_text(char *str, SDL_Color color, t_sdl *s,
					t_tex_rec *data);

/*
** filtre
*/

Uint32				blackwhite(Uint32 color);
Uint32				sepia(Uint32 color);
Uint32				filtre(t_sdl *s, Uint32 color);

/*
** HUD
*/

void				hud_init(t_sdl *s, t_env *e);
void				recup_cam_to_print(t_sdl *s, t_env *e);

/*
** ft_put_pixel
*/

void				ft_put_pixel_hud(Uint32 *tab, int x, int y, int color);
void				ft_put_pixel_winrend(Uint32 *tab, int x, int y, int color);

/*
** shapes's raytracing
*/

void				raytracing(t_env *e, t_sdl *s);
t_inter				ray_sphere(t_env *e, t_vec dir, t_vec ori, int nbr);
t_inter				ray_cylindre(t_env *e, t_vec dir, t_vec ori, int nbr);
t_inter				ray_cone(t_env *e, t_vec dir, t_vec ori, int nbr);
t_inter				ray_plan(t_env *e, t_vec v, t_vec ori, int nbr);

/*
** shapes's normal
*/

t_vec				cone_normal_at(t_inter t, t_obj obj, t_vec ori);
t_vec				cylindre_normal_at(t_inter t, t_obj obj, t_vec ori);
t_vec				sphere_normal_at(t_inter t, t_obj obj);
t_vec				plan_normal_at(t_inter t, t_obj obj, t_vec ori);

/*
** parser functions
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
void				add_cone(t_env *e, char **sp);
void				add_plan(t_env *e, char **sp);
void				count_spot(char *str, t_env *e);
void				select_add_spot(char *str, t_env *e);

/*
** color
*/

char				*only_color(char *str);
t_color				mult_color(t_color a, t_color b);
int					ft_atoi_color(char *str);
t_color				split_color(Uint32 full);
Uint32				rgb_to_int(t_color color);
t_color				color_init(double r, double g, double b);

/*
** error
*/

void				parser_error(int err);
void				ft_sdl_error(char *msg, const char *error);
void				ft_error(char *msg);
t_color				normalize_color(t_color ret);

void				check_define(void);

/*
** trait.c
*/

void				vertical_trait(t_vec p1, t_vec p2, int color, t_env *e);
void				horizontal_trait(t_vec p1, t_vec p2, int color, t_env *e);

#endif
