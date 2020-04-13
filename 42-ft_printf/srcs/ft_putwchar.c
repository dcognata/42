/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:50:50 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 04:43:53 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_putwchar(int c, t_env *e)
{
	write(1, (unsigned char *)&c, 1);
	if (e->written > 0)
		e->written += 1;
	else
		e->written = 1;
}
