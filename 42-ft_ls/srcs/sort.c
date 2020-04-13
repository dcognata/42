/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:21:47 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/26 22:42:59 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			swap_item(t_lslist *a, t_lslist *b)
{
	char		*name_tmp;
	char		*path_tmp;
	struct stat	*stat_tmp;
	t_bool		error_tmp;

	name_tmp = a->name;
	path_tmp = a->path;
	stat_tmp = a->stat;
	error_tmp = a->error;
	a->name = b->name;
	a->path = b->path;
	a->stat = b->stat;
	a->error = b->error;
	b->name  = name_tmp;
	b->path  = path_tmp;
	b->stat  = stat_tmp;
	b->error  = error_tmp;
}

static int		ft_timecmp(t_lslist *a, t_lslist *b)
{
	if (a->stat->st_mtime < b->stat->st_mtime)
		return 1;
	else if (a->stat->st_mtime > b->stat->st_mtime)
		return -1;
	else
	{
		if (a->stat->st_size < b->stat->st_size)
			return 1;
		else if (a->stat->st_size > b->stat->st_size)
			return -1;
	}
	return (0);
}

int				sort_difftime(t_lslist *list, char *flags)
{
	t_lslist	*list_tmp;
	int			is_sort;

    list_tmp = list;
	is_sort = TRUE;
	while (list_tmp && list_tmp->next != NULL)
	{
		if (*flags & FLAG_R)
		{
			if (ft_timecmp(list_tmp, list_tmp->next) > 0)
				swap_item(list_tmp, list_tmp->next);
		}
		else
		{
			if (ft_timecmp(list_tmp, list_tmp->next) < 0)
				swap_item(list_tmp->next, list_tmp);
		}
		list_tmp = list_tmp->next;
	}
	return (is_sort);
}

int				sort_alpha(t_lslist *list, char *flags)
{
	t_lslist	*list_tmp;
	int			is_sort;

    list_tmp = list;
	is_sort = TRUE;
	while (list_tmp && list_tmp->next != NULL)
	{
		if (*flags & FLAG_R)
		{
			if (ft_strcmp(list_tmp->name, list_tmp->next->name) < 0)
				swap_item(list_tmp, list_tmp->next);
		}
		else
		{
			if (ft_strcmp(list_tmp->name, list_tmp->next->name) > 0)
				swap_item(list_tmp->next, list_tmp);
		}
		list_tmp = list_tmp->next;
	}
	return (is_sort);
}

void			sort_list(t_lslist **list, char *flags, t_bool first)
{
	t_bool 		is_sort;

	is_sort = FALSE;
	while (is_sort == FALSE)
		is_sort = sort_alpha(*list, flags);
	if (first == FALSE)
	{
		if (*flags & FLAG_T)
			while (is_sort == FALSE)
				is_sort = sort_difftime(*list, flags);
	}
}