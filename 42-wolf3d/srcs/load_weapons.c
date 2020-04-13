/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:35:50 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/01 23:46:34 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	load_assets_minia(t_env *e)
{
	int	a;
	int	b;

	e->weapon.minia.gun = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/gun/minia-gun.xpm", &a, &b);
	e->weapon.minia.shootgun = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/shootgun/minia-shootgun.xpm", &a, &b);
	e->weapon.minia.rifle = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/rifle/minia-rifle.xpm", &a, &b);
}

void	load_assets_weapons(t_env *e)
{
	int	a;
	int	b;

	e->weapon.knif = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/null.xpm", &a, &b);
	e->weapon.gun_1 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/gun/gun-1.xpm", &a, &b);
	e->weapon.gun_2 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/gun/gun-2.xpm", &a, &b);
	e->weapon.shootgun_1 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/shootgun/shootgun-1.xpm", &a, &b);
	e->weapon.shootgun_2 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/shootgun/shootgun-2.xpm", &a, &b);
	e->weapon.rifle_1 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/rifle/rifle-1.xpm", &a, &b);
	e->weapon.rifle_2 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/rifle/rifle-2.xpm", &a, &b);
}

void	load_assets_reticles(t_env *e)
{
	int	a;
	int	b;

	e->weapon.retic.gun_1 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/gun/reticle_1.xpm", &a, &b);
	e->weapon.retic.gun_2 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/gun/reticle_2.xpm", &a, &b);
	e->weapon.retic.shootgun_1 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/shootgun/reticle-1.xpm", &a, &b);
	e->weapon.retic.shootgun_2 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/shootgun/reticle-2.xpm", &a, &b);
	e->weapon.retic.rifle_1 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/rifle/reticle-1.xpm", &a, &b);
	e->weapon.retic.rifle_2 = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/weaps/rifle/reticle-2.xpm", &a, &b);
}
