/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:03:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/20 22:06:24 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		usage(int error)
{
	if (error == 0)
		ft_putstr("Less or more argument.\n");
	if (error == 1)
		ft_putstr("Malloc failed.\n");
	if (error == 2)
		ft_putstr("Open failed.\n");
	if (error == 3)
		ft_putstr("End of Program.\n");
	if (error == 4)
		ft_putstr("mlx_init() failed.\n");
	if (error == 5)
		ft_putstr("Bad content file.\n");
	if (error == 6)
		ft_putstr("Empty file.\n");
	exit(0);
}

void		user_instructions(t_env *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, (SCR_X - 160), 5, WHITE,
			"FDF - DCOGNATA");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 5, WHITE,
			"Instructions for use :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 27, WHITE,
			"[C] Change map color");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 44, WHITE,
			"[< ^ >] Move map");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 61, WHITE,
			"[+] Zoom in");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 78, WHITE,
			"[-] Zoom out");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, (SCR_X - 212), (SCR_Y - 30),
			WHITE, "[R] Reinitialisation");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, (SCR_Y - 30), WHITE,
			"[ESC] Quit the program");
}

void		init_struct(t_env *fdf, t_board *board)
{
	fdf->first = board;
	fdf->color = WHITE;
	fdf->nbchange = 0;
	fdf->zoom_value = 15;
	fdf->nb_zoom = 0;
	fdf->move_value = 0;
	fdf->nb_move = 0;
	fdf->step = 20;
	fdf->nb_column = -1;
	board->next = NULL;
	board->right = NULL;
	board->down = NULL;
	board->value = -666;
}

void		change_color(t_env *fdf)
{
	fdf->nbchange++;
	fdf->changec = 1;
	if (fdf->nbchange == 5)
		fdf->nbchange = 0;
	if (fdf->nbchange == 0)
		fdf->color = GREY;
	else if (fdf->nbchange == 1)
		fdf->color = RED;
	else if (fdf->nbchange == 2)
		fdf->color = GREEN;
	else if (fdf->nbchange == 3)
		fdf->color = BLUE;
	else if (fdf->nbchange == 4)
		fdf->color = WHITE;
}
