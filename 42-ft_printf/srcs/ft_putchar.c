/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:30:23 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/28 23:50:39 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_writechar(char c, t_env *e)
{
	ft_putchar(c);
	e->written++;
}

void	ft_writemchar(char c, t_env *e)
{
	ft_putchar(c);
	e->written++;
	e->width.w--;
}
