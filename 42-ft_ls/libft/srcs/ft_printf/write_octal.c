/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:37:59 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:35:24 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		wr_prec(t_pf_env *e, int lng)
{
	int			i;
	int			j;

	i = 0;
	j = e->precision.p - lng;
	while (j--)
	{
		ft_putchar('0');
		e->written++;
	}
}

static void		wr_base(t_pf_env *e, int lng)
{
	int			w;
	int			i;

	i = 0;
	w = e->width.w - lng;
	if (e->convert.flags[SHARP] == 1)
		w -= 1;
	while (i < w)
	{
		if (e->width.bz != 1)
			ft_putchar(' ');
		else
			ft_putchar('0');
		i++;
		e->written++;
	}
}

static void		wl_justify(t_pf_env *e, int lng, int d)
{
	int			tmp;

	tmp = lng;
	if (e->precision.p > 0 && e->precision.p > lng)
		tmp = e->precision.p;
	if (e->width.w > lng && e->convert.flags[BASE] == 1)
		wr_base(e, tmp);
	if (e->precision.p > 0 && e->precision.p > lng)
		wr_prec(e, lng);
	if (e->convert.flags[SHARP] == 1 && lng >= 1 && e->precision.p < 1 &&
		d != 0)
	{
		ft_putchar('0');
		e->written++;
		e->width.w--;
	}
}

static void		lprecision(t_pf_env *e, int lng)
{
	int			tmp;

	tmp = 0;
	if (e->convert.flags[LEFT_JUSTIFY] == 1 && e->width.w >
		lng && e->precision.p < e->width.w)
	{
		tmp = lng;
		if (e->width.w > e->precision.p && e->precision.p > 0)
			tmp = e->precision.p;
		while (e->width.w > tmp)
			ft_writemchar(' ', e);
	}
}

void			printf_write_octal(t_pf_env *e, va_list ap)
{
	int			i;
	void		*d;
	char		*str;
	int			lng;

	i = 0;
	d = va_arg(ap, void *);
	d = printf_caste_normal_type(e, d);
	if (printf_return_fdp(e, (int)d) || printf_except_o(e, (unsigned long long)d))
		return ;
	str = ((long long int)d == LONG_MIN) ? "1000000000000000000000"
		: ft_itoa_base((long long int)d, 8, 0);
	lng = ((int)ft_strlen(str));
	wl_justify(e, lng, ft_atoi(str));
	ft_putstr(str);
	e->written += lng;
	lprecision(e, lng);
	printf_free_fdp(str, (long long int)d);
}
