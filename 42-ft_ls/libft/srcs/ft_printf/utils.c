/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:18:21 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:08:01 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_print_less(t_pf_env *e)
{
	ft_putchar('-');
	e->written++;
}

void	printf_print_more(t_pf_env *e)
{
	ft_putchar('+');
	e->written++;
}

int		printf_except_o(t_pf_env *e, unsigned long long d)
{
	if (d == ULLONG_MAX)
	{
		ft_putstr("1777777777777777777777");
		e->written += 22;
		return (1);
	}
	return (0);
}

void	printf_free_fdp(char *str, long long int d)
{
	if (d != LONG_MIN)
		free(str);
}

int		printf_return_fdp(t_pf_env *e, int nb)
{
	if (e->precision.p == 0 && nb == 0 && e->width.w == 0
		&& e->convert.flags[SHARP] != 1)
		return (1);
	return (0);
}
