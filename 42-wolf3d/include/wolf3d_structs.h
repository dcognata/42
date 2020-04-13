/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:05:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 14:40:50 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCTS_H
# define WOLF3D_STRUCTS_H

typedef struct		s_tex
{
	void			*xpm;
	char			*img;
	int				bpp;
	int				size_l;
	int				s_x;
	int				s_y;
	int				endian;
}					t_tex;

typedef struct		s_rtcls
{
	int				shoot;
	void			*gun_1;
	void			*gun_2;
	void			*shootgun_1;
	void			*shootgun_2;
	void			*rifle_1;
	void			*rifle_2;
}					t_rtcls;

typedef struct		s_minia
{
	void			*gun;
	void			*shootgun;
	void			*rifle;
}					t_minia;

typedef struct		s_weapon
{
	int				weap;
	struct s_rtcls	retic;
	struct s_minia	minia;
	void			*gun_1;
	void			*gun_2;
	void			*shootgun_1;
	void			*shootgun_2;
	void			*rifle_1;
	void			*rifle_2;
	void			*knif;
}					t_weapon;

typedef struct		s_assets
{
	void			*load_screen;
	void			*load_msg;
	void			*load_fstate;
	void			*load_sstate;
	void			*load_tstate;
	void			*load_ftstate;
	void			*title;
	void			*play_h;
	void			*edit_h;
	void			*exit_h;
	void			*play;
	void			*edit;
	void			*exit;
	void			*arrow;
	void			*level;
	void			*editor_bg;
}					t_assets;

typedef struct dirent	t_dirent;

typedef struct		s_level
{
	t_dirent		*dirent;
	DIR				*dir;
	char			**array;
	char			*level;
	int				level_choice;
	int				nb;
	int				fd;
}					t_level;

typedef struct		s_ray
{
	double			plane_x;
	double			plane_y;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	int				lheight;
	int				dstart;
	int				dend;
}					t_ray;

typedef struct		s_player
{
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	double			pos_x;
	double			pos_y;
	double			bpos_x;
	double			bpos_y;
	double			dir_x;
	double			dir_y;
	int				step_x;
	int				step_y;
	int				side;
	int				hit;
}					t_player;

typedef struct		s_tmp
{
	double			old_dir_x;
	double			old_plane_x;
}					t_tmp;

typedef struct		s_map
{
	int				**board;
	int				map_x;
	int				map_y;
	int				sky;
}					t_map;

typedef struct		s_draw
{
	double			floor_x_w;
	double			floor_y_w;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	double			weight;
	double			current_floor_x;
	double			current_floor_y;
	int				floor_tex_x;
	int				floor_tex_y;
}					t_draw;

typedef struct		s_editor
{
	int				**board;
	int				start[2];
	int				size[2];
	int				select;
	int				sky;
	int				st;
}					t_editor;

typedef struct		s_env
{
	struct s_tex	*t[NBTEX];
	struct s_player player;
	struct s_tmp	tmp;
	struct s_map	map;
	struct s_assets	ast;
	struct s_level	lvl;
	struct s_ray	ray;
	struct s_weapon	weapon;
	struct s_draw	draw;
	struct s_editor edit;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				size_l;
	int				endian;
	int				select;
	int				gui;
	int				draw_mode;
	int				color;
}					t_env;

#endif
