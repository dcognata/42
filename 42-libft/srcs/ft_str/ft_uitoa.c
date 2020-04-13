/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:54:30 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 21:36:22 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(unsigned long long int n, int base, char *str, int maj)
{
	long	div;
	char	temp;
	int		i;

	i = 0;
	div = 1;
	temp = 0;
	while (n / (unsigned long long)div >= (unsigned long long)base)
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

char		*ft_uitoa_base(unsigned long long int n, int base, int maj)
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

char		*ft_uitoa(unsigned long long int n)
{
	return (ft_itoa_base(n, 10, 0));
}
