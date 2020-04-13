/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 16:37:40 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/14 18:11:40 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# define KEY_ENTER  65293
# define KEY_ESC    65307
# define KEY_MORE_1 65451
# define KEY_MORE_2 61
# define KEY_LESS_1 65453
# define KEY_LESS_2 45
# define KEY_RESET  114
# define KEY_TOP    65362
# define KEY_LEFT   65361
# define KEY_BOTTOM 65364
# define KEY_RIGHT  65363
# define KEY_D      100
# define KEY_C      99

// # define KEY_ENTER  36
// # define KEY_ESC    53
// # define KEY_MORE_1 69
// # define KEY_MORE_2 24
// # define KEY_LESS_1 78
// # define KEY_LESS_2 27
// # define KEY_RESET  15
// # define KEY_TOP    126
// # define KEY_LEFT   123
// # define KEY_BOTTOM 125
// # define KEY_RIGHT  124
// # define KEY_D      2
// # define KEY_C      8

# define SCR_X       1280
# define SCR_Y       720
# define PIXEL_SIZE  1

# define WHITE  0x00FFFFFF
# define GREEN  0x0000FF21
# define RED    0x00FF0000
# define GREY   0x00808080
# define BLUE   0x0000FFFF

# define NBR_ARGUMENTS 0
# define MALLOC_FAILED 1
# define OPEN_FAILED   2
# define END_PROGRAM   3
# define INIT_FAILED   4
# define BAD_CONTENT   5
# define EMPTY_FILE    6

typedef struct		s_board
{
	int				x;
	int				y;
	int				draw_x;
	int				draw_y;
	int				value;
	struct s_board	*next;
	struct s_board	*right;
	struct s_board	*down;
}					t_board;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_board			*first;
	int				zoom_value;
	int				nb_zoom;
	int				move_value;
	int				nb_move;
	int				nbchange;
	int				changec;
	int				color;
	int				nb_line;
	int				nb_column;
	int				div_x;
	int				div_y;
	int				fd;
	int				step;
	int				z_impact;
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
}					t_env;

typedef struct		s_bresh
{
	int				dx;
	int				dy;
	int				incx;
	int				incy;
	int				inc1;
	int				inc2;
	int				x;
	int				y;
	int				i;
	int				e;
}					t_bresh;

typedef struct		s_draw
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_draw;

void				usage(int error);
void				init_struct(t_env *fdf, t_board *board);
void				user_instructions(t_env *fdf);
void				change_color(t_env *fdf);

int					read_board(t_env *fdf);
void				parse_board(t_env *fdf, char *line, int countl);
void				assign_down_ptr(t_env *fdf);
int					whileread(char *line, int ret, int countl, t_env *fdf);
int					put_in_list(t_board *board, int value, int cntl, int cntc);

int					key_hook(int keycode, t_env *fdf);
void				reinit(t_env *fdf);
void				zoom_in(t_env *fdf, int keycode);

void				move_it(t_env *fdf, int keycode);
void				ft_move(t_env *fdf, t_board *ptr, int keycode);
void				ft_upz(t_board *ptr, int keycode);
void				upz(t_env *fdf, int keycode);

void				draw_pixel(int x, int y, t_env *fdf);
void				draw_segment(t_env *fdf, t_draw *draw);
void				draw_map(t_env *fdf);

void				bresh_init_check(t_bresh *bresh, t_draw *draw);
void				bresh_if(t_bresh *bresh, t_env *fdf);
void				bresh_else(t_bresh *bresh, t_env *fdf);

int					get_percentage(int percent, int nb);
void				is_numeric(char *str);

void				recalculate_translation(t_env *fdf);
void				rework_translation_points_x(t_env *fdf);
void				rework_translation_points_y(t_env *fdf);
int					validate_translation(t_env *fdf);
void				set_translation_points(t_env *fdf);

#endif
