/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/14 18:15:44 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_hook(int keycode, t_env *fdf)
{
	if (keycode == KEY_MORE_1 || keycode == KEY_LESS_1)
		zoom_in(fdf, keycode);
	if (keycode == KEY_MORE_2 || keycode == KEY_LESS_2)
		upz(fdf, keycode);
	if (keycode == KEY_C)
		change_color(fdf);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		usage(END_PROGRAM);
	}
	if (keycode == KEY_LEFT || keycode == KEY_TOP ||
		keycode == KEY_RIGHT || keycode == KEY_BOTTOM)
		move_it(fdf, keycode);
	if (keycode == KEY_RESET)
		reinit(fdf);
	if (keycode != KEY_ENTER)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw_map(fdf);
		user_instructions(fdf);
	}
	return (0);
}

void		reinit(t_env *fdf)
{
	fdf->color = WHITE;
	fdf->nbchange = 0;
	fdf->changec = 0;
	fdf->zoom_value = 15;
	fdf->nb_zoom = 0;
	fdf->move_value = 0;
	fdf->nb_move = 0;
	fdf->step = 15;
}

void		zoom_in(t_env *fdf, int keycode)
{
	fdf->zoom_value = get_percentage(10, fdf->step) + 2;
	if (keycode == KEY_MORE_1 || keycode == KEY_MORE_2)
	{
		if (fdf->nb_zoom >= -5 && fdf->nb_zoom < 5)
		{
			fdf->nb_move = 0;
			fdf->step += fdf->zoom_value;
			fdf->nb_zoom++;
			fdf->move_value = 0;
		}
	}
	if (keycode == KEY_LESS_1 || keycode == KEY_LESS_2)
	{
		if (fdf->nb_zoom > -4 && fdf->nb_zoom <= 5)
		{
			fdf->nb_move = 0;
			fdf->step -= fdf->zoom_value;
			if (fdf->step < 1)
				fdf->step = 1;
			fdf->nb_zoom--;
			fdf->move_value = 0;
		}
	}
}
