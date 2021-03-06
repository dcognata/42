/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 04:10:25 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/30 15:53:24 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ftlib.h"

int		ft_lenuint(unsigned long long int cp)
{
	int nblen;

	if (cp == 0)
		return (1);
	nblen = 0;
	while (cp != 0)
	{
		nblen++;
		cp = cp / 10;
	}
	return (nblen);
}
