/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parse_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:27:23 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:03:18 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	park_width(t_env *e, va_list ap, char *nb, int t[2])
{
	int		b;

	b = 0;
	while (ft_isdigit(e->str[e->current]) || e->str[e->current] == '*')
	{
		if (e->str[e->current] == '0' && t[1] == 0)
		{
			e->width.bz = 1;
			b = 1;
		}
		else if (e->str[e->current] == '*' && (t[1] == 0 || b == 1))
		{
			e->width.w = va_arg(ap, int);
			e->current++;
			break ;
		}
		else
		{
			nb[t[0]] = e->str[e->current];
			t[0]++;
		}
		t[1]++;
		e->current++;
	}
}

void		parse_width(t_env *e, va_list ap)
{
	char	*nb;
	int		t[2];

	t[0] = 0;
	t[1] = 0;
	nb = ft_strnew(0);
	park_width(e, ap, nb, t);
	if (t[1] >= 1)
	{
		nb[t[0]] = '\0';
		e->width.w = ft_atoi(nb);
		if (e->convert.flags[LEFT_JUSTIFY] != 1)
		{
			e->convert.flags[BASE] = 1;
			e->convert.flags[LEFT_JUSTIFY] = 0;
		}
	}
	if (e->width.w < 0)
	{
		e->width.w *= -1;
		e->convert.flags[BASE] = 0;
		e->convert.flags[LEFT_JUSTIFY] = 1;
	}
	free(nb);
}
