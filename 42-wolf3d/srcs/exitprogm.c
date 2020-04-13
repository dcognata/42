/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitprogm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:27:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 14:39:42 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	destroy_textures(t_env *e)
{
	int	i;

	i = NBTEX - 1;
	while (i > 0)
	{
		mlx_destroy_image(e->mlx_ptr, e->t[i]->xpm);
		free(e->t[i]);
		i--;
	}
}

void	destroy_assets(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->ast.title);
	mlx_destroy_image(e->mlx_ptr, e->ast.play);
	mlx_destroy_image(e->mlx_ptr, e->ast.edit);
	mlx_destroy_image(e->mlx_ptr, e->ast.exit);
	mlx_destroy_image(e->mlx_ptr, e->ast.arrow);
	mlx_destroy_image(e->mlx_ptr, e->ast.level);
	mlx_destroy_image(e->mlx_ptr, e->ast.play_h);
	mlx_destroy_image(e->mlx_ptr, e->ast.edit_h);
	mlx_destroy_image(e->mlx_ptr, e->ast.exit_h);
	mlx_destroy_image(e->mlx_ptr, e->ast.load_screen);
	mlx_destroy_image(e->mlx_ptr, e->ast.load_msg);
	mlx_destroy_image(e->mlx_ptr, e->ast.load_fstate);
	mlx_destroy_image(e->mlx_ptr, e->ast.load_sstate);
	mlx_destroy_image(e->mlx_ptr, e->ast.load_tstate);
	mlx_destroy_image(e->mlx_ptr, e->ast.load_ftstate);
	mlx_destroy_image(e->mlx_ptr, e->ast.editor_bg);
}

void	leave_program(t_env *e)
{
	destroy_assets(e);
	destroy_textures(e);
	destroy_weapons(e);
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	closedir(e->lvl.dir);
	free(e->lvl.array);
	free(e->edit.board);
	free(e->map.board);
	free(e);
	usage(END_PROGRAM);
}
