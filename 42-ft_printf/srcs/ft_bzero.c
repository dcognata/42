/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:48:10 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/20 22:24:08 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ftlib.h"

void		ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
		*ptr++ = '\0';
}
