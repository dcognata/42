/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:32:27 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 23:53:54 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	display_gun(t_env *e)
{
	if (e->weapon.retic.shoot == SAFE)
	{
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.retic.gun_1, 578, 296);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.gun_1, 730, 498);
	}
	else
	{
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.gun_2, 730, 498);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.retic.gun_2, 578, 296);
	}
}
