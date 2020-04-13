/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:01:25 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 17:54:48 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_editor(t_env *e)
{
	e->edit.board = ft_create_arrays(40, 50);
	e->edit.start[0] = 2;
	e->edit.start[1] = 2;
	e->edit.size[0] = 5;
	e->edit.size[1] = 5;
	e->edit.select = 1;
	e->edit.sky = 1;
	e->edit.st = 1;
}

void	start_editor(t_env *e)
{
	if (e->edit.st == 0)
		init_editor(e);
	if (!e->win_ptr)
		mlx_clear_window(e->mlx_ptr, e->win_ptr);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->ast.editor_bg, 0, 0);
}
