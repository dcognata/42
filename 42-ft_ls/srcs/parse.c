/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:59:28 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/26 21:49:28 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			parse_args(t_lslist **list, char **to_parse, char *flags)
{
	int			i;

	i = 0;
	if (to_parse[i] != NULL)
	{
		while (to_parse[i])
		{
			add_item(list, "./", to_parse[i]);
			i++;
		}
	}
	else
	{
		add_item(list, "./", ".");
		*flags |= NO_ARGS;
	}
}

static void		set_flags(char *str, char *flags)
{
	int			i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != 'l' && str[i] != 'R' && str[i] != 'a' &&
			str[i] != 'r' && str[i] != 't' && str[i] != 'g')
			force_exit(NULL, &str[i], ERR_FLAG);
		if (str[i] == 'l')
			*flags |= FLAG_L;
		else if (str[i] == 'R')
			*flags |= FLAG_RR;
		else if (str[i] == 'a')
			*flags |= FLAG_A;
		else if (str[i] == 'r')
			*flags |= FLAG_R;
		else if (str[i] == 't')
			*flags |= FLAG_T;
		else if (str[i] == 'g')
			*flags |= FLAG_G;
		i++;
	}
}

char			**parse_flags(int argc, char **argv, char *flags)
{
	int			i;

	i = 1;
	if (argc >= 2)
	{
		if (argv[i][0] == '-')
		{
			while (argv[i] != NULL && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
			{
				set_flags(argv[i], flags);
				i++;
			}
		}
		return (&argv[i]);
	}
	return (NULL);
}
