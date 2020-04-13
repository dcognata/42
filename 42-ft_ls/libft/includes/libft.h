/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:23:36 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/20 11:36:23 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

/*
** libft base
*/
# define BUFF_SIZE 8

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long int n, int base, int maj);
char				*ft_uitoa(unsigned long long int n);
char				*ft_uitoa_base(unsigned long long int n, int base, int maj);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long long int n);
void				ft_putunbr(unsigned long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isspace(char c);
int					ft_lenint(long long int cp);
int					ft_lenuint(unsigned long long int cp);
int					ft_signint(int cp);
int					ft_count_words(char const *s, char c);
int					ft_want_size(char const *s, char c);
int					ft_abs(int n);
void				*ft_create_arrays(int x, int y);
int					get_next_line(int const fd, char **line);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** printf
*/
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

typedef struct			s_pf_modif
{
	int					m;
}						t_pf_modif;

typedef struct			s_pf_prec
{
	int					p;
}						t_pf_prec;

typedef struct			s_pf_convert
{
	char				flags[5];
}						t_pf_convert;

typedef struct			s_pf_width
{
	int					bz;
	int					w;
}						t_pf_width;

typedef struct			s_pf_env
{
	char				*str;
	int					current;
	int					written;
	struct s_pf_convert	convert;
	struct s_pf_width	width;
	struct s_pf_prec	precision;
	struct s_pf_modif	modificator;
	char				type;
	int					ret;
}						t_pf_env;

int		ft_printf(char *format, ...);
int		printf_return_fdp(t_pf_env *e, int nb);
void	printf_free_fdp(char *str, long long int d);
void	printf_print_less(t_pf_env *e);
void	printf_print_more(t_pf_env *e);
int		printf_read_string(t_pf_env *e, va_list ap);
void	printf_parse_flags(t_pf_env *e);
void	printf_parse_width(t_pf_env *e, va_list ap);
void	printf_parse_precision(t_pf_env *e, va_list ap);
void	printf_parse_modificator(t_pf_env *e);
void	printf_parse_convertor(t_pf_env *e);
void	*printf_caste_normal_type(t_pf_env *e, void *t);
void	printf_write_left_justify(t_pf_env *e, int nb);
void	printf_write_right_justify(t_pf_env *e, int nb);
void	printf_write_arg(t_pf_env *e, va_list ap);
void	printf_write_char(t_pf_env *e, va_list ap);
void	printf_write_int(t_pf_env *e, va_list ap);
void	printf_write_uint(t_pf_env *e, va_list ap);
void	printf_write_string(t_pf_env *e, va_list ap);
void	printf_write_pointor(t_pf_env *e, va_list ap);
void	printf_write_hexa(t_pf_env *e, va_list ap);
void	printf_write_hexam(t_pf_env *e, va_list ap);
void	printf_write_octal(t_pf_env *e, va_list ap);
void	printf_write_wchar(t_pf_env *e, va_list ap);
void	printf_write_wstr(t_pf_env *e, va_list ap);
int		printf_except_x(t_pf_env *e, unsigned long long d);
int		printf_except_p(t_pf_env *e, unsigned long long d);
int		printf_except_xx(t_pf_env *e, long long d);
int		printf_except_xm(t_pf_env *e, unsigned long long d);
void	printf_except_i(t_pf_env *e, int lng, long long int nb, char c);
int		printf_except_o(t_pf_env *e, unsigned long long d);
void	ft_putwchar(int c, t_pf_env *e);
void	ft_writechar(char c, t_pf_env *e);
void	ft_writemchar(char c, t_pf_env *e);
int		ft_strlenwchar(wchar_t *s);
int		ft_strlenwchars(wchar_t s);

#endif
