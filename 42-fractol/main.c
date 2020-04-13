/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 19:08:17 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/10 11:00:47 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int argc, char **argv)
{
	t_env		*e;
	t_fractal	*f;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		usage(MALLOC_FAILED);
	if ((f = (t_fractal *)malloc(sizeof(t_fractal))) == NULL)
		usage(MALLOC_FAILED);
	check_fractal(argv[1], argc, e);
	if ((e->mlx_ptr = mlx_init()) == 0)
		usage(INIT_FAILED);
	if ((e->img_ptr = mlx_new_image(e->mlx_ptr, SCRX, SCRY)) == 0)
		usage(INIT_FAILED);
	if ((e->win_ptr = mlx_new_window(e->mlx_ptr, SCRX, SCRY, e->t)) == 0)
		usage(INIT_FAILED);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_l, &e->endian);
	e->p = 0;
	e->frac = f;
	e->init = 0;
	image_reload(e);
	mlx_key_hook(e->win_ptr, key_hook, e);
	mlx_mouse_hook(e->win_ptr, mouse_hook, e);
	mlx_hook(e->win_ptr, 6, (1L << 6), motion_hook, e);
	mlx_loop(e->mlx_ptr);
	return (0);
}
