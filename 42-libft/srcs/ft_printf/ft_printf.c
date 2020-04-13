/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 22:54:31 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/08 15:35:36 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
