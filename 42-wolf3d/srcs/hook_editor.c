/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 18:03:45 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/25 12:02:12 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	editor_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		e->gui = UI_MENU;
		display_menu(e);
	}
}
