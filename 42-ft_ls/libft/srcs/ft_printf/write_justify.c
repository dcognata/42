/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_justify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:53:37 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:12:58 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		printf_write_right_justify(t_pf_env *e, int nb)
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

void		printf_write_left_justify(t_pf_env *e, int nb)
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
