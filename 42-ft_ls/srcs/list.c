/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:25:08 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/24 23:37:09 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			add_item(t_lslist **list, char *path, char *name)
{
	t_lslist	*new_item;
	t_lslist	*tmp_item;


	if ((new_item = (t_lslist *)malloc(sizeof(t_lslist))) == NULL)
		force_exit(NULL, NULL, ERR_MALLOC);
	new_item->path = path;
	new_item->name = name;
	new_item->stat = NULL;
	new_item->error = FALSE;
	new_item->next = NULL;
	if (*list != NULL)
	{
		tmp_item = *list;
		while (tmp_item->next != NULL)
			tmp_item = tmp_item->next;
		tmp_item->next = new_item;
	}
	else
		*list = new_item;
}