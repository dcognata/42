/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/09 16:20:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresh_init_check(t_bresh *bresh, t_draw *draw)
{
	if (bresh->dx < 0)
		bresh->dx = -bresh->dx;
	if (bresh->dy < 0)
		bresh->dy = -bresh->dy;
	bresh->incx = 1;
	if (draw->x2 < draw->x1)
		bresh->incx = -1;
	bresh->incy = 1;
	if (draw->y2 < draw->y1)
		bresh->incy = -1;
	bresh->x = draw->x1;
	bresh->y = draw->y1;
}

void	bresh_if(t_bresh *bresh, t_env *fdf)
{
	draw_pixel(bresh->x, bresh->y, fdf);
	bresh->e = 2 * bresh->dy - bresh->dx;
	bresh->inc1 = 2 * (bresh->dy - bresh->dx);
	bresh->inc2 = 2 * bresh->dy;
	bresh->i = 0;
	while (bresh->i < bresh->dx)
	{
		if (bresh->e >= 0)
		{
			bresh->e += bresh->inc1;
			bresh->y += bresh->incy;
		}
		else
			bresh->e += bresh->inc2;
		bresh->x += bresh->incx;
		draw_pixel(bresh->x, bresh->y, fdf);
		bresh->i++;
	}
}

void	bresh_else(t_bresh *bresh, t_env *fdf)
{
	draw_pixel(bresh->x, bresh->y, fdf);
	bresh->e = 2 * bresh->dx - bresh->dy;
	bresh->inc1 = 2 * (bresh->dx - bresh->dy);
	bresh->inc2 = 2 * bresh->dx;
	bresh->i = 0;
	while (bresh->i < bresh->dy)
	{
		if (bresh->e >= 0)
		{
			bresh->x += bresh->incx;
			bresh->e += bresh->inc1;
		}
		else
			bresh->e += bresh->inc2;
		bresh->y += bresh->incy;
		draw_pixel(bresh->x, bresh->y, fdf);
		bresh->i++;
	}
}
