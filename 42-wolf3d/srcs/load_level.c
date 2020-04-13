/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:14:05 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/29 20:06:47 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"
#include <dirent.h>

static char		**sort_string(int i, char **array)
{
	char		*tmp;
	int			j;

	j = i;
	i = 0;
	while (0 < j)
	{
		while (array[i + 1] != NULL)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
			}
			i++;
		}
		j--;
		i = 0;
	}
	return (array);
}

static char		**sort_string_array(t_env *e)
{
	char		**array;
	int			i;

	i = 0;
	array = ft_create_arrays(10, 16);
	while ((e->lvl.dirent = readdir(e->lvl.dir)) != NULL)
	{
		if (e->lvl.dirent->d_name[0] != '.')
		{
			array[i] = ft_strjoin("./level/", e->lvl.dirent->d_name);
			array[i][15] = '\0';
			i++;
		}
	}
	array[i] = NULL;
	e->lvl.nb = i--;
	return (sort_string(i, array));
}

void			load_level(t_env *e)
{
	if ((e->lvl.dir = opendir("./level")) == NULL)
		usage(OPEN_DIR_FAILED);
	e->lvl.array = sort_string_array(e);\
}
