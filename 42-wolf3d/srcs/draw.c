/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:41:58 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/24 23:14:15 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	select_color(t_env *e)
{
	if (e->player.side == 0)
	{
		if (e->player.step_x < 0)
			e->color = SUD;
		else
			e->color = EST;
	}
	else
	{
		if (e->player.step_y < 0)
			e->color = OUEST;
		else
			e->color = NORTH;
	}
}

void	wolf_reload(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	if ((e->img_ptr = mlx_new_image(e->mlx_ptr, SCRX, SCRY)) == NULL)
		usage(INIT_FAILED);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_l, &e->endian);
	start_wolf(e);
}

void	editor_reload(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	if ((e->img_ptr = mlx_new_image(e->mlx_ptr, SCRX, SCRY)) == NULL)
		usage(INIT_FAILED);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_l, &e->endian);
	start_wolf(e);
}

void	put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = x * 4 + y * e->size_l;
	if (e->endian == 1)
	{
		e->img[i + 1] = r;
		e->img[i + 2] = g;
		e->img[i + 3] = b;
		e->img[i] = 1;
	}
	else
	{
		e->img[i] = b;
		e->img[i + 1] = g;
		e->img[i + 2] = r;
		e->img[i + 3] = 1;
	}
}
