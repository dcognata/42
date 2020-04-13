/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:58:29 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/27 22:04:15 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			parse_dir(char *path, char *flags, t_bool first)
{
	t_lslist *new_list;

    struct dirent	*pDirent;
    DIR				*pDir;

    new_list = NULL;
	ft_printf("%s:\n", path);
	if ((pDir = opendir(path)) != NULL)
	{
        while ((pDirent = readdir(pDir)) != NULL)
        	add_item(&new_list, ft_strjoin(path, "/"), pDirent->d_name);
		closedir(pDir);
	}
	if ((*flags & FLAG_RR) || first)
		ft_ls(&new_list, flags, FALSE);
}

void			display_error(t_lslist **list, t_bool first)
{
	t_lslist	*list_tmp;

    list_tmp = *list;
	while (list_tmp != NULL)
	{
		if ((list_tmp->stat = (struct stat *)malloc(sizeof(struct stat)))
			== NULL)
			force_exit(NULL, NULL, ERR_MALLOC);
		if (lstat(ft_strjoin(list_tmp->path, list_tmp->name), list_tmp->stat) == -1)
		{
			list_tmp->error = TRUE;
			force_exit(*list, ft_strjoin(list_tmp->path, list_tmp->name), ERR_STAT);
		}
		list_tmp = list_tmp->next;
	}
}

void			ft_ls(t_lslist **list, char *flags, t_bool first)
{
	t_lslist	*list_tmp;

	sort_list(list, flags, first);
    list_tmp = *list;
	display_error(list, first);
	while (list_tmp != NULL)
	{
		// if (!(S_ISDIR(list_tmp->stat->st_mode)) && ((ft_strcmp(list_tmp->name, ".")
			// && ft_strcmp(list_tmp->name, "..")) && list_tmp->error != TRUE))
			ft_printf("%s ", list_tmp->name);
		list_tmp = list_tmp->next;
	}
	ft_printf("\n\n");		
    list_tmp = *list;
	while (list_tmp != NULL)
	{
		if (S_ISDIR(list_tmp->stat->st_mode) && (first || (ft_strcmp(list_tmp->name, ".")
			&& ft_strcmp(list_tmp->name, ".."))) && list_tmp->error != TRUE)
			parse_dir(list_tmp->name, flags, first);
		list_tmp = list_tmp->next;
	}
}