/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/25 20:05:21 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_pixel(int x, int y, t_env *fdf)
{
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
}

void		draw_segment(t_env *fdf, t_draw *draw)
{
	t_bresh	*bresh;

	if ((bresh = (t_bresh *)malloc(sizeof(t_bresh))) == NULL)
		usage(MALLOC_FAILED);
	bresh->dx = draw->x2 - draw->x1;
	bresh->dy = draw->y2 - draw->y1;
	bresh_init_check(bresh, draw);
	if (bresh->dx > bresh->dy)
		bresh_if(bresh, fdf);
	else
		bresh_else(bresh, fdf);
}

void		draw_map(t_env *fdf)
{
	t_board	*ptr;
	t_draw	*draw;

	if ((draw = (t_draw *)malloc(sizeof(t_draw))) == NULL)
		usage(MALLOC_FAILED);
	set_translation_points(fdf);
	ptr = fdf->first;
	while (ptr != NULL)
	{
		draw->x1 = ptr->draw_x;
		draw->y1 = ptr->draw_y;
		if (ptr->right != NULL)
		{
			draw->x2 = ptr->next->draw_x;
			draw->y2 = ptr->next->draw_y;
			draw_segment(fdf, draw);
		}
		if (ptr->down != NULL)
		{
			draw->x2 = ptr->down->draw_x;
			draw->y2 = ptr->down->draw_y;
			draw_segment(fdf, draw);
		}
		ptr = ptr->next;
	}
}
