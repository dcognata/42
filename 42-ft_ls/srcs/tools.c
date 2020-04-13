/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:42:46 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/23 00:30:05 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			force_exit(t_lslist *list, char *error, int type)
{
	if (type == ERR_FLAG)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putstr(error);
		ft_putstr("\nusage: ls [-Ralrtg] [file ...]\n");
		exit(EXIT_FAILURE);
	}
	else if (type == ERR_MALLOC)
	{
		ft_printf("\n");
		exit(EXIT_FAILURE);
	}
	else if (type == ERR_STAT)
		ft_printf("ft_ls: %s: %s\n", error, strerror(errno));
}

void			clean_app(t_lslist *list)
{
	t_lslist	*curr;

	while ((curr = list) != NULL)
	{
	    list = curr->next;
	    free(curr->stat);
	    free(curr);
	}
	free(list);
}