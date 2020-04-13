/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:05:44 by dcognata          #+#    #+#             */
/*   Updated: 2016/01/09 16:20:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_percentage(int percent, int nb)
{
	return (nb = ((percent * nb) / 100));
}

void		is_numeric(char *str)
{
	int		i;
	int		result;
	int		matchnb;

	i = 0;
	matchnb = 0;
	while (str[i] != '\0')
	{
		result = ft_isdigit(str[i]);
		if (str[i] == '-' && matchnb == 1)
			usage(BAD_CONTENT);
		if (result == 1)
			matchnb = 1;
		i++;
	}
}
