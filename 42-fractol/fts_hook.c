/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/08 12:58:46 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			zoomifelse(t_env *e, int but, double *ecart_x, double *ecart_y)
{
	if (but == KEY_MORE || but == 4 || but == 1)
	{
		*ecart_x /= 1.2;
		*ecart_y /= 1.2;
		e->nbzoom += 1;
		if (e->nbzoom % 3 == 0)
			e->deep++;
	}
	else
	{
		*ecart_x *= 1.2;
		*ecart_y *= 1.2;
		e->nbzoom -= 1;
		if (e->nbzoom % 3 == 0)
			e->deep--;
	}
}

void			zoom(t_env *e, int button, int x, int y)
{
	t_fractal	*f;
	double		new_center_x;
	double		new_center_y;
	double		ecart_x;
	double		ecart_y;

	f = e->frac;
	ecart_x = f->max_x - f->min_x;
	ecart_y = f->max_y - f->min_y;
	new_center_x = f->min_x + (ecart_x) / (double)SCRX * (double)x;
	new_center_y = f->min_y + (ecart_y) / (double)SCRY * (double)y;
	zoomifelse(e, button, &ecart_x, &ecart_y);
	f->min_x = new_center_x - ecart_x / 2.0;
	f->max_x = new_center_x + ecart_x / 2.0;
	f->min_y = new_center_y - ecart_y / 2.0;
	f->max_y = new_center_y + ecart_y / 2.0;
}

void			move(t_env *e, int keycode)
{
	t_fractal	*f;

	f = e->frac;
	if (keycode == KEY_DOWN)
	{
		f->min_y -= 0.1;
		f->max_y -= 0.1;
	}
	else if (keycode == KEY_UP)
	{
		f->min_y += 0.1;
		f->max_y += 0.1;
	}
	else if (keycode == KEY_LEFT)
	{
		f->min_x += 0.1;
		f->max_x += 0.1;
	}
	else if (keycode == KEY_RIGHT)
	{
		f->min_x -= 0.1;
		f->max_x -= 0.1;
	}
}

void			deep(t_env *e, int keycode)
{
	if (KEY_DEEPM == keycode)
		e->deep++;
	else
	{
		if (e->deep > 2)
			e->deep--;
	}
}
