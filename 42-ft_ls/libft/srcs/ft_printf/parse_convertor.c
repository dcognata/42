/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convertor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:49:37 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:40:59 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	first_list(t_pf_env *e)
{
	if (e->str[e->current] == 's')
		e->type = 's';
	else if (e->str[e->current] == 'S')
		e->type = 'S';
	else if (e->str[e->current] == 'd')
		e->type = 'd';
	else if (e->str[e->current] == 'p')
		e->type = 'p';
	else if (e->str[e->current] == 'D')
		e->type = 'D';
	else if (e->str[e->current] == 'i')
		e->type = 'i';
	else if (e->str[e->current] == 'o')
		e->type = 'o';
}

static void	second_list(t_pf_env *e)
{
	if (e->str[e->current] == 'O')
		e->type = 'O';
	else if (e->str[e->current] == 'u')
		e->type = 'u';
	else if (e->str[e->current] == 'U')
		e->type = 'U';
	else if (e->str[e->current] == 'x')
		e->type = 'x';
	else if (e->str[e->current] == 'X')
		e->type = 'X';
	else if (e->str[e->current] == 'c')
		e->type = 'c';
	else if (e->str[e->current] == 'C')
		e->type = 'C';
}

void		printf_parse_convertor(t_pf_env *e)
{
	if (e->str[e->current] == 's' || e->str[e->current] == 'S' ||
		e->str[e->current] == 'd' || e->str[e->current] == 'p' ||
		e->str[e->current] == 'D' || e->str[e->current] == 'i' ||
		e->str[e->current] == 'o')
		first_list(e);
	else if (e->str[e->current] == 'O' || e->str[e->current] == 'u' ||
		e->str[e->current] == 'U' || e->str[e->current] == 'x' ||
		e->str[e->current] == 'X' || e->str[e->current] == 'c' ||
		e->str[e->current] == 'C')
		second_list(e);
	else
	{
		if (e->convert.flags[BASE] == 1)
			printf_write_right_justify(e, 0);
		ft_putchar(e->str[e->current]);
		e->written++;
		if (e->convert.flags[LEFT_JUSTIFY] == 1)
			printf_write_left_justify(e, 0);
	}
	e->current++;
}
