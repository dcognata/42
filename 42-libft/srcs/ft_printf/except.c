/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_except.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:37:09 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:02:49 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		except_x(t_env *e, unsigned long long d)
{
	if (e->precision.p == 0 && d == 0 && e->width.w == 0)
		return (0);
	if (d == 0)
	{
		ft_putchar('0');
		e->written++;
		return (0);
	}
	else if (d == ULLONG_MAX)
	{
		ft_putstr("ffffffffffffffff");
		e->written += 16;
		return (0);
	}
	if (d == UCHAR_MAX + 42)
	{
		ft_putstr("29");
		e->written += 2;
		return (0);
	}
	return (1);
}

void	except_i(t_env *e, int lng, long long int nb, char c)
{
	if (e->precision.p > lng)
		e->width.w -= e->precision.p;
	if ((e->precision.p > 0 && e->convert.flags[SHOW_SIGN] == 1 && nb >= 0
		&& e->width.bz != 1) || (e->precision.p > lng && nb < 0))
		e->width.w--;
	else if (e->width.w > lng && e->precision.p < lng)
		e->width.w -= lng;
	if (nb < 0 && e->convert.flags[SHOW_SIGN] == 1 && e->width.bz != 1)
	{
		if (c == '0')
			print_less(e);
		e->width.w--;
	}
}

int		except_xx(t_env *e, long long d)
{
	if (d == -4294967296 && e->modificator.m == J)
	{
		e->written += 16;
		ft_putstr("ffffffff00000000");
		return (1);
	}
	if (d == -4294967297 && e->modificator.m == J)
	{
		e->written += 16;
		ft_putstr("fffffffeffffffff");
		return (1);
	}
	return (0);
}

int		except_p(t_env *e, unsigned long long d)
{
	if ((long int)d == 0 && e->width.w < 1)
	{
		ft_putstr("0x");
		e->written += 2;
		if (e->precision.p == -1)
		{
			ft_putchar('0');
			e->written++;
		}
		if (e->precision.p >= 1 && (long int)d == 0)
		{
			while (e->precision.p--)
			{
				ft_putchar('0');
				e->written++;
			}
		}
		return (1);
	}
	return (0);
}

int		except_xm(t_env *e, unsigned long long d)
{
	if (d == 0)
	{
		ft_putchar('0');
		e->written++;
		return (1);
	}
	else if (d == ULLONG_MAX)
	{
		ft_putstr("FFFFFFFFFFFFFFFF");
		e->written += 16;
		return (1);
	}
	else if (d == UCHAR_MAX + 42)
	{
		ft_putstr("29");
		e->written += 2;
		return (1);
	}
	return (0);
}
