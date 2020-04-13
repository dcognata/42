/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:46:19 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:35:05 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	wr_justify(t_pf_env *e, int lng)
{
	char	c;
	int		tmp;

	tmp = e->width.w;
	if (e->width.bz == 1)
		c = '0';
	else
		c = ' ';
	if (e->precision.p < lng && e->precision.p != -1 && e->width.w > 0)
	{
		while (tmp--)
			ft_writechar(c, e);
	}
	else
	{
		while (tmp > lng)
		{
			tmp--;
			ft_writechar(c, e);
		}
	}
	lng = 0;
}

static void	wl_justify(t_pf_env *e, int lng)
{
	int		tmp;

	tmp = 0;
	if (e->precision.p == -1)
		e->width.w -= lng;
	while (e->width.w > tmp)
	{
		ft_writechar(' ', e);
		tmp++;
	}
}

void		put_str_lmt(t_pf_env *e, char *str, int lng)
{
	int		i;

	i = 0;
	if (e->precision.p < lng && e->precision.p > 0)
	{
		while (i < e->precision.p)
		{
			ft_putchar(str[i]);
			e->written++;
			i++;
		}
	}
	else
	{
		ft_putstr(str);
		e->written += lng;
	}
}

void		printf_write_string(t_pf_env *e, va_list ap)
{
	char	*str;
	int		lng;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	lng = ft_strlen(str);
	if (e->precision.p == 0 && e->width.w <= 0)
		return ;
	else if (e->precision.p == 0 && e->width.w > 0)
	{
		wr_justify(e, lng);
		return ;
	}
	if (lng > e->precision.p && e->width.w > 0 && e->precision.p != -1)
		e->width.w -= e->precision.p;
	if (e->convert.flags[BASE] == 1)
		wr_justify(e, lng);
	put_str_lmt(e, str, lng);
	if (e->convert.flags[LEFT_JUSTIFY] == 1 && e->width.w != 0)
		wl_justify(e, lng);
}
