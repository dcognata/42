/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 22:12:49 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 00:16:51 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB_H
# define FTLIB_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

void	ft_putchar(char c);
char	*ft_strnew(size_t size);
void	ft_putstr(char const *s);
void	ft_putnbr(long long int n);
void	ft_putunbr(unsigned long long int n);
int		ft_isdigit(int c);
char	*ft_itoa(long long int n);
char	*ft_itoa_base(long long int n, int base, int maj);
char	*ft_uitoa(unsigned long long int n);
char	*ft_uitoa_base(unsigned long long int n, int base, int maj);
void	ft_bzero(void *s, size_t n);
int		ft_lenint(long long int cp);
int		ft_lenuint(unsigned long long int cp);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
