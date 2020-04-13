/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 18:02:30 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/25 19:02:43 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	level_key_left(t_env *e)
{
	if (e->lvl.level_choice == 1 && e->lvl.nb != 1)
		e->lvl.level_choice = e->lvl.nb;
	else if (e->lvl.level_choice == 2)
		e->lvl.level_choice = 1;
	else if (e->lvl.level_choice == 3)
		e->lvl.level_choice = 2;
	else if (e->lvl.level_choice == 4)
		e->lvl.level_choice = 3;
	else if (e->lvl.level_choice == 5)
		e->lvl.level_choice = 4;
	else if (e->lvl.level_choice == 6)
		e->lvl.level_choice = 5;
	else if (e->lvl.level_choice == 7)
		e->lvl.level_choice = 6;
	else if (e->lvl.level_choice == 8)
		e->lvl.level_choice = 7;
	else if (e->lvl.level_choice == 9)
		e->lvl.level_choice = 8;
}

void	level_key(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
	{
		if (e->lvl.level_choice == 1 && e->lvl.nb >= 2)
			e->lvl.level_choice = 2;
		else if (e->lvl.level_choice == 2 && e->lvl.nb >= 3)
			e->lvl.level_choice = 3;
		else if (e->lvl.level_choice == 3 && e->lvl.nb >= 4)
			e->lvl.level_choice = 4;
		else if (e->lvl.level_choice == 4 && e->lvl.nb >= 5)
			e->lvl.level_choice = 5;
		else if (e->lvl.level_choice == 5 && e->lvl.nb >= 6)
			e->lvl.level_choice = 6;
		else if (e->lvl.level_choice == 6 && e->lvl.nb >= 7)
			e->lvl.level_choice = 7;
		else if (e->lvl.level_choice == 7 && e->lvl.nb >= 8)
			e->lvl.level_choice = 8;
		else if (e->lvl.level_choice == 8 && e->lvl.nb == 9)
			e->lvl.level_choice = 9;
		else if (e->lvl.level_choice == 9 || e->lvl.level_choice == e->lvl.nb)
			e->lvl.level_choice = 1;
	}
	else
		level_key_left(e);
	display_menu(e);
}

void	select_key(int keycode, t_env *e)
{
	if (e->select == 0 && keycode == KEY_DOWN)
		e->select = 1;
	else if (e->select == 1 && keycode == KEY_DOWN)
		e->select = 2;
	else if (e->select == 2 && keycode == KEY_DOWN)
		e->select = 3;
	else if (e->select == 3 && keycode == KEY_UP)
		e->select = 2;
	else if (e->select == 3 && keycode == KEY_DOWN)
		e->select = 1;
	else if (e->select == 2 && keycode == KEY_UP)
		e->select = 1;
	display_menu(e);
}

void	launch_selection(t_env *e)
{
	if (e->select == 1)
	{
		e->gui = UI_GAME;
		start_wolf(e);
	}
	else if (e->select == 2)
	{
		e->gui = UI_EDITOR;
		start_editor(e);
	}
	else if (e->select == 3)
		leave_program(e);
}

void	menu_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_1)
	{
		e->gui = UI_GAME;
		start_wolf(e);
	}
	else if (keycode == KEY_2)
	{
		e->gui = UI_EDITOR;
		start_editor(e);
	}
	else if (keycode == KEY_3)
		leave_program(e);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		level_key(keycode, e);
		open_file(e);
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		select_key(keycode, e);
	else if (keycode == KEY_ENTER)
		launch_selection(e);
}
