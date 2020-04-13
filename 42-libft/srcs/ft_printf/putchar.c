/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:30:23 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 23:12:53 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
