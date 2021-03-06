/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 02:06:22 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/16 02:08:19 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhitespace(const char c)
{
	if (c == '\t' || c == '\v' || c == '\n' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
