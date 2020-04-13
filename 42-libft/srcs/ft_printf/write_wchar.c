/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_write_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 01:52:04 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:04:22 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Write Unicode Caractere :
** .1 octet  0xxxxxxx
** .2 octets 110xxxxx 10xxxxxx
** .3 octets 1110xxxx 10xxxxxx 10xxxxxx
** .4 octets 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
** (1)recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
** (2)recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
** (3)recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
** (4)recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
*/

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

static void	checkjust(t_env *e, int i, wchar_t c)
{
	if (c <= 32 && e->convert.flags[SHOW_SIGN])
	{
		if (e->written == 0)
			e->written++;
	}
	if (i == 1)
	{
		if (e->convert.flags[BASE] == 1)
			wr_justify(e, 0);
	}
	else
	{
		if (e->convert.flags[LEFT_JUSTIFY] == 1)
			wl_justify(e, 0);
	}
}

void		write_wchar(t_env *e, va_list ap)
{
	int		c;

	c = va_arg(ap, int);
	checkjust(e, 1, (wchar_t)c);
	if ((int)c < 0x80)
		ft_putwchar((int)c, e);
	else if ((int)c < 0x800)
	{
		ft_putwchar((int)c >> 6 | 0xC0, e);
		ft_putwchar(((int)c & 0xBF) | 0x80, e);
	}
	else if ((int)c < 0x10000)
	{
		ft_putwchar((int)c >> 12 | 0xE0, e);
		ft_putwchar((((int)c >> 6) & 0xBF) | 0x80, e);
		ft_putwchar(((int)c & 0xBF) | 0x80, e);
	}
	else
	{
		ft_putwchar((int)c >> 18 | 0xF0, e);
		ft_putwchar((((int)c >> 12) & 0xBF) | 0x80, e);
		ft_putwchar((((int)c >> 6) & 0xBF) | 0x80, e);
		ft_putwchar(((int)c & 0xBF) | 0x80, e);
	}
	checkjust(e, 2, (wchar_t)c);
}
