/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:03:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/25 22:18:55 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;
	int		i;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = x * 4 + y * e->size_l;
	e->img[i] = b;
	e->img[i + 1] = g;
	e->img[i + 2] = r;
	e->img[i + 3] = 1;
}

void		draw(t_env *e)
{
	if (e->fractal == MDLB)
	{
		print_mandelbrot(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
	else if (e->fractal == JL)
	{
		print_julia(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
	else
	{
		print_perso(e);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
}
