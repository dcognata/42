/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:30:35 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/03 17:33:21 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	sky_to_img(t_env *e, int x, int y, int tmp)
{
	int	i;

	i = x * 4 + (SCRY - y) * e->size_l;
	tmp = e->draw.floor_tex_x * (e->t[e->map.sky]->bpp / 8) +
		e->draw.floor_tex_y * e->t[e->map.sky]->size_l;
	e->img[i] = e->t[e->map.sky]->img[tmp];
	e->img[i + 1] = e->t[e->map.sky]->img[tmp + 1];
	e->img[i + 2] = e->t[e->map.sky]->img[tmp + 2];
	e->img[i + 3] = 1;
}

void	draw_sky_while(t_env *e, int x)
{
	int	y;
	int	tmp;

	tmp = 0;
	y = e->ray.dend + 1;
	if (e->ray.dend < 0)
		y = SCRY;
	while (y < SCRY)
	{
		e->draw.current_dist = SCRY / (2.0 * y - SCRY);
		e->draw.weight = (e->draw.current_dist - e->draw.dist_player)
			/ (e->draw.dist_wall - e->draw.dist_player);
		e->draw.current_floor_x = e->draw.weight * e->draw.floor_x_w +
			(1.0 - e->draw.weight) * e->player.pos_x;
		e->draw.current_floor_y = e->draw.weight * e->draw.floor_y_w +
			(1.0 - e->draw.weight) * e->player.pos_y;
		e->draw.floor_tex_x = (int)(e->draw.current_floor_x * TEXWIDTH)
			% TEXWIDTH;
		e->draw.floor_tex_y = (int)(e->draw.current_floor_y * TEXWIDTH)
			% TEXWIDTH;
		sky_to_img(e, x, y, tmp);
		y++;
	}
}

void	draw_tex_sky(int x, t_env *e)
{
	if (e->player.side == 0 && e->ray.ray_dir_x > 0)
	{
		e->draw.floor_x_w = e->map.map_x;
		e->draw.floor_y_w = e->map.map_y + e->ray.wall_x;
	}
	else if (e->player.side == 0 && e->ray.ray_dir_x < 0)
	{
		e->draw.floor_x_w = e->map.map_x + 1.0;
		e->draw.floor_y_w = e->map.map_y + e->ray.wall_x;
	}
	else if (e->player.side == 1 && e->ray.ray_dir_y > 0)
	{
		e->draw.floor_x_w = e->map.map_x + e->ray.wall_x;
		e->draw.floor_y_w = e->map.map_y;
	}
	else
	{
		e->draw.floor_x_w = e->map.map_x + e->ray.wall_x;
		e->draw.floor_y_w = e->map.map_y + 1.0;
	}
	e->draw.dist_wall = e->ray.perp_wall_dist;
	e->draw.dist_player = 0.0;
	draw_sky_while(e, x);
}

void	draw_base_sky(int x, t_env *e)
{
	int	tmp;

	tmp = 0;
	while (tmp < e->ray.dstart)
	{
		put_pixel_to_img(e, x, tmp, SKY);
		tmp++;
	}
}

void	draw_sky(int x, t_env *e)
{
	if (e->draw_mode == 0)
		draw_base_sky(x, e);
	else
		draw_tex_sky(x, e);
}
