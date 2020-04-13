# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/06 13:03:14 by dcognata          #+#    #+#              #
#    Updated: 2016/03/30 17:19:25 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -pedantic -O3

SRC_PATH = ./srcs/

SRC_NAME =  ft_bzero.c    \
			ft_itoa.c     \
			ft_isdigit.c  \
			ft_lenint.c   \
			ft_lenuint.c  \
			ft_putchar.c  \
			ft_putnbr.c   \
			ft_putstr.c   \
			ft_strnew.c   \
			ft_atoi.c     \
			ft_strlen.c   \
			ft_putunbr.c  \
			ft_strjoin.c  \
			ft_putwchar.c \
			ft_strlenwchar.c \
			ft_printf.c         \
			parse_flags.c       \
			parse_width.c       \
			read_format.c       \
			parse_precision.c   \
			parse_modificator.c \
			parse_convertor.c   \
			write_arg.c         \
			write_int.c         \
			write_intu.c        \
			write_char.c        \
			write_string.c      \
			write_pointor.c     \
			write_hexa.c        \
			write_hexam.c       \
			write_octal.c       \
			write_justify.c     \
			write_wchar.c       \
			write_wstr.c        \
			caste_arg.c         \
			utils.c             \
			except.c

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CPPFLAGS = -I./incs/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "ft_printf : Sources compiling..."
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "ft_printf compile with success !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Objects removed..."

fclean: clean
	rm -fv $(NAME)
	rm -fv a.out
	@echo "ft_printf binary removed..."

re: fclean all

.PHONY: all, clean, fclean, re
