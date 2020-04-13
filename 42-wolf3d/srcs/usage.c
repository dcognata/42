/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:30:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 13:46:48 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		initialisation(t_env *e)
{
	e->player.dir_x = 1.0;
	e->player.dir_y = 0.0;
	e->ray.plane_x = 0.0;
	e->ray.plane_y = 0.66;
	e->ray.ray_pos_x = e->player.pos_x;
	e->ray.ray_pos_y = e->player.pos_y;
	e->player.rot_speed = 0.04;
	e->player.move_speed = 0.27;
	e->weapon.retic.shoot = SAFE;
	e->weapon.weap = HAND;
}

void		open_file(t_env *e)
{
	int		lvl;

	lvl = e->lvl.level_choice;
	e->lvl.level = e->lvl.array[lvl - 1];
	if ((e->lvl.fd = open(e->lvl.level, O_RDONLY)) < 0)
		usage(OPEN_FAILED);
	parse(e);
}

void		usage(int error)
{
	if (error == MALLOC_FAILED)
		ft_putendl("Wolf3d : Malloc failed.");
	else if (error == INIT_FAILED)
		ft_putendl("Wolf3d : mlx_init() failed.");
	else if (error == END_PROGRAM)
		ft_putendl("Wolf3d : End of Program.");
	else if (error == OPEN_FAILED)
		ft_putendl("Wolf3d : Error 404 - Level not found.");
	else if (error == OPEN_DIR_FAILED)
		ft_putendl("Wolf3d : Error 404 - Levels directory not found.");
	exit(0);
}
