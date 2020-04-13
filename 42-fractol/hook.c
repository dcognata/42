/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/14 18:19:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		image_reload(t_env *e)
{
	if (!e->img_ptr)
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	draw(e);
}

int			motion_hook(int x, int y, t_env *e)
{
	t_fractal *f;

	f = e->frac;
	if (x >= 0 && y >= 0 && x <= SCRX && y <= SCRY && e->p)
	{
		e->frac->rc = -1.0 + 2.0 / (double)SCRX * (double)x;
		e->frac->ic = -1.0 + 2.0 / (double)SCRY * (double)y;
		image_reload(e);
	}
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_R)
		e->init = 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
		mlx_destroy_window(e->mlx_ptr, e->win_ptr);
		usage(END_PROGRAM);
	}
	if (keycode == KEY_LEFT || keycode == KEY_UP ||
		keycode == KEY_RIGHT || keycode == KEY_DOWN)
		move(e, keycode);
	if (keycode == KEY_DEEPM || keycode == KEY_DEEPL)
		deep(e, keycode);
	if (keycode == KEY_MORE || keycode == KEY_LESS)
		zoom(e, keycode, 400, 300);
	if (keycode == KEY_P)
		e->p = !(e->p);
	image_reload(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if ((button == 4 || button == 5 || button == 1 ||
		button == 2) && x >= 0 && y >= 0)
		zoom(e, button, x, y);
	image_reload(e);
	return (0);
}
