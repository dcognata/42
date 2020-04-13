/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpoints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/20 22:01:48 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		recalculate_translation(t_env *fdf)
{
	t_board	*ptr;

	ptr = fdf->first;
	fdf->min_x = 0;
	fdf->max_x = 0;
	fdf->min_y = 0;
	fdf->max_y = 0;
	fdf->z_impact = fdf->step / 8 + 1;
	while (ptr != NULL)
	{
		ptr->draw_y = fdf->step * ptr->x + fdf->step * ptr->y
			- fdf->z_impact * ptr->value;
		ptr->draw_x = fdf->step * 2 * ptr->x - fdf->step * 2 * ptr->y;
		ptr = ptr->next;
	}
}

int			validate_translation_x(t_env *fdf)
{
	t_board	*ptr;

	ptr = fdf->first;
	while (ptr != NULL)
	{
		if (ptr->draw_x < fdf->min_x)
			fdf->min_x = ptr->draw_x;
		if (ptr->draw_x > fdf->max_x)
			fdf->max_x = ptr->draw_x;
		ptr = ptr->next;
	}
	if (fdf->max_x - fdf->min_x > SCR_X)
	{
		if (fdf->step > 1)
		{
			fdf->step--;
			recalculate_translation(fdf);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int			validate_translation_y(t_env *fdf)
{
	t_board	*ptr;

	ptr = fdf->first;
	while (ptr != NULL)
	{
		if (ptr->draw_y < fdf->min_y)
			fdf->min_y = ptr->draw_y;
		if (ptr->draw_y > fdf->max_y)
			fdf->max_y = ptr->draw_y;
		ptr = ptr->next;
	}
	if (fdf->max_y - fdf->min_y > SCR_Y)
	{
		if (fdf->step > 1)
		{
			fdf->step--;
			recalculate_translation(fdf);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void		rework_translation_points(t_env *fdf)
{
	t_board *ptr;
	int		val1;
	int		val2;

	ptr = fdf->first;
	while (ptr != NULL)
	{
		val1 = fdf->max_x - fdf->min_x;
		val1 = SCR_X - val1;
		val1 = val1 / 2;
		ptr->draw_x = ptr->draw_x - fdf->min_x + val1;
		val2 = fdf->max_y - fdf->min_y;
		val2 = SCR_Y - val2;
		val2 = val2 / 2;
		ptr->draw_y = ptr->draw_y - fdf->min_y + val2;
		ptr = ptr->next;
	}
}

void		set_translation_points(t_env *fdf)
{
	t_board	*ptr;

	ptr = fdf->first;
	fdf->z_impact = fdf->step / 8 + 1;
	if (fdf->nb_move == 0)
	{
		while (ptr != NULL)
		{
			ptr->draw_y = fdf->step * ptr->x + fdf->step * ptr->y
				- fdf->z_impact * ptr->value;
			ptr->draw_x = fdf->step * 2 * ptr->x - fdf->step * 2 * ptr->y;
			ptr = ptr->next;
		}
		if (fdf->nb_zoom == 0)
		{
			while (validate_translation_x(fdf))
				;
			while (validate_translation_y(fdf))
				;
		}
		rework_translation_points(fdf);
	}
}
