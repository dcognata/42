/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:30:56 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/07 21:15:47 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_create_arrays(int x, int y)
{
	void	**array;
	int		i;

	i = 0;
	array = (void **)malloc(sizeof(void *) * y);
	while (i < y)
	{
		array[i] = (void *)malloc(sizeof(void *) * x);
		i++;
	}
	return (array);
}
