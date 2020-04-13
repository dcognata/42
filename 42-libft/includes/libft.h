/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:23:36 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/10 17:36:13 by dcognata         ###   ########.fr       */
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





# define BUFF_SIZE 8

int		get_next_line(int const fd, char **line);












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

int						ft_printf(char *format, ...);
int						return_fdp(t_env *e, int nb);
void					free_fdp(char *str, long long int d);
void					ft_writechar(char c, t_env *e);
void					ft_writemchar(char c, t_env *e);
int						ft_strlenwchar(wchar_t *s);
int						ft_strlenwchars(wchar_t s);
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
