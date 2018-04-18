/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:04:56 by vgauther          #+#    #+#             */
/*   Updated: 2018/04/18 14:13:58 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"

typedef struct		s_tex_rec
{
	SDL_Texture		*tex;
	SDL_Rect		rect;
}					t_tex_rec;

typedef struct		s_bouton
{
	int				i;
	SDL_Rect		rect;
}					t_bouton;

typedef struct		s_print_cam
{
	t_tex_rec		title;
	t_tex_rec		pos_x;
	t_tex_rec		pos_y;
	t_tex_rec		pos_z;
	t_tex_rec		rot_x;
	t_tex_rec		rot_y;
	t_tex_rec		rot_z;
}					t_print_cam;

typedef struct		s_credits
{
	t_tex_rec		names;
	t_tex_rec		title;
}					t_credits;

typedef struct		s_filter_tok
{
	int				sep;
	int				bw;
}					t_filter_tok;

typedef struct		s_font
{
	TTF_Font		*bebas;
	SDL_Color		color[5];
	SDL_Texture		*texture;
}					t_font;

typedef	struct		s_rect
{
	int				x;
	int				y;
	int				len;
	int				hei;
}					t_rect;

typedef struct		s_hud
{
	SDL_Surface		*s_back;
	SDL_Texture		*t_back;
	SDL_Surface		*s_logo;
	SDL_Texture		*t_logo;
	SDL_Rect		r_logo;
	t_print_cam		cam;
	t_bouton		bouton[15];
	t_tex_rec		info;
	t_tex_rec		save;
	t_credits		credits;
	int				i_mess;
	t_bouton		shape_img;
	char			**mess;
	int				selectobj;
	t_filter_tok	filter_token;
	int				multi;
	int				how_much;
	SDL_Rect		multi_bouton[3];
}					t_hud;

#endif
