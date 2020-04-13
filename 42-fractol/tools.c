/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:03:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/10 10:59:36 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		usage(int error)
{
	if (error == 0)
		ft_putstr("Less or more argument.\n");
	if (error == 1)
		ft_putstr("Malloc failed.\n");
	if (error == 2)
		ft_putstr("Bad Fractal...\n");
	if (error == 3)
		ft_putstr("End of Program.\n");
	if (error == 4)
		ft_putstr("mlx_init() failed.\n");
	exit(0);
}

void		put_rules(void)
{
	ft_putstr("Usage: fractol [-m] [-j] [-p]\n");
	exit(0);
}

void		check_fractal(char *fract, int argc, t_env *e)
{
	if (argc != 2)
		usage(NBR_ARGUMENTS);
	if (ft_strcmp(fract, "-m") == 0)
	{
		e->t = "Fract'ol - Mandelbrot =)";
		e->fractal = MDLB;
	}
	else if (ft_strcmp(fract, "-j") == 0)
	{
		e->t = "Fract'ol - Julia =)";
		e->fractal = JL;
	}
	else if (ft_strcmp(fract, "-p") == 0)
	{
		e->t = "Fract'ol - Perso =)";
		e->fractal = PERSO;
	}
	else
	{
		put_rules();
		usage(BAD_FRACTAL);
	}
}
