/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 21:04:49 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 17:07:44 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	draw_base_walls(int x, t_env *e)
{
	int	tmp;

	tmp = e->ray.dstart;
	if (e->ray.dend < 0)
		e->ray.dend = SCRY;
	while (tmp < e->ray.dend)
	{
		put_pixel_to_img(e, x, tmp, e->color);
		tmp++;
	}
}

void	draw_walls_while(t_env *e, int x, int tn, int y)
{
	int	d;
	int	i;
	int	tmp;

	while (y <= e->ray.dend)
	{
		d = y * 256 - SCRY * 128 + e->ray.lheight * 128;
		e->ray.tex_y = ((d * TEXHEIGHT) / e->ray.lheight) / 256;
		i = x * 4 + y * e->size_l;
		tmp = e->ray.tex_x * (e->t[tn]->bpp / 8) + e->ray.tex_y
			* e->t[tn]->size_l;
		e->img[i] = e->t[tn]->img[tmp];
		e->img[i + 1] = e->t[tn]->img[tmp + 1];
		e->img[i + 2] = e->t[tn]->img[tmp + 2];
		e->img[i + 3] = 1;
		y++;
	}
}

void	draw_texture_walls(int x, t_env *e)
{
	int	tn;
	int	y;

	tn = e->map.board[e->map.map_x][e->map.map_y];
	if (e->player.side == 0)
		e->ray.wall_x = e->ray.ray_pos_y + e->ray.perp_wall_dist
		* e->ray.ray_dir_y;
	else
		e->ray.wall_x = e->ray.ray_pos_x + e->ray.perp_wall_dist
		* e->ray.ray_dir_x;
	e->ray.wall_x -= floor(e->ray.wall_x);
	e->ray.tex_x = floor(e->ray.wall_x * (double)TEXWIDTH);
	if (e->player.side == 0 && e->ray.ray_dir_x > 0)
		e->ray.tex_x = TEXWIDTH - e->ray.tex_x - 1;
	if (e->player.side == 1 && e->ray.ray_dir_y < 0)
		e->ray.tex_x = TEXWIDTH - e->ray.tex_x - 1;
	y = e->ray.dstart;
	draw_walls_while(e, x, tn, y);
}
