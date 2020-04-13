/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 22:54:31 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:39:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(char *format, ...)
{
	va_list	ap;
	t_pf_env	e;
	int		ret;

	if (format == NULL)
		return (-1);
	ft_bzero(&e, sizeof(t_pf_env));
	e.str = format;
	va_start(ap, format);
	e.ret = printf_read_string(&e, ap);
	if (e.ret == 1)
		e.written = -1;
	va_end(ap);
	ret = e.written;
	ft_bzero(&e, sizeof(t_pf_env));
	return (ret);
}
