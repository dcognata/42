/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_write_intu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:41:40 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:03:54 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	wr_prec(t_env *e, int lng)
{
	while (lng < e->precision.p - 1)
	{
		ft_putchar('0');
		e->written++;
		lng++;
	}
}

static void	wr_justify(t_env *e, int lng)
{
	char	c;

	if (e->width.bz == 1)
		c = '0';
	else
		c = ' ';
	if (e->precision.p > lng)
		e->width.w -= e->precision.p - lng - 1;
	e->width.w -= lng;
	while (e->width.w-- > 1)
	{
		ft_putchar(c);
		e->written++;
	}
	if (e->precision.p > lng)
		wr_prec(e, lng);
}

static void	wl_justify(t_env *e, int lng)
{
	char	c;

	if (e->width.bz == 1 && e->convert.flags[LEFT_JUSTIFY] != 1)
		c = '0';
	else
		c = ' ';
	e->width.w -= lng;
	while (e->width.w-- > 1)
	{
		ft_putchar(c);
		e->written++;
	}
}

void		write_uint(t_env *e, va_list ap)
{
	void	*d;
	int		lng;

	d = va_arg(ap, void *);
	d = caste_normal_type(e, d);
	if (e->precision.p == 0 && (int)d == 0)
		return ;
	if (d == UINT_MAX + 1 && d != 0)
	{
		ft_putchar('0');
		e->written++;
	}
	lng = ft_lenuint((unsigned long long int)d) - 1;
	if (e->precision.p > 0 && e->convert.flags[BASE] != 1)
		wr_prec(e, lng);
	if (e->convert.flags[BASE] == 1)
		wr_justify(e, lng);
	ft_putunbr((unsigned long long int)d);
	e->written += ft_lenuint((unsigned long long int)d);
	if (e->convert.flags[LEFT_JUSTIFY] == 1 && e->width.w > lng)
		wl_justify(e, lng);
}
