/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_shootgun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:32:45 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 23:41:37 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	display_shootgun(t_env *e)
{
	if (e->weapon.retic.shoot == SAFE)
	{
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.retic.shootgun_1, 578, 296);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.shootgun_1, 730, 484);
	}
	else
	{
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.shootgun_2, 730, 484);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.retic.shootgun_2, 578, 296);
	}
}
