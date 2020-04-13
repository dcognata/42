/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:44:22 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 15:40:38 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	select_first_range(int x, t_env *e)
{
	if (x >= 1037 && x <= 1070)
		e->edit.select = 1;
	else if (x >= 1080 && x <= 1113)
		e->edit.select = 2;
	else if (x >= 1123 && x <= 1156)
		e->edit.select = 3;
	else if (x >= 1166 && x <= 1199)
		e->edit.select = 4;
	else if (x >= 1209 && x <= 1242)
		e->edit.select = 5;
}

void	editor_mouse_hook(int button, int x, int y, t_env *e)
{
	if (y >= 151 && y <= 240 && button == 1)
		select_first_range(x, e);
	else if (y >= 566 && y <= 599 && button == 1)
	{
		if (x >= 1097 && x <= 1130)
			e->edit.sky = 1;
		else if (x >= 1149 && x <= 1182)
			e->edit.sky = 2;
	}
}
