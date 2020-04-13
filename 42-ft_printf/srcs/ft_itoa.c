/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:54:30 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 00:15:14 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ftlib.h"

static char	*ft_convert(long long int n, int base, char *str, int maj)
{
	long	div;
	char	temp;
	int		i;

	div = 1;
	i = 0;
	temp = 0;
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
	while (n / div >= base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		str[i] = (temp > '9') ? (temp + maj) : temp;
		n %= div;
		div /= base;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa_base(long long int n, int base, int maj)
{
	char	*str;
	int		i;

	str = ft_strnew(0);
	i = 0;
	if (maj == 0)
		maj = 39;
	else
		maj = 7;
	return (ft_convert(n, base, str, maj));
}

char		*ft_itoa(long long int n)
{
	return (ft_itoa_base(n, 10, 0));
}
