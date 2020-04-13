/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 22:30:29 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/02 15:17:07 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		set_sky(t_env *e, char *line)
{
	char	**str;
	int		tmp;

	str = ft_strsplit(line, ' ');
	if ((tmp = ft_atoi(str[0])) == 1)
		e->map.sky = 24;
	else if ((tmp = ft_atoi(str[0])) == 2)
		e->map.sky = 25;
}

void		set_map(t_env *e, char *line, int i)
{
	char	**str;
	int		j;

	j = 0;
	str = ft_strsplit(line, ' ');
	while (str[j] != '\0')
	{
		e->map.board[i - 3][j] = ft_atoi(str[j]);
		j++;
	}
}

void		set_start_zone(t_env *e, char *line)
{
	char	**str;

	str = ft_strsplit(line, '|');
	e->player.pos_x = (double)ft_atoi(str[0]);
	e->player.pos_y = (double)(ft_atoi(str[1]) - 0.5);
	e->player.bpos_x = e->player.pos_x;
	e->player.bpos_y = e->player.pos_y;
	initialisation(e);
}

void		set_size(t_env *e, char *line)
{
	char	**str;

	str = ft_strsplit(line, '|');
	e->map.map_x = ft_atoi(str[0]);
	e->map.map_y = ft_atoi(str[1]);
	if (!e->map.board)
		free(e->map.board);
	e->map.board = ft_create_arrays(e->map.map_x, e->map.map_y);
}

void		parse(t_env *e)
{
	int		ret;
	int		i;
	char	*line;

	i = 0;
	ret = 0;
	line = ft_strnew(0);
	while ((ret = get_next_line(e->lvl.fd, &line)) > 0)
	{
		if (i == 0)
			set_size(e, line);
		else if (i == 1)
			set_start_zone(e, line);
		else if (i == 2)
			set_sky(e, line);
		else if (i >= 3)
			set_map(e, line, i);
		if (ret == 0)
			break ;
		i++;
	}
}
