/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_rifle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 04:02:00 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 23:34:26 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	display_rifle(t_env *e)
{
	if (e->weapon.retic.shoot == SAFE)
	{
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.retic.rifle_1, 578, 296);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.rifle_1, 730, 526);
	}
	else
	{
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.rifle_2, 730, 526);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.retic.rifle_2, 578, 296);
	}
}
