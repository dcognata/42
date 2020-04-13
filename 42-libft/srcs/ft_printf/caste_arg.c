/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_caste_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 18:48:58 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 22:02:41 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*caste_unsigned_type(t_env *e, void *t)
{
	if (e->modificator.m == L)
		return ((void *)(unsigned long long)t);
	else if (e->modificator.m == LL)
		return ((void *)(unsigned long long)(unsigned long)t);
	else if (e->modificator.m == H)
		return ((void *)(unsigned long long)(unsigned short)t);
	else if (e->modificator.m == HH)
		return ((void *)(unsigned long long)(unsigned char)t);
	else if (e->modificator.m == J)
		return ((void *)(unsigned long long)t);
	else if (e->modificator.m == Z)
		return ((void *)(unsigned long long)(size_t)t);
	return ((void *)(unsigned long long)(unsigned int)t);
}

void		*caste_normal_type(t_env *e, void *t)
{
	if (e->type == 'U' || e->type == 'O')
		return ((void *)(unsigned long long)(unsigned long)t);
	else if (e->type == 'D')
		return ((void *)(long long)(long)t);
	else if (e->type == 'u' || e->type == 'o' || e->type == 'X' ||
		e->type == 'x')
		return (caste_unsigned_type(e, t));
	if (e->modificator.m == L)
		return ((void *)(long long)(long)t);
	else if (e->modificator.m == LL)
		return ((void *)(long long)t);
	else if (e->modificator.m == H)
		return ((void *)(long long)(short)t);
	else if (e->modificator.m == HH)
		return ((void *)(long long)(char)t);
	else if (e->modificator.m == J)
		return ((void *)(long long)t);
	else if (e->modificator.m == Z)
		return ((void *)(long long)(size_t)t);
	return ((void *)(long long)(int)t);
}
