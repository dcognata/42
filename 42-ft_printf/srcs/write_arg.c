/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:22:23 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/30 15:36:43 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	write_maj_arg(t_env *e, va_list ap)
{
	if (e->type == 's' && e->modificator.m != L)
		write_string(e, ap);
	else if (e->type == 's' && e->modificator.m == L)
		write_wstr(e, ap);
	if (e->type == 'S')
		write_wstr(e, ap);
	else if (e->type == 'D')
	{
		e->modificator.m = L;
		write_int(e, ap);
	}
	else if (e->type == 'O')
		write_octal(e, ap);
	else if (e->type == 'X')
		write_hexam(e, ap);
	else if (e->type == 'U')
		write_uint(e, ap);
	else if (e->type == 'C')
		write_wchar(e, ap);
}

void	write_min_arg(t_env *e, va_list ap)
{
	if (e->type == 'd')
		write_int(e, ap);
	else if (e->type == 'p')
		write_pointor(e, ap);
	else if (e->type == 'i')
		write_int(e, ap);
	else if (e->type == 'o')
		write_octal(e, ap);
	else if (e->type == 'u')
		write_uint(e, ap);
	else if (e->type == 'x')
		write_hexa(e, ap);
	else if (e->type == 'c')
	{
		if (e->modificator.m == L)
			write_wchar(e, ap);
		else
			write_char(e, ap);
	}
}

void	write_arg(t_env *e, va_list ap)
{
	if (e->type == 'd' ||
		e->type == 'p' || e->type == 'x' ||
		e->type == 'u' || e->type == 'i' ||
		e->type == 'o' || e->type == 'c')
		write_min_arg(e, ap);
	else if (e->type == 'O' || e->type == 'D' ||
		e->type == 'U' || e->type == 'S' ||
		e->type == 'X' || e->type == 'C' || e->type == 's')
		write_maj_arg(e, ap);
}
