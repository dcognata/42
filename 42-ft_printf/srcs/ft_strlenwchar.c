/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenwchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:56:18 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/20 22:24:53 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ftlib.h"

int		ft_strlenwchar(wchar_t *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((int)s[i] < 0x80)
			j += 1;
		else if ((int)s[i] < 0x800)
			j += 2;
		else if ((int)s[i] < 0x10000)
			j += 3;
		else
			j += 4;
		i++;
	}
	return (j);
}

int		ft_strlenwchars(wchar_t s)
{
	int	j;

	j = 0;
	if ((int)s < 0x80)
		j += 1;
	else if ((int)s < 0x800)
		j += 2;
	else if ((int)s < 0x10000)
		j += 3;
	else
		j += 4;
	return (j);
}
