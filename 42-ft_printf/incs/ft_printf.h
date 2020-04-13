/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 13:54:02 by dcognata          #+#    #+#             */
/*   Updated: 2016/03/31 04:30:44 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./ftlib.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

# define OKLM  1
# define ERROR 0

# define TRUE  1
# define FALSE 0

# define BASE         0
# define LEFT_JUSTIFY 1
# define SHOW_SIGN    2
# define IF_NEGATIVE  3
# define SHARP        4

# define HH 0
# define H  1
# define LL 2
# define L  3
# define J  4
# define Z  5

typedef struct			s_modif
{
	int					m;
}						t_modif;

typedef struct			s_prec
{
	int					p;
}						t_prec;

typedef struct			s_convert
{
	char				flags[5];
}						t_convert;

typedef struct			s_width
{
	int					bz;
	int					w;
}						t_width;

typedef struct			s_env
{
	char				*str;
	int					current;
	int					written;
	struct s_convert	convert;
	struct s_width		width;
	struct s_prec		precision;
	struct s_modif		modificator;
	char				type;
	int					ret;
}						t_env;

int						return_fdp(t_env *e, int nb);
void					free_fdp(char *str, long long int d);
void					ft_writechar(char c, t_env *e);
void					ft_writemchar(char c, t_env *e);
int						ft_strlenwchar(wchar_t *s);
int						ft_strlenwchars(wchar_t s);
int						ft_printf(char *format, ...);
void					print_less(t_env *e);
void					print_more(t_env *e);
int						read_string(t_env *e, va_list ap);
void					parse_flags(t_env *e);
void					parse_width(t_env *e, va_list ap);
void					parse_precision(t_env *e, va_list ap);
void					parse_modificator(t_env *e);
void					parse_convertor(t_env *e);
void					*caste_normal_type(t_env *e, void *t);
void					write_left_justify(t_env *e, int nb);
void					write_right_justify(t_env *e, int nb);
void					write_arg(t_env *e, va_list ap);
void					write_char(t_env *e, va_list ap);
void					ft_putwchar(int c, t_env *e);
void					write_int(t_env *e, va_list ap);
void					write_uint(t_env *e, va_list ap);
void					write_string(t_env *e, va_list ap);
void					write_pointor(t_env *e, va_list ap);
void					write_hexa(t_env *e, va_list ap);
void					write_hexam(t_env *e, va_list ap);
void					write_octal(t_env *e, va_list ap);
void					write_wchar(t_env *e, va_list ap);
void					write_wstr(t_env *e, va_list ap);
int						except_x(t_env *e, unsigned long long d);
int						except_p(t_env *e, unsigned long long d);
int						except_xx(t_env *e, long long d);
int						except_xm(t_env *e, unsigned long long d);
void					except_i(t_env *e, int lng, long long int nb, char c);
int						except_o(t_env *e, unsigned long long d);

#endif
