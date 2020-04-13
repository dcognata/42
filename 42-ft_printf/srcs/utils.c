/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:18:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 04:30:57 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_less(t_env *e)
{
	ft_putchar('-');
	e->written++;
}

void	print_more(t_env *e)
{
	ft_putchar('+');
	e->written++;
}

int		except_o(t_env *e, unsigned long long d)
{
	if (d == ULLONG_MAX)
	{
		ft_putstr("1777777777777777777777");
		e->written += 22;
		return (1);
	}
	return (0);
}

void	free_fdp(char *str, long long int d)
{
	if (d != LONG_MIN)
		free(str);
}

int		return_fdp(t_env *e, int nb)
{
	if (e->precision.p == 0 && nb == 0 && e->width.w == 0
		&& e->convert.flags[SHARP] != 1)
		return (1);
	return (0);
}
