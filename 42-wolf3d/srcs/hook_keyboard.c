/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:42:10 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/26 18:24:12 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		key_press(int keycode, t_env *e)
{
	if (e->gui == UI_GAME && keycode != KEY_T && keycode != KEY_R)
		game_key_hook(keycode, e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("k %d\n", keycode);
	if (keycode == KEY_ESC && e->gui != UI_EDITOR && e->gui != UI_GAME)
		leave_program(e);
	else if (keycode == KEY_ESC && e->gui == UI_GAME)
	{
		e->gui = UI_MENU;
		display_menu(e);
	}
	else if (e->gui == UI_MENU)
		menu_key_hook(keycode, e);
	else if (e->gui == UI_EDITOR)
		editor_key_hook(keycode, e);
	else if (e->gui == UI_GAME && keycode != KEY_A && keycode != KEY_D
			&& keycode != KEY_W && keycode != KEY_S)
		game_key_hook(keycode, e);
	return (0);
}
