/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:42:15 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 04:12:25 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	wr_justify(t_env *e, int nb)
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

static void	wl_justify(t_env *e, int nb)
{
	char	c;
	int		tmp;

	if (e->width.bz == 1 && e->convert.flags[LEFT_JUSTIFY] != 1)
		c = '0';
	else
		c = ' ';
	e->written += e->width.w - 1;
	tmp = ft_lenint(nb) - 1;
	e->width.w -= tmp;
	while (e->width.w-- > 1)
		ft_putchar(c);
}

void		write_char(t_env *e, va_list ap)
{
	void	*c;
	int		tmp;

	tmp = e->width.w;
	c = va_arg(ap, void *);
	c = caste_normal_type(e, c);
	if (e->convert.flags[BASE] == 1)
		wr_justify(e, 0);
	ft_putchar((char)c);
	if (c == 0 && e->convert.flags[BASE] == 1 && tmp == 0)
		e->written++;
	if (e->written < 1)
		e->written = 1;
	else
		e->written++;
	if (e->convert.flags[LEFT_JUSTIFY] == 1)
		wl_justify(e, 0);
}
