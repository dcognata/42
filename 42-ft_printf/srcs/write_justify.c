/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_justify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:53:37 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/22 18:40:55 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void		write_right_justify(t_env *e, int nb)
{
	char	c;

	if (e->width.bz == 1)
		c = '0';
	else
		c = ' ';
	e->written += e->width.w - 1;
	e->width.w -= ft_lenint(nb) - 1;
	if (nb < 0)
	{
		e->width.w--;
		e->written--;
	}
	while (e->width.w-- > 1)
		ft_putchar(c);
}

void		write_left_justify(t_env *e, int nb)
{
	char	c;
	int		tmp;

	if (e->width.bz == 1)
		c = '0';
	else
		c = ' ';
	e->written += e->width.w - 1;
	tmp = ft_lenint(nb) - 1;
	e->width.w -= tmp;
	while (e->width.w-- > 1)
		ft_putchar(c);
}
