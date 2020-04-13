/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:18:40 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:39:22 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_percent_percent(t_pf_env *e)
{
	if (e->str[e->current] == '%')
	{
		ft_putchar('%');
		e->current++;
		e->written++;
		return (1);
	}
	else
		return (0);
}

static int 	handle_conversion(t_pf_env *e, va_list ap)
{
	if (check_percent_percent(e) || e->str[e->current] == '\0')
		return (0);
	printf_parse_flags(e);
	printf_parse_width(e, ap);
	printf_parse_precision(e, ap);
	printf_parse_modificator(e);
	printf_parse_convertor(e);
	return (1);
}

int			printf_read_string(t_pf_env *e, va_list ap)
{
	while (e->str[e->current] != '\0')
	{
		if (e->str[e->current] == '%')
		{
			e->current++;
			e->ret = handle_conversion(e, ap);
			if (e->ret == 1)
				printf_write_arg(e, ap);
		}
		else
		{
			ft_putchar(e->str[e->current]);
			e->current++;
			e->written++;
		}
	}
	return (0);
}
