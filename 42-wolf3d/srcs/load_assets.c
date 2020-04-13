/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:35:57 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/03 17:59:11 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void			load_assets_load(t_env *e)
{
	int			a;
	int			b;

	e->ast.load_screen = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/loading/loadscreen.xpm", &a, &b);
	e->ast.load_msg = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/loading/loading.xpm", &a, &b);
	e->ast.load_fstate = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/loading/state_first.xpm", &a, &b);
	e->ast.load_sstate = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/loading/state_second.xpm", &a, &b);
	e->ast.load_tstate = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/loading/state_third.xpm", &a, &b);
	e->ast.load_ftstate = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/loading/state_fourth.xpm", &a, &b);
}

void			load_assets_menu(t_env *e)
{
	int			a;
	int			b;

	e->ast.title = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/title.xpm", &a, &b);
	e->ast.play = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/play.xpm", &a, &b);
	e->ast.edit = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/editor.xpm", &a, &b);
	e->ast.exit = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/exit.xpm", &a, &b);
	e->ast.arrow = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/arrow.xpm", &a, &b);
	e->ast.level = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/level.xpm", &a, &b);
	e->ast.play_h = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/play_hover.xpm", &a, &b);
	e->ast.edit_h = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/editor_hover.xpm", &a, &b);
	e->ast.exit_h = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/menu/exit_hover.xpm", &a, &b);
}

void			load_assets_editor(t_env *e)
{
	int			a;
	int			b;

	e->ast.editor_bg = mlx_xpm_file_to_image(e->mlx_ptr,
		"./assets/editor/editor.xpm", &a, &b);
}

void			load_assets(t_env *e)
{
	load_assets_load(e);
	reload_load_screen(e, 1);
	load_assets_menu(e);
	load_assets_minia(e);
	reload_load_screen(e, 2);
	load_assets_editor(e);
	load_assets_weapons(e);
	reload_load_screen(e, 3);
	load_textures(e);
	load_assets_reticles(e);
	reload_load_screen(e, 4);
}
