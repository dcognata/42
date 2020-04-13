/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:18:40 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/23 04:03:34 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	check_percent_percent(t_env *e)
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

int	handle_conversion(t_env *e, va_list ap)
{
	if (check_percent_percent(e) || e->str[e->current] == '\0')
		return (0);
	parse_flags(e);
	parse_width(e, ap);
	parse_precision(e, ap);
	parse_modificator(e);
	parse_convertor(e);
	return (1);
}

int	read_string(t_env *e, va_list ap)
{
	while (e->str[e->current] != '\0')
	{
		if (e->str[e->current] == '%')
		{
			e->current++;
			e->ret = handle_conversion(e, ap);
			if (e->ret == 1)
				write_arg(e, ap);
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
