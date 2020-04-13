/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:43:10 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/03 17:33:53 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		main(void)
{
	t_env	*e;
	t_tex	*t;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		usage(MALLOC_FAILED);
	if ((t = (t_tex *)malloc(NBTEX * sizeof(t_tex))) == NULL)
		usage(MALLOC_FAILED);
	if ((e->mlx_ptr = mlx_init()) == 0)
		usage(INIT_FAILED);
	if ((e->win_ptr = mlx_new_window(e->mlx_ptr, SCRX, SCRY,
		"Wolf3d - dcognata")) == 0)
		usage(INIT_FAILED);
	if ((e->img_ptr = mlx_new_image(e->mlx_ptr, SCRX, SCRY)) == NULL)
		usage(INIT_FAILED);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_l, &e->endian);
	*e->t = t;
	launch(e);
	mlx_key_hook(e->win_ptr, key_hook, e);
	mlx_mouse_hook(e->win_ptr, mouse_hook, e);
	mlx_hook(e->win_ptr, 2, (1L<<0), key_press, e);
	mlx_hook(e->win_ptr, 6, (1L<<6), motion_hook, e);
	mlx_loop(e->mlx_ptr);
	return (0);
}
