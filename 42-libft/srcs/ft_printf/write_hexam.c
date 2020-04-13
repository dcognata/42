/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_write_hexam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:37:09 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:03:45 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		wr_prec(t_env *e, int lng)
{
	int			i;
	int			j;

	i = 0;
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

static void		wrz_justify(t_env *e, int w)
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

static void		wr_base(t_env *e, int lng)
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

static void		wl_justify(t_env *e, int lng)
{
	if (e->precision.p != 0 && e->precision.p > lng)
		wr_prec(e, lng);
	else if (e->width.w > lng && e->convert.flags[BASE] == 1)
		wr_base(e, lng);
	if (e->convert.flags[SHARP] == 1 && (e->width.bz != 1 || e->width.w >= lng))
	{
		ft_putstr("0X");
		e->written += 2;
	}
}

void			write_hexam(t_env *e, va_list ap)
{
	int			i;
	void		*d;
	char		*str;
	int			lng;

	i = 0;
	d = va_arg(ap, void *);
	if (e->precision.p == 0 && d == 0 && e->width.w == 0)
		return ;
	d = caste_normal_type(e, d);
	if (except_xm(e, (unsigned long long)d))
		return ;
	str = ft_itoa_base((long long int)d, 16, 1);
	lng = ((int)ft_strlen(str));
	wl_justify(e, lng);
	ft_putstr(str);
	e->written += lng;
	if (e->convert.flags[LEFT_JUSTIFY] == 1 && e->width.w > lng)
	{
		e->written += e->width.w - 4;
		while (e->width.w-- > lng)
			ft_putchar(' ');
		e->written -= ft_strlen(str) - 4;
	}
	free(str);
}
