/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 02:23:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/29 00:12:13 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	wr_justify(t_env *e, int lng)
{
	char	c;

	if (e->precision.p > 1 && e->width.w > 0)
		e->width.w -= e->precision.p - 1;
	else if (e->precision.p > 0 && e->width.w > 0)
		e->width.w -= e->precision.p;
	if (e->width.bz == 1)
		c = '0';
	else
		c = ' ';
	while (e->width.w > 0)
	{
		e->width.w--;
		e->written++;
		ft_putchar(c);
	}
	lng = 0;
	return (0);
}

static int	wl_justify(t_env *e)
{
	while (e->width.w--)
	{
		e->written++;
		ft_putchar(' ');
	}
	return (0);
}

static void	write_wc(t_env *e, int c)
{
	if ((int)c < 0x80)
		ft_putwchar(c, e);
	else if (c < 0x800)
	{
		ft_putwchar(c >> 6 | 0xC0, e);
		ft_putwchar((c & 0xBF) | 0x80, e);
	}
	else if (c < 0x10000)
	{
		ft_putwchar(c >> 12 | 0xE0, e);
		ft_putwchar(((c >> 6) & 0xBF) | 0x80, e);
		ft_putwchar((c & 0xBF) | 0x80, e);
	}
	else
	{
		ft_putwchar(c >> 18 | 0xF0, e);
		ft_putwchar(((c >> 12) & 0xBF) | 0x80, e);
		ft_putwchar(((c >> 6) & 0xBF) | 0x80, e);
		ft_putwchar((c & 0xBF) | 0x80, e);
	}
}

static int	print_null(t_env *e, wchar_t *str)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		e->written += 6;
		return (1);
	}
	return (0);
}

void		write_wstr(t_env *e, va_list ap)
{
	wchar_t	*str;
	int		lng;
	int		i;
	int		j;

	str = va_arg(ap, wchar_t *);
	i = 0;
	if (print_null(e, str))
		return ;
	j = ft_strlenwchars(str[i]);
	lng = ft_strlenwchar(str);
	e->width.w -= (e->width.w > 0 && e->precision.p < 0) ? lng : 0;
	(e->convert.flags[BASE] == 1 && e->width.w > 0) ? wr_justify(e, lng) : 0;
	while (str[i] != '\0')
	{
		if (e->precision.p == 0)
			break ;
		j += ft_strlenwchars(str[i]);
		write_wc(e, (int)str[i]);
		if (j > e->precision.p && e->precision.p >
			0 && e->precision.p > e->width.w)
			break ;
		i++;
	}
	(e->convert.flags[1] == 1 && e->width.w > 0) ? wl_justify(e) : 0;
}
