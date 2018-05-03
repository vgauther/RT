/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 01:10:11 by vgauther          #+#    #+#             */
/*   Updated: 2018/05/03 12:55:23 by fde-souz         ###   ########.fr       */
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
	double			taille;
	double			rayon_2;
	int				material;
	int				type;
	Uint32			color;
	t_color			color_rgb;
	t_vec			rot;
	double			angle;
	double			angletan;
	t_vec			rot_to_print;
	int				num;
	int				reflex;
	SDL_Surface		*tex;
	int				is_neg[6];
	char			*name;
	int				transp;
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
	t_cam			ca;
	double			amb;
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
	SDL_Texture		*tex[33];
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
	Uint32			col;
}					t_spec_dif;

typedef struct		s_thread_st
{
	t_env				*e;
	t_sdl				*s;
	int					x;
}					t_thread_st;

typedef struct		s_thread_util
{
	t_thread_st		thread_param;
	pthread_t		thread;
	int				ret;
}					t_thread_util;

typedef struct		s_reflect_transp
{
	t_env			*e;
	int				*depth;
}					t_reflect_transp;

int					ft_tablen(void **tab);
void				print_info(t_sdl *s, t_env *e, int i);
t_vec				ft_rotate(t_vec p, double rot_x, double rot_y,
					double rot_z);
void				resolve_poly(t_polynome *p, t_inter *t,
					t_vec v, t_vec ori);
t_obj				*realloc_obj(t_env *e);
void				ft_wait(void);
t_obj				*realloc_obj(t_env *e);
t_cam				init_cam(void);
void				mouv(long key, t_env *e, t_sdl *s);
void				ft_init(t_sdl *s, char *name, t_env *e);
t_obj				realloc_sphere(t_env *e, int i);

/*
** loading screen
*/

void				loading_screen(int i, t_sdl *s);

/*
** create bouton
*/

void				create_bouton_tool_bar(t_sdl *s);
void				create_bouton_cam(t_sdl *s);

/*
** number with keyboard
*/

void				init_is_neg(t_env *e);
void				del_char(t_env *e, t_sdl *s, int n);
void				remplir_text_box(int key, t_env *e, t_sdl *s, int n);

/*
** texture
*/

SDL_Surface			*load_texture(char *texture);
Uint32				get_texture_chest_sphere(t_env *e, t_inter pt, t_obj obj);
Uint32				get_texture_pixel_sphere(t_env *e, t_inter pt, t_obj obj);
void				open_texture(t_sdl *s);
t_color				color_pix(t_env *e, t_inter pt);

/*
** transpa & reflect
*/

Uint32				transp(t_reflect_transp	*var, t_inter pt,
	Uint32 color, t_vec ori);
Uint32				get_reflect(t_reflect_transp *var, t_inter pt,
	Uint32 color);
t_inter				get_closest_test(t_env *e, t_vec dir, t_vec ori, int t);
void				get_closest(t_env *e, t_inter *pt, t_vec dir, t_vec ori);

/*
** bloc hud
*/

void				bloc_multiplier(t_env *e, t_sdl *s);
void				bloc_save(t_env *e, t_sdl *s);
void				bloc_credits(t_env *e, t_sdl *s);
void				bloc_logo(t_sdl *s);
void				bloc_camera(t_env *e, t_sdl *s);
void				bloc_lux(t_sdl *s, t_env *e);
void				bloc_work_space(t_env *e, t_sdl *s);

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
void				mouse_modify_ray_angle(int x, int y, t_sdl *s, t_env *e);
void				mouse_switch(int mouse_x, int mouse_y, t_sdl *s, t_env *e);
void				save_bouton(int x, int y, t_sdl *s, t_env *e);
void				mouse_filter_activate(int x, int y, t_sdl *s, t_env *e);
void				mouse_multi(int x, int y, t_sdl *s, t_env *e);
/*
** display
*/

void				display_credits(t_sdl *s);
void				display_cam(t_sdl *s);
void				display_multi_text(t_sdl *s);
void				display_light(t_sdl *s, t_env *e);
void				display_pipette(t_sdl *s);
void				display_all_bouton(t_sdl *s);
void				display_work_space(t_sdl *s, t_env *e);
void				display_hud(t_sdl *s, t_env *e);
void				display(t_sdl *s, t_env *e);

/*
** lux light lumiere
*/

double				lux(t_env *e, t_inter pt);
int					ray_shadow(t_env *e, t_inter ori, t_obj spot, Uint32 *col);

/*
** tools
*/

double				dot(t_vec v1, t_vec v2);
double				dot_2(t_vec v1, t_vec v2);
t_vec				vector_init(double x, double y, double z);
t_vec				normalize_vec(t_vec ret);
t_vec				sub_vec(t_vec v1, t_vec v2);
t_vec				v_scale(double c, t_vec *v);
t_vec				calc_dir_vec(int x, int y, t_env *e);
t_vec				vec3_cross(t_vec va, t_vec vb);
t_vec				get_normal(t_env *e, t_inter pt, t_vec ori);

t_vec				add_vec(t_vec v1, t_vec v2);
t_vec				init_point(double x, double y, double z);
t_vec				init_point_2_coord(int x, int y);
void				intersection_point(t_inter *pt, t_vec ca, t_vec v);
t_rect				init_rect(int x1, int x2, int x3, int x4);
void				print_rect(t_rect b, t_env *e, int t, int color);

void				ft_free_tab(char **tab);
int					ft_tablen(void **tab);

SDL_Rect			init_sdl_rect(int x, int y, int w, int h);
void				quit_sdl_proprely(t_sdl *s);
void				actualize_background(t_sdl *s, t_env *e);

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
double				toon(t_env *e, t_inter pt);

/*
** HUD
*/

void				hud_init(t_sdl *s, t_env *e);
void				recup_cam_to_print(t_sdl *s, t_env *e);
void				init_add_obj_selection_rect(t_sdl *s);
void				init_add_obj_text_box(t_sdl *s);
void				init_info_messages(t_sdl *s);
void				init_color_selector(t_sdl *s);
void				init_color_text(t_sdl *s);
void				ornement(SDL_Rect p, int color, int size, t_env *e);
void				empty_rect(t_rect b, t_env *e, int t, int color);
void				add_obj_menu(t_sdl *s, t_env *e, int nb);
void				add_obj_selection_display(t_sdl *s);
void				recup_cam_to_print(t_sdl *s, t_env *e);
void				print_data_obj(t_sdl *s, t_env *e, int nbr);
void				init_hud_var(t_sdl *s);

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
t_inter				ray_disque(t_env *e, t_vec v, t_vec ori, int nbr);
t_inter				shape_redirection(t_env *e, t_vec dir,
					t_vec ori, int nbr);

/*
** shapes's normal
*/

t_vec				disque_normal_at(t_inter t, t_obj obj, t_vec ori);
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
void				add_disque(t_env *e, char **sp);
void				add_plan(t_env *e, char **sp);
void				count_spot(char *str, t_env *e);
void				select_add_spot(char *str, t_env *e);
int					check_value(char *nbr);

/*
** color
*/

char				*only_color(char *str);
t_color				mult_color(t_color a, t_color b);
int					ft_atoi_color(char *str);
t_color				split_color(Uint32 full);
Uint32				rgb_to_int(t_color color);
t_color				color_init(double r, double g, double b);
Uint32				proces_color(t_env *e, t_sdl *s, t_inter pt);

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
