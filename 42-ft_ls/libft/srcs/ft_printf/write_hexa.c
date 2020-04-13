/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:37:09 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:18:38 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		wr_prec(t_pf_env *e, int lng)
{
	int			i;
	int			j;

	i = 0;
	if (e->convert.flags[SHARP] == 1 && (e->width.bz != 1 || e->width.w >= lng)
		&& e->precision.p > 1)
	{
		ft_putstr("0x");
		e->written += 2;
	}
	if (e->width.w > e->precision.p)
	{
		j = e->width.w - e->precision.p;
		while (j--)
		{
			ft_putchar(' ');
			e->written++;
		}
	}
	j = e->precision.p - lng;
	while (j--)
	{
		ft_putchar('0');
		e->written++;
	}
}

static void		wrz_justify(t_pf_env *e, int w)
{
	int			i;

	i = 0;
	while (i < w)
	{
		ft_putchar('0');
		i++;
	}
	e->written += w;
}

static void		wr_base(t_pf_env *e, int lng)
{
	int			w;
	int			i;

	i = 0;
	w = e->width.w - lng;
	if (e->width.bz != 1)
	{
		if (e->convert.flags[SHARP] == 1)
			w -= 2;
		while (i < w)
		{
			ft_putchar(' ');
			i++;
		}
		e->written += w;
	}
	else
		wrz_justify(e, w);
}

static void		wl_justify(t_pf_env *e, int lng)
{
	if (e->convert.flags[SHARP] == 1 && e->precision.p < 1 && e->width.w == 0)
	{
		ft_putstr("0x");
		e->written += 2;
	}
	if (e->convert.flags[SHARP] == 1 && e->width.bz == 1 && e->width.w >= lng)
	{
		ft_putstr("0x");
		e->written += 2;
		e->width.w -= 2;
	}
	if (e->precision.p != 0 && e->precision.p > lng)
		wr_prec(e, lng);
	else if (e->width.w > lng && e->convert.flags[BASE] == 1)
		wr_base(e, lng);
	if (e->convert.flags[SHARP] == 1 && e->width.bz != 1 && e->width.w >= lng
		&& e->precision.p < 1)
	{
		ft_putstr("0x");
		e->written += 2;
	}
}

void			printf_write_hexa(t_pf_env *e, va_list ap)
{
	int			i;
	void		*d;
	char		*str;
	int			lng;

	i = 0;
	d = va_arg(ap, void *);
	if (printf_except_x(e, (unsigned long long)d) != 1)
		return ;
	d = printf_caste_normal_type(e, d);
	if (printf_except_xx(e, (long long)d))
		return ;
	str = ft_itoa_base((long long int)d, 16, 0);
	lng = ((int)ft_strlen(str));
	wl_justify(e, lng);
	ft_putstr(str);
	e->written += lng;
	if (e->convert.flags[LEFT_JUSTIFY] == 1 && e->width.w > lng)
	{
		e->written += e->width.w - lng;
		while (e->width.w-- > lng)
			ft_putchar(' ');
	}
	free(str);
}
