/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:09:57 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 15:53:50 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	game_mouse_hook(int button, t_env *e)
{
	if (button == 1)
	{
		e->weapon.retic.shoot = SHOOT;
		wolf_reload(e);
		e->weapon.retic.shoot = SAFE;
		wolf_reload(e);
		usleep(40000);
	}
	else if (button == 4)
	{
		if (e->weapon.weap >= 1 && e->weapon.weap <= 3)
			e->weapon.weap--;
		wolf_reload(e);
	}
	else if (button == 5)
	{
		if (e->weapon.weap >= 0 && e->weapon.weap <= 2)
			e->weapon.weap++;
		wolf_reload(e);
	}
}

void	menu_motion_hook(int x, int y, t_env *e)
{
	if ((x >= 591 && x <= 768) && (y >= 556 && y <= 641) && e->select != 3)
	{
		e->select = 3;
		display_menu(e);
	}
	else if ((x >= 527 && x <= 826) && (y >= 430 && y <= 541) && e->select != 2)
	{
		e->select = 2;
		display_menu(e);
	}
	else if ((x >= 559 && x <= 768) && (y >= 265 && y <= 341) && e->select != 1)
	{
		e->select = 1;
		display_menu(e);
	}
	else if (e->select != 0 && !(x >= 591 && x <= 768) && !(y >= 556 &&
		y <= 641) && !(x >= 527 && x <= 826) && !(y >= 430 && y <= 541) &&
		!(x >= 559 && x <= 768) && !(y >= 265 && y <= 341))
	{
		e->select = 0;
		display_menu(e);
	}
}

void	menu_mouse_hook(int x, int y, t_env *e)
{
	if ((x >= 550 && x <= 768) && (y >= 570 && y <= 641))
		leave_program(e);
	else if ((x >= 527 && x <= 826) && (y >= 440 && y <= 541))
	{
		e->gui = UI_EDITOR;
		start_editor(e);
	}
	else if ((x >= 559 && x <= 768) && (y >= 275 && y <= 471))
	{
		e->gui = UI_GAME;
		start_wolf(e);
	}
}

int		motion_hook(int x, int y, t_env *e)
{
	if (e->gui == UI_MENU)
		menu_motion_hook(x, y, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("%d\n", button);
	if (e->gui == UI_MENU)
		menu_mouse_hook(x, y, e);
	else if (e->gui == UI_EDITOR)
		editor_mouse_hook(button, x, y, e);
	else if (e->gui == UI_GAME)
		game_mouse_hook(button, e);
	return (0);
}
