/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 15:53:50 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 23:34:02 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	select_weapon(t_env *e)
{
	if (e->weapon.weap == 1)
	{
		display_gun(e);
	}
	else if (e->weapon.weap == 2)
	{
		display_shootgun(e);
	}
	else if (e->weapon.weap == 3)
	{
		display_rifle(e);
	}
	else
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr,
			e->weapon.knif, 620, 571);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->weapon.minia.shootgun,
		28, 678);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->weapon.minia.rifle,
		10, 638);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->weapon.minia.gun,
		46, 600);
}
