/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:16:42 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/30 18:11:59 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void		flags_cond(t_env *e)
{
	if (e->str[e->current] == '-')
	{
		e->convert.flags[LEFT_JUSTIFY] = 1;
		e->current++;
		if (e->convert.flags[BASE] == 1)
			e->convert.flags[BASE] = 0;
	}
	else if (e->str[e->current] == '+')
	{
		e->convert.flags[SHOW_SIGN] = 1;
		e->current++;
	}
	else if (e->str[e->current] == ' ')
	{
		e->convert.flags[IF_NEGATIVE] = 1;
		e->current++;
	}
	else if (e->str[e->current] == '#')
	{
		e->convert.flags[SHARP] = 1;
		e->current++;
	}
}

void		parse_flags(t_env *e)
{
	if (ft_isdigit(e->str[e->current]) || e->str[e->current] == '*' ||
		e->str[e->current] == '+')
	{
		e->convert.flags[BASE] = 1;
		e->convert.flags[LEFT_JUSTIFY] = 0;
		if (e->str[e->current] == '0' && e->str[e->current + 1] == '-')
		{
			e->convert.flags[LEFT_JUSTIFY] = 1;
			e->current++;
		}
		else if (e->str[e->current] == '0' && e->str[e->current + 1] == '+')
		{
			e->width.bz = 1;
			e->current++;
		}
	}
	while (e->str[e->current] == '-' || e->str[e->current] == ' '
		|| e->str[e->current] == '+' || e->str[e->current] == '#')
		flags_cond(e);
}
