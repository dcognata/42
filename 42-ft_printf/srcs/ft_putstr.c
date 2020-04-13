/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:32:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/20 22:24:50 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ftlib.h"

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
