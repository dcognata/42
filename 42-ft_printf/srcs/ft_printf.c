/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 13:46:18 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/20 22:24:36 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list	ap;
	t_env	e;
	int		ret;

	if (format == NULL)
		return (-1);
	ft_bzero(&e, sizeof(t_env));
	e.str = format;
	va_start(ap, format);
	e.ret = read_string(&e, ap);
	if (e.ret == 1)
		e.written = -1;
	va_end(ap);
	ret = e.written;
	ft_bzero(&e, sizeof(t_env));
	return (ret);
}
