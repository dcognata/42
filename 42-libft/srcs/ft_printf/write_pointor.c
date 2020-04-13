/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_write_pointor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:43:37 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:04:09 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		wr_prec(t_env *e, int w, int lng)
{
	int			i;
	int			j;

	i = 0;
	j = 1;
	e->width.w -= lng + 2;
	if (e->width.w >= 1)
	{
		while (e->width.w--)
		{
			ft_putchar(' ');
			e->written++;
		}
	}
	ft_putstr("0x\0");
	e->written += 2;
	while (i < w)
	{
		ft_putchar('0');
		e->written++;
		i++;
	}
}

static void		wrz_justify(t_env *e, int w)
{
	int			i;

	i = 0;
	ft_putstr("0x\0");
	while (i < w)
	{
		ft_putchar('0');
		i++;
		e->written++;
	}
}

static void		wr_base(t_env *e, int lng, int b)
{
	int			w;
	int			i;

	i = 0;
	w = e->width.w - lng;
	if (e->width.bz != 1)
	{
		while (i < w)
		{
			ft_putchar(' ');
			i++;
			e->written++;
		}
		if (b == 1)
		{
			ft_putstr("0x\0");
			e->written += 2 + w;
		}
	}
	else
		wrz_justify(e, w);
}

static void		w_justify(t_env *e, int lng, char *str)
{
	if (((str[0] == '0' && str[1] == '\0') || e->modificator.m == L)
		&& e->convert.flags[LEFT_JUSTIFY] != 1)
	{
		if (e->width.w > 3)
			wr_base(e, 3, 0);
		if (e->width.bz == 0)
			ft_putstr("0x");
		e->written += 2;
		return ;
	}
	if (e->precision.p > 0)
		wr_prec(e, e->precision.p - lng, lng);
	else if (e->width.w > lng && e->convert.flags[BASE] == 1)
		wr_base(e, lng, 1);
	else
	{
		ft_putstr("0x\0");
		e->written += 2;
	}
}

void			write_pointor(t_env *e, va_list ap)
{
	int			i;
	long int	d;
	char		*str;
	int			lng;

	i = 0;
	d = (long long int)va_arg(ap, void *);
	if (except_p(e, (unsigned long long)d))
		return ;
	str = ft_itoa_base((long long int)d, 16, 0);
	lng = ((int)ft_strlen(str));
	w_justify(e, lng, str);
	ft_putstr(str);
	e->written += lng;
	if (e->convert.flags[LEFT_JUSTIFY] == 1 && e->width.w > (lng + 2))
	{
		e->width.w -= 2;
		e->written += e->width.w - 4;
		while (e->width.w-- > 1)
			ft_putchar(' ');
		e->written -= ft_strlen(str) - 4;
	}
	free(str);
}
