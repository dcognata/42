/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 23:00:33 by dcognata          #+#    #+#             */
/*   Updated: 2015/12/02 02:23:10 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		k;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && j < n)
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
