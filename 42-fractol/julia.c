/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/27 18:39:02 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel_julia(t_env *e, t_fractal *f)
{
	int			color;

	color = 0;
	if (f->iz > (0.04 + e->deep / 1000))
		color = BLUE + e->deep;
	else if (f->iz <= (0.04 + e->deep / 1000)
		&& f->iz >= (-0.04 + e->deep / 1000))
		color = GREEN + e->deep;
	else if (f->iz < (-0.04 + e->deep / 1000))
		color = RED + e->deep;
	put_pixel_to_img(e, f->x, f->y, color);
}

void			draw_julia(t_env *e, t_fractal *f)
{
	while (f->x++ < SCRX - 1)
	{
		while (f->y++ < SCRY - 1)
		{
			f->rz = f->min_x + (f->max_x - f->min_x) / SCRX * f->x;
			f->iz = f->min_y + (f->max_y - f->min_y) / SCRY * f->y;
			while (f->a < e->deep)
			{
				f->r = f->rz;
				f->rz = f->rz * f->rz - f->iz * f->iz + f->rc;
				f->iz = 2.0 * f->r * f->iz + f->ic;
				f->a++;
			}
			f->a = 0;
			if (f->rz * f->rz + f->iz * f->iz <= 4.0)
				put_pixel_julia(e, f);
			else
				put_pixel_to_img(e, f->x, f->y, WHITE);
		}
		f->y = 0;
	}
}

void			print_julia(t_env *e)
{
	t_fractal	*f;

	f = e->frac;
	if (e->init == 0)
	{
		f->rc = 0.285;
		f->ic = 0.01;
		f->min_x = -1.6;
		f->max_x = 1.6;
		f->min_y = -1.4;
		f->max_y = 1.4;
		e->deep = 42;
		e->init = 1;
		e->nbzoom = 10;
	}
	f->x = 0;
	f->y = 0;
	f->a = 0;
	draw_julia(e, f);
}
