/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 19:08:17 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/10 22:57:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_env	*fdf;
	t_board *board;

	if (argc != 2)
		usage(NBR_ARGUMENTS);
	if ((fdf = (t_env *)malloc(sizeof(t_env))) == NULL)
		usage(MALLOC_FAILED);
	if ((board = (t_board *)malloc(sizeof(t_board))) == NULL)
		usage(MALLOC_FAILED);
	init_struct(fdf, board);
	if ((fdf->fd = open(argv[1], O_RDONLY)) < 0)
		usage(OPEN_FAILED);
	read_board(fdf);
	if ((fdf->mlx_ptr = mlx_init()) == 0)
		usage(INIT_FAILED);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, SCR_X, SCR_Y, "42 Fil de Fer");
	draw_map(fdf);
	user_instructions(fdf);
	mlx_key_hook(fdf->win_ptr, key_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	close(fdf->fd);
	return (0);
}
