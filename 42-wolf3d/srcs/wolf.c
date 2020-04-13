/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:40:31 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 23:58:26 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	super_calculator(t_env *e)
{
	if (e->player.side == 0)
		e->ray.perp_wall_dist = fabs((e->map.map_x - e->ray.ray_pos_x +
			(1 - e->player.step_x) / 2) / e->ray.ray_dir_x);
	else
		e->ray.perp_wall_dist = fabs((e->map.map_y - e->ray.ray_pos_y +
			(1 - e->player.step_y) / 2) / e->ray.ray_dir_y);
	e->ray.lheight = abs((int)(SCRY / e->ray.perp_wall_dist));
	e->ray.dstart = (-1 * e->ray.lheight) / 2 + SCRY / 2;
	if (e->ray.dstart < 0)
		e->ray.dstart = 0;
	e->ray.dend = e->ray.lheight / 2 + SCRY / 2;
	if (e->ray.dend >= SCRY)
		e->ray.dend = SCRY - 1;
}

void	perform_dda(t_env *e)
{
	while (e->player.hit == 0)
	{
		if (e->ray.side_dist_x < e->ray.side_dist_y)
		{
			e->ray.side_dist_x += e->ray.delta_dist_x;
			e->map.map_x += e->player.step_x;
			e->player.side = 0;
		}
		else
		{
			e->ray.side_dist_y += e->ray.delta_dist_y;
			e->map.map_y += e->player.step_y;
			e->player.side = 1;
		}
		if (e->map.board[e->map.map_x][e->map.map_y] > 0)
			e->player.hit = 1;
	}
}

void	set_side(t_env *e)
{
	if (e->ray.ray_dir_x < 0)
	{
		e->player.step_x = -1;
		e->ray.side_dist_x = (e->ray.ray_pos_x - e->map.map_x) *
		e->ray.delta_dist_x;
	}
	else
	{
		e->player.step_x = 1;
		e->ray.side_dist_x = (e->map.map_x + 1.0 - e->ray.ray_pos_x) *
		e->ray.delta_dist_x;
	}
	if (e->ray.ray_dir_y < 0)
	{
		e->player.step_y = -1;
		e->ray.side_dist_y = (e->ray.ray_pos_y - e->map.map_y) *
		e->ray.delta_dist_y;
	}
	else
	{
		e->player.step_y = 1;
		e->ray.side_dist_y = (e->map.map_y + 1.0 - e->ray.ray_pos_y) *
		e->ray.delta_dist_y;
	}
}

void	set_ray_and_data(int x, t_env *e)
{
	e->player.camera_x = 2 * x / (double)(SCRX) - 1;
	e->ray.ray_pos_x = e->player.pos_x;
	e->ray.ray_pos_y = e->player.pos_y;
	e->ray.ray_dir_x = e->player.dir_x + e->ray.plane_x * e->player.camera_x;
	e->ray.ray_dir_y = e->player.dir_y + e->ray.plane_y * e->player.camera_x;
	e->map.map_x = (int)e->ray.ray_pos_x;
	e->map.map_y = (int)e->ray.ray_pos_y;
	e->ray.delta_dist_x = sqrt(1 + (e->ray.ray_dir_y * e->ray.ray_dir_y) /
		(e->ray.ray_dir_x * e->ray.ray_dir_x));
	e->ray.delta_dist_y = sqrt(1 + (e->ray.ray_dir_x * e->ray.ray_dir_x) /
		(e->ray.ray_dir_y * e->ray.ray_dir_y));
	e->player.hit = 0;
}

void	start_wolf(t_env *e)
{
	int	x;

	x = 0;
	while (x < SCRX)
	{
		set_ray_and_data(x, e);
		set_side(e);
		perform_dda(e);
		super_calculator(e);
		if (e->draw_mode == 0)
			select_color(e);
		if (e->draw_mode == 0)
			draw_base_walls(x, e);
		else if (e->draw_mode == 1)
			draw_texture_walls(x, e);
		draw_sky(x, e);
		draw_floor(x, e);
		x++;
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	if (e->draw_mode == 1)
		select_weapon(e);
}
