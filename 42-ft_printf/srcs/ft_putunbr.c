/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:32:06 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/30 19:05:24 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ftlib.h"

void	ft_putunbr(unsigned long long int n)
{
	if (n == 9223372036854775807)
	{
		ft_putstr("9223372036854775807");
		return ;
	}
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
