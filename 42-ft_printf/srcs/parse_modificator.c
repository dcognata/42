/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modificator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:03:56 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/24 19:32:24 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void		parse_modificator(t_env *e)
{
	e->modificator.m = -1;
	if (e->str[e->current] == 'l' || e->str[e->current] == 'h'
		|| e->str[e->current] == 'j' || e->str[e->current] == 'z')
	{
		if (e->str[e->current] == 'l' && e->str[e->current + 1] == 'l')
		{
			e->modificator.m = LL;
			e->current++;
		}
		else if (e->str[e->current] == 'l')
			e->modificator.m = L;
		else if (e->str[e->current] == 'h' && e->str[e->current + 1] == 'h')
		{
			e->modificator.m = HH;
			e->current++;
		}
		else if (e->str[e->current] == 'h')
			e->modificator.m = H;
		else if (e->str[e->current] == 'j')
			e->modificator.m = J;
		else if (e->str[e->current] == 'z')
			e->modificator.m = Z;
		e->current++;
	}
}
