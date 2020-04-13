/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/20 21:57:40 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move(t_env *fdf, t_board *ptr, int keycode)
{
	if (keycode == KEY_BOTTOM)
		while (ptr != NULL)
		{
			ptr->draw_y += fdf->move_value;
			ptr = ptr->next;
		}
	if (keycode == KEY_RIGHT)
		while (ptr != NULL)
		{
			ptr->draw_x += fdf->move_value;
			ptr = ptr->next;
		}
	if (keycode == KEY_TOP)
		while (ptr != NULL)
		{
			ptr->draw_y -= fdf->move_value;
			ptr = ptr->next;
		}
	if (keycode == KEY_LEFT)
		while (ptr != NULL)
		{
			ptr->draw_x -= fdf->move_value;
			ptr = ptr->next;
		}
}

void		move_it(t_env *fdf, int keycode)
{
	t_board *ptr;

	fdf->move_value = fdf->move_value + 8;
	ptr = fdf->first;
	ft_move(fdf, ptr, keycode);
	fdf->nb_move++;
}

void		ft_upz(t_board *ptr, int keycode)
{
	if (keycode == KEY_MORE_2)
	{
		while (ptr != NULL)
		{
			if (ptr->value < 0)
				if ((ptr->value -= 2) == 0)
					ptr->value -= 1;
			if (ptr->value > 0)
				if ((ptr->value += 2) == 0)
					ptr->value += 1;
			ptr = ptr->next;
		}
	}
	if (keycode == KEY_LESS_2)
	{
		while (ptr != NULL)
		{
			if (ptr->value < 0 && (ptr->value += 2) == 0)
				ptr->value += 1;
			if (ptr->value > 0)
				if ((ptr->value -= 2) == 0)
					ptr->value -= 1;
			ptr = ptr->next;
		}
	}
}

void		upz(t_env *fdf, int keycode)
{
	t_board *ptr;

	ptr = fdf->first;
	ft_upz(ptr, keycode);
}
