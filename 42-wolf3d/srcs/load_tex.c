/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:35:57 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 13:57:33 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	set_texture(t_env *e, int x, char *str)
{
	e->t[x]->xpm = mlx_xpm_file_to_image(e->mlx_ptr, str, &e->t[x]->s_x,
		&e->t[x]->s_y);
	e->t[x]->img = mlx_get_data_addr(e->t[x]->xpm, &e->t[x]->bpp,
		&e->t[x]->size_l, &e->t[x]->endian);
}

void	load_tex_items(t_env *e)
{
	set_texture(e, 0, "./assets/textures/floor.xpm");
	set_texture(e, 20, "./assets/textures/area_1.xpm");
	set_texture(e, 21, "./assets/textures/area_2.xpm");
	set_texture(e, 22, "./assets/textures/door_1.xpm");
	set_texture(e, 23, "./assets/textures/door_2.xpm");
	set_texture(e, 24, "./assets/textures/sky_1.xpm");
	set_texture(e, 25, "./assets/textures/sky_2.xpm");
}

void	load_tex_s(t_env *e)
{
	set_texture(e, 1, "./assets/textures/wall_0.xpm");
	set_texture(e, 2, "./assets/textures/wall_1.xpm");
	set_texture(e, 3, "./assets/textures/wall_2.xpm");
	set_texture(e, 4, "./assets/textures/wall_3.xpm");
	set_texture(e, 5, "./assets/textures/wall_4.xpm");
	set_texture(e, 6, "./assets/textures/wall_5.xpm");
	set_texture(e, 7, "./assets/textures/wall_6.xpm");
	set_texture(e, 8, "./assets/textures/wall_7.xpm");
	set_texture(e, 9, "./assets/textures/wall_8.xpm");
	set_texture(e, 10, "./assets/textures/wall_9.xpm");
	set_texture(e, 11, "./assets/textures/wall_10.xpm");
	set_texture(e, 12, "./assets/textures/wall_11.xpm");
	set_texture(e, 13, "./assets/textures/wall_12.xpm");
	set_texture(e, 14, "./assets/textures/wall_13.xpm");
	set_texture(e, 15, "./assets/textures/wall_14.xpm");
	set_texture(e, 16, "./assets/textures/wall_15.xpm");
	set_texture(e, 17, "./assets/textures/wall_16.xpm");
	set_texture(e, 18, "./assets/textures/wall_17.xpm");
	set_texture(e, 19, "./assets/textures/wall_18.xpm");
}

void	load_textures(t_env *e)
{
	int	i;

	i = 0;
	while (i < NBTEX)
	{
		if ((e->t[i] = (t_tex *)malloc(sizeof(t_tex))) == NULL)
			usage(MALLOC_FAILED);
		i++;
	}
	load_tex_items(e);
	load_tex_s(e);
}
