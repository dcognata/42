/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_weaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:33:42 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 14:34:37 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	destroy_reticles(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->weapon.retic.gun_1);
	mlx_destroy_image(e->mlx_ptr, e->weapon.retic.gun_2);
	mlx_destroy_image(e->mlx_ptr, e->weapon.retic.shootgun_1);
	mlx_destroy_image(e->mlx_ptr, e->weapon.retic.shootgun_2);
	mlx_destroy_image(e->mlx_ptr, e->weapon.retic.rifle_1);
	mlx_destroy_image(e->mlx_ptr, e->weapon.retic.rifle_2);
}

void	destroy_miniatures(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->weapon.minia.gun);
	mlx_destroy_image(e->mlx_ptr, e->weapon.minia.rifle);
	mlx_destroy_image(e->mlx_ptr, e->weapon.minia.shootgun);
}

void	destroy_weapons(t_env *e)
{
	destroy_miniatures(e);
	destroy_reticles(e);
	mlx_destroy_image(e->mlx_ptr, e->weapon.gun_1);
	mlx_destroy_image(e->mlx_ptr, e->weapon.gun_2);
	mlx_destroy_image(e->mlx_ptr, e->weapon.shootgun_1);
	mlx_destroy_image(e->mlx_ptr, e->weapon.shootgun_2);
	mlx_destroy_image(e->mlx_ptr, e->weapon.rifle_1);
	mlx_destroy_image(e->mlx_ptr, e->weapon.rifle_2);
}
