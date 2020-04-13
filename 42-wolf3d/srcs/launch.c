/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 23:06:02 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/03 18:00:42 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	reload_load_screen(t_env *e, int state)
{
	if (!e->win_ptr)
		mlx_clear_window(e->mlx_ptr, e->win_ptr);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_screen, 0, 0);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_msg, 530, 218);
	if (state == 1)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_fstate,
			432, 329);
	else if (state == 2)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_sstate,
			432, 329);
	else if (state == 3)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_tstate,
			432, 329);
	else if (state == 4)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_ftstate,
			432, 329);
	usleep(500000);
}

int		select_x_arrow(t_env *e)
{
	int	x;

	x = 370;
	if (e->lvl.level_choice == 2)
		x = 370 + (1 * 59);
	else if (e->lvl.level_choice == 3)
		x = 370 + (2 * 59);
	else if (e->lvl.level_choice == 4)
		x = 370 + (3 * 59);
	else if (e->lvl.level_choice == 5)
		x = 370 + (4 * 59);
	else if (e->lvl.level_choice == 6)
		x = 370 + (5 * 59);
	else if (e->lvl.level_choice == 7)
		x = 370 + (6 * 59);
	else if (e->lvl.level_choice == 8)
		x = 370 + (7 * 59);
	else if (e->lvl.level_choice == 9)
		x = 370 + (8 * 59);
	return (x);
}

void	display_menu(t_env *e)
{
	int	x;

	if (!e->win_ptr)
		mlx_clear_window(e->mlx_ptr, e->win_ptr);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.load_screen, 0, 0);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.title, 374, 62);
	if (e->select == 1)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.play_h,
			559, 265);
	else
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.play, 559, 265);
	if (e->select == 2)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.edit_h,
			527, 430);
	else
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.edit, 527, 430);
	if (e->select == 3)
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.exit_h,
			591, 556);
	else
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.exit, 591, 556);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.level, 401, 362);
	x = select_x_arrow(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.arrow, x, 372);
}

void	launch(t_env *e)
{
	e->select = 0;
	e->lvl.level = "./level/level.1";
	e->lvl.level_choice = 1;
	e->gui = UI_LOAD;
	load_assets(e);
	e->gui = UI_MENU;
	load_level(e);
	open_file(e);
	display_menu(e);
	parse(e);
}
