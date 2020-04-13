/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 21:26:07 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/14 18:19:30 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define KEY_P        112
# define KEY_R        114
# define KEY_UP     65362
# define KEY_LEFT   65361
# define KEY_DOWN   65364
# define KEY_RIGHT  65363
# define KEY_ENTER  65293
# define KEY_ESC    65307
# define KEY_DEEPM  65451
# define KEY_DEEPL  65453
# define KEY_MORE      61
# define KEY_LESS      45

// # define KEY_P         35
// # define KEY_R         15
// # define KEY_UP       126
// # define KEY_LEFT     123
// # define KEY_DOWN     124
// # define KEY_RIGHT    125
// # define KEY_ENTER     36
// # define KEY_ESC       53
// # define KEY_DEEPM     69
// # define KEY_DEEPL     78
// # define KEY_MORE      24
// # define KEY_LESS      27

# define SCRX          800
# define SCRY          600

# define WHITE      0x00FFFFFF
# define BLACK      0x00000000
# define GREEN      0x0000FF21
# define RED        0x00FF0000
# define GREY       0x00808080
# define BLUE       0x0000FFFF
# define BLUE2      0x00007F7F
# define ORANGE     0x00FF6A00

# define NBR_ARGUMENTS 0
# define MALLOC_FAILED 1
# define BAD_FRACTAL   2
# define END_PROGRAM   3
# define INIT_FAILED   4

# define MDLB  1
# define JL    2
# define PERSO 3

typedef struct			s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*t;
	int					p;
	int					init;
	int					fractal;
	int					deep;
	struct s_fractal	*frac;
	char				*img;
	int					bpp;
	int					size_l;
	int					endian;
	int					nbzoom;
}						t_env;

typedef struct			s_fractal
{
	int					x;
	int					y;
	int					a;
	double				min_x;
	double				min_y;
	double				max_x;
	double				max_y;
	double				rc;
	double				ic;
	double				rz;
	double				iz;
	double				r;
	double				i;
}						t_fractal;

void					put_pixel_to_img(t_env *e, int x, int y, int color);
void					usage(int error);
void					check_fractal(char *fract, int argc, t_env *e);
void					put_rules(void);
void					deep(t_env *e, int keycode);
int						key_hook(int keycode, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
void					draw(t_env *e);
void					print_mandelbrot(t_env *frcl);
void					print_julia(t_env *frcl);
void					print_perso(t_env *frcl);
void					move(t_env *e, int keycode);
void					zoom(t_env *e, int button, int x, int y);
int						motion_hook(int x, int y, t_env *e);
void					image_reload(t_env *e);

#endif
