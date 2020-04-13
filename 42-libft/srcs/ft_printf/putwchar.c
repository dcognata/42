/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:05:18 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 23:05:25 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(int c, t_env *e)
{
	write(1, (unsigned char *)&c, 1);
	if (e->written > 0)
		e->written += 1;
	else
		e->written = 1;
}
