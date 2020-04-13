/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 00:03:21 by dcognata          #+#    #+#             */
/*   Updated: 2016/02/10 22:56:02 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		assign_down_ptr(t_env *fdf)
{
	int		i;
	int		j;
	t_board	*ptr;
	t_board	*tmp;

	i = 0;
	ptr = fdf->first;
	while (i < fdf->nb_line * fdf->nb_column - fdf->nb_column)
	{
		tmp = ptr;
		j = 0;
		while (j < fdf->nb_column)
		{
			tmp = tmp->next;
			j++;
		}
		ptr->down = tmp;
		ptr = ptr->next;
		i++;
	}
}

int			put_in_list(t_board *board, int value, int cntl, int cntc)
{
	t_board	*new;
	t_board	*tmp;

	if (board->value == -666)
	{
		board->x = cntc;
		board->y = cntl;
		board->value = value;
		return (0);
	}
	if ((new = (t_board *)malloc(sizeof(t_board))) == NULL)
		usage(MALLOC_FAILED);
	tmp = board;
	new->x = cntc;
	new->y = cntl;
	new->value = value;
	new->right = NULL;
	new->next = NULL;
	new->down = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	if (tmp->y == new->y)
		tmp->right = new;
	return (0);
}

void		parse_board(t_env *fdf, char *line, int countl)
{
	char	**str;
	int		i;
	int		value;
	int		countc;

	countc = 0;
	str = ft_strsplit(line, ' ');
	i = 0;
	while (str[i] != '\0')
	{
		is_numeric(str[i]);
		value = ft_atoi(str[i]);
		put_in_list(fdf->first, value, countl, countc);
		countc++;
		i++;
	}
	if (fdf->nb_column == -1)
		fdf->nb_column = countc;
	if (fdf->nb_column != countc)
		usage(BAD_CONTENT);
}

int			whileread(char *line, int ret, int countl, t_env *fdf)
{
	int		i;

	i = 0;
	while ((ret = get_next_line(fdf->fd, &line)) >= 0)
	{
		if (i == 0 && ret == 0)
			usage(EMPTY_FILE);
		if (!line[0] && ret == 0)
		{
			fdf->nb_line = countl;
			assign_down_ptr(fdf);
			return (0);
		}
		parse_board(fdf, line, countl);
		if (ret == 0)
		{
			fdf->nb_line = countl + 1;
			assign_down_ptr(fdf);
			return (0);
		}
		countl++;
		i++;
	}
	return (0);
}

int			read_board(t_env *fdf)
{
	char	*line;
	int		ret;
	int		countl;
	int		oklm;

	countl = 0;
	ret = 0;
	line = NULL;
	oklm = whileread(line, ret, countl, fdf);
	return (oklm);
}
