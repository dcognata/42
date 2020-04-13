/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:22:23 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:09:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_maj_arg(t_pf_env *e, va_list ap)
{
	if (e->type == 's' && e->modificator.m != L)
		printf_write_string(e, ap);
	else if (e->type == 's' && e->modificator.m == L)
		printf_write_wstr(e, ap);
	if (e->type == 'S')
		printf_write_wstr(e, ap);
	else if (e->type == 'D')
	{
		e->modificator.m = L;
		printf_write_int(e, ap);
	}
	else if (e->type == 'O')
		printf_write_octal(e, ap);
	else if (e->type == 'X')
		printf_write_hexam(e, ap);
	else if (e->type == 'U')
		printf_write_uint(e, ap);
	else if (e->type == 'C')
		printf_write_wchar(e, ap);
}

static void	write_min_arg(t_pf_env *e, va_list ap)
{
	if (e->type == 'd')
		printf_write_int(e, ap);
	else if (e->type == 'p')
		printf_write_pointor(e, ap);
	else if (e->type == 'i')
		printf_write_int(e, ap);
	else if (e->type == 'o')
		printf_write_octal(e, ap);
	else if (e->type == 'u')
		printf_write_uint(e, ap);
	else if (e->type == 'x')
		printf_write_hexa(e, ap);
	else if (e->type == 'c')
	{
		if (e->modificator.m == L)
			printf_write_wchar(e, ap);
		else
			printf_write_char(e, ap);
	}
}

void		printf_write_arg(t_pf_env *e, va_list ap)
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
