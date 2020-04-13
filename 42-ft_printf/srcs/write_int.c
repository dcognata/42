/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:41:40 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 04:32:49 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	write_prec(t_env *e, long long int nb, int lng)
{
	if (nb < 0)
		print_less(e);
	if (e->precision.p > 0 && e->convert.flags[SHOW_SIGN] == 1 && nb >= 0
		&& e->width.bz != 1)
	{
		ft_putchar('+');
		e->written++;
	}
	if (e->precision.p > lng || e->convert.flags[BASE] == 1)
	{
		while (lng < e->precision.p)
		{
			e->width.w--;
			ft_putchar('0');
			e->written++;
			lng++;
		}
	}
	return (0);
}

static void	wr_justify(t_env *e, long long int nb, int lng)
{
	char	c;
	int		tmp;

	tmp = 0;
	c = (e->width.bz == 1) ? '0' : ' ';
	if (e->precision.p > lng)
		c = ' ';
	except_i(e, lng, nb, c);
	if (e->width.bz == 1 && e->convert.flags[SHOW_SIGN] == 1 && nb >= 0)
	{
		e->width.w--;
		print_more(e);
	}
	if (nb < 0 && e->precision.p < lng && c != '0')
		e->width.w--;
	while (e->width.w > tmp)
	{
		tmp++;
		ft_putchar(c);
		e->written++;
	}
	(e->precision.p > lng) ? write_prec(e, nb, lng) : 0;
}

static int	wl_justify(t_env *e, long long int nb)
{
	char	c;

	if (e->width.bz == 1 && e->convert.flags[LEFT_JUSTIFY] != 1)
		c = '0';
	else
		c = ' ';
	if (e->convert.flags[SHOW_SIGN] == 1)
		e->width.w--;
	e->width.w -= ft_lenint(nb) - 1;
	if (nb < 0 && e->convert.flags[LEFT_JUSTIFY] != 1)
	{
		print_less(e);
		e->width.w--;
	}
	while (e->width.w > 1)
	{
		e->width.w--;
		ft_putchar(c);
		e->written++;
	}
	return (0);
}

static void	write_nb(t_env *e, long long int nb, int lng)
{
	if (e->precision.p < 0 && e->convert.flags[SHOW_SIGN] == 1 && nb >= 0
		&& e->width.bz != 1)
		print_more(e);
	else if (e->convert.flags[SHOW_SIGN] == 1 && nb >= 0 && e->width.bz == 1
		&& e->width.w < lng && lng > 1 && e->width.w > 0)
	{
		ft_putchar('+');
		e->written++;
	}
	else if (e->convert.flags[SHOW_SIGN] == 1 && nb < 0 && e->width.bz != 1)
		print_less(e);
	else if (nb < 0 && e->width.bz != 1 && e->precision.p < 0
		&& e->convert.flags[BASE] != 1)
	{
		e->width.w--;
		print_less(e);
	}
	else if (nb < 0 && e->width.bz != 1 && e->precision.p < lng
		&& e->convert.flags[BASE] == 1 && (e->precision.p == -1 ||
			e->width.w > lng))
	{
		e->width.w--;
		print_less(e);
	}
}

void		write_int(t_env *e, va_list ap)
{
	int		lng;
	void	*d;

	d = va_arg(ap, void *);
	d = caste_normal_type(e, d);
	if (e->precision.p == 0 && (int)d == 0 && e->width.w == 0)
		return ;
	lng = ft_lenint((long long)d);
	if (e->precision.p > 0 && (e->convert.flags[BASE] != 1 || e->width.w < lng))
		write_prec(e, (long long)d, lng);
	if (e->width.bz == 1 && (int)d < 0 && e->precision.p < lng)
	{
		e->width.w--;
		print_less(e);
	}
	if (e->convert.flags[IF_NEGATIVE] == 1 && (long long)d >= 0
		&& e->convert.flags[SHOW_SIGN] != 1)
		ft_writemchar(' ', e);
	if (e->convert.flags[BASE] == 1 && e->width.w > lng)
		wr_justify(e, (long long)d, lng);
	write_nb(e, (long long)d, lng);
	ft_putnbr((long long)d);
	e->written += ft_lenint((long long)d);
	(e->convert.flags[LEFT_JUSTIFY] == 1) ? wl_justify(e, (long long)d) : 0;
}
