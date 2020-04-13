/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 23:14:18 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/26 21:51:04 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int argc, char **argv)
{
	char		flags;
	t_lslist	*list;
	char		**to_parse;
	
	flags = 0x0;
	list = NULL;
	to_parse = parse_flags(argc, argv, &flags);
	if (to_parse != NULL)
		parse_args(&list, to_parse, &flags);
	else
	{
		add_item(&list, "\0", ".\0");
		flags |= NO_ARGS;
	}
	if (!(flags & FLAG_L) && !(flags & FLAG_RR)
	&& !(flags & FLAG_A) && !(flags & FLAG_R)
	&& !(flags & FLAG_T) && !(flags & FLAG_G))
	{
		flags |= FLAG_NONE;
	}
	ft_ls(&list, &flags, TRUE);
	clean_app(list);
	return (EXIT_SUCCESS);
}
