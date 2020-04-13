# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 19:31:45 by dcognata          #+#    #+#              #
#    Updated: 2018/09/20 11:38:34 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -O2 -Iincludes

SRC_STR = \
		ft_memset.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memmove.c \
		ft_memcmp.c ft_memalloc.c ft_bzero.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		ft_strcmp.c ft_strncmp.c ft_strdup.c ft_strlen.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isalpha.c ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_atoi.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_strclr.c \
		ft_strequ.c ft_strnequ.c ft_strjoin.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strsub.c ft_strtrim.c ft_strsplit.c ft_isspace.c ft_lenint.c \
		ft_signint.c ft_count_words.c ft_want_size.c ft_abs.c ft_lstnew.c \
		ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_create_arrays.c ft_lenuint.c ft_putunbr.c ft_uitoa.c

SRC_PRINTF = \
		caste_arg.c except.c parse_convertor.c \
		parse_flags.c parse_modificator.c \
		parse_precision.c parse_width.c read_format.c \
		utils.c putwchar.c write_arg.c \
		write_char.c write_hexa.c write_hexam.c \
		write_int.c write_intu.c write_justify.c \
		write_octal.c write_pointor.c write_string.c \
		write_wchar.c write_wstr.c ft_strlenwchar.c \
		ft_writechar.c ft_printf.c

SRC_GNL = \
		get_next_line.c

SRC = \
	$(addprefix srcs/ft_str/, ${SRC_STR}) \
	$(addprefix srcs/ft_printf/, ${SRC_PRINTF}) \
	$(addprefix srcs/get_next_line/, ${SRC_GNL}) 

COBJ = $(SRC:.c=.o)

OBJ = $(COBJ:.s=.o)

R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

.SILENT:

all: $(NAME)

${NAME}: ${OBJ}
	@echo ${B}Compiling" "[${NAME}]...${X}
	ar rc ${NAME} ${OBJ}
	@echo ${G}Success"   "[${NAME}]${X}

############################## MORE ############################################

clean:
	@echo ${R}Cleaning"  "[objs]...${X}
	/bin/rm -f ${OBJ}

fclean: clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re