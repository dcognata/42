/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:03:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/25 22:18:55 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(t_env *e, t_fractal *f)
{
	int			color;

	color = 0;
	if (f->iz > (4.0 + e->deep / 1000))
		color = GREEN + e->frac->a / e->deep;
	else if (f->iz <= (4.0 + e->deep / 1000) &&
		f->iz >= (-4.0 + e->deep / 1000))
		color = BLUE + e->frac->a / e->deep;
	else if (f->iz < (-4.0 + e->deep / 1000))
		color = RED + e->frac->a / e->deep;
	put_pixel_to_img(e, f->x, f->y, color);
}

void			draw_mandelbrot(t_env *e, t_fractal *f)
{
	while (f->x++ < SCRX - 1)
	{
		while (f->y++ < SCRY - 1)
		{
			f->rc = f->min_x + (f->max_x - f->min_x) / SCRX * f->x;
			f->ic = f->min_y + (f->max_y - f->min_y) / SCRY * f->y;
			f->rz = 0.0;
			f->iz = 0.0;
			while (f->a < e->deep)
			{
				f->r = f->rz;
				f->i = f->iz;
				f->rz = f->r * f->r - f->i * f->i + f->rc;
				f->iz = 2.0 * f->r * f->i + f->ic;
				f->a++;
			}
			f->a = 0;
			if (f->rz * f->rz + f->iz * f->iz > 4.0)
				put_pixel(e, f);
			else
				put_pixel_to_img(e, f->x, f->y, BLACK + 50);
		}
		f->y = 0;
	}
}

void			print_mandelbrot(t_env *e)
{
	t_fractal	*f;

	f = e->frac;
	if (e->init == 0)
	{
		e->deep = 25;
		f->min_x = -2.1;
		f->max_x = 0.6;
		f->min_y = -1.2;
		f->max_y = 1.2;
		e->init = 1;
		e->nbzoom = 10;
	}
	f->x = 0;
	f->y = 0;
	f->a = 0;
	draw_mandelbrot(e, f);
}
