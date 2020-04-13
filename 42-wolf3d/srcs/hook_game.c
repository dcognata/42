/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 18:02:17 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/25 14:06:38 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		rotate(int keycode, t_env *e)
{
	e->tmp.old_dir_x = e->player.dir_x;
	e->tmp.old_plane_x = e->ray.plane_x;
	if (keycode == KEY_D)
	{
		e->player.dir_x = e->player.dir_x * cos(-e->player.rot_speed)
			- e->player.dir_y * sin(-e->player.rot_speed);
		e->player.dir_y = e->tmp.old_dir_x * sin(-e->player.rot_speed)
			+ e->player.dir_y * cos(-e->player.rot_speed);
		e->ray.plane_x = e->ray.plane_x * cos(-e->player.rot_speed)
			- e->ray.plane_y * sin(-e->player.rot_speed);
		e->ray.plane_y = e->tmp.old_plane_x * sin(-e->player.rot_speed)
			+ e->ray.plane_y * cos(-e->player.rot_speed);
	}
	else if (keycode == KEY_A)
	{
		e->player.dir_x = e->player.dir_x * cos(e->player.rot_speed)
			- e->player.dir_y * sin(e->player.rot_speed);
		e->player.dir_y = e->tmp.old_dir_x * sin(e->player.rot_speed)
			+ e->player.dir_y * cos(e->player.rot_speed);
		e->ray.plane_x = e->ray.plane_x * cos(e->player.rot_speed)
			- e->ray.plane_y * sin(e->player.rot_speed);
		e->ray.plane_y = e->tmp.old_plane_x * sin(e->player.rot_speed)
			+ e->ray.plane_y * cos(e->player.rot_speed);
	}
}

void		move(int keycode, t_env *e)
{
	if (keycode == KEY_W)
	{
		if (!(e->map.board[(int)(e->player.pos_x + e->player.dir_x
			* e->player.move_speed)][(int)e->player.pos_y]))
			e->player.pos_x += e->player.dir_x * e->player.move_speed;
		if (!(e->map.board[(int)e->player.pos_x][(int)(e->player.pos_y +
			e->player.dir_y * e->player.move_speed)]))
			e->player.pos_y += e->player.dir_y * e->player.move_speed;
	}
	else if (keycode == KEY_S)
	{
		if (!(e->map.board[(int)(e->player.pos_x - e->player.dir_x
			* e->player.move_speed)][(int)e->player.pos_y]))
			e->player.pos_x -= e->player.dir_x * e->player.move_speed;
		if (!(e->map.board[(int)e->player.pos_x][(int)(e->player.pos_y
			- e->player.dir_y * e->player.move_speed)]))
			e->player.pos_y -= e->player.dir_y * e->player.move_speed;
	}
}

void		game_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_W || keycode == KEY_S)
	{
		move(keycode, e);
		wolf_reload(e);
	}
	else if (keycode == KEY_D || keycode == KEY_A)
	{
		rotate(keycode, e);
		wolf_reload(e);
	}
	else if (keycode == KEY_T)
	{
		if (e->draw_mode == 0)
			e->draw_mode = 1;
		else if (e->draw_mode == 1)
			e->draw_mode = 0;
		wolf_reload(e);
	}
	else if (keycode == KEY_R)
	{
		e->player.pos_x = e->player.bpos_x;
		e->player.pos_y = e->player.bpos_y;
		wolf_reload(e);
	}
}
