/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parse_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:27:23 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:03:13 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	park_precision(t_env *e, va_list ap, char *nb, int t[2])
{
	if (e->str[e->current] == '.')
	{
		e->current++;
		if (e->str[e->current] == '*')
		{
			e->precision.p = va_arg(ap, int);
			e->current++;
			t[1]++;
		}
		while (ft_isdigit(e->str[e->current]))
		{
			nb[t[0]] = e->str[e->current];
			e->current++;
			t[0]++;
		}
	}
	else
	{
		t[1]++;
		e->precision.p = -1;
	}
}

void		parse_precision(t_env *e, va_list ap)
{
	char	*nb;
	int		t[2];

	t[0] = 0;
	t[1] = 0;
	nb = ft_strnew(0);
	park_precision(e, ap, nb, t);
	if (t[1] == 0)
	{
		nb[t[0]] = '\0';
		e->precision.p = ft_atoi(nb);
	}
	free(nb);
}
