# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 19:31:45 by dcognata          #+#    #+#              #
#*   Updated: 2016/01/20 14:10:47 by dcognata         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_memset.c      \
	   ft_memcpy.c      \
	   ft_memccpy.c     \
	   ft_memchr.c      \
	   ft_memmove.c     \
	   ft_memcmp.c      \
	   ft_memalloc.c    \
	   ft_bzero.c       \
	   ft_putchar.c     \
	   ft_putstr.c      \
	   ft_putendl.c     \
	   ft_putchar_fd.c  \
	   ft_putstr_fd.c   \
	   ft_putendl_fd.c  \
	   ft_strcpy.c      \
	   ft_strncpy.c     \
	   ft_strcat.c      \
	   ft_strncat.c     \
	   ft_strlcat.c     \
	   ft_strcmp.c      \
	   ft_strncmp.c     \
	   ft_strdup.c      \
	   ft_strlen.c      \
	   ft_strchr.c      \
	   ft_strrchr.c     \
	   ft_strstr.c      \
	   ft_strnstr.c     \
	   ft_isdigit.c     \
	   ft_isalnum.c     \
	   ft_isascii.c     \
	   ft_isalpha.c     \
	   ft_isprint.c     \
	   ft_tolower.c     \
	   ft_toupper.c     \
	   ft_atoi.c        \
	   ft_itoa.c        \
	   ft_putnbr.c      \
	   ft_putnbr_fd.c   \
	   ft_strclr.c      \
	   ft_strequ.c      \
	   ft_strnequ.c     \
	   ft_strjoin.c     \
	   ft_memdel.c      \
	   ft_strnew.c      \
	   ft_strdel.c      \
	   ft_striter.c     \
	   ft_striteri.c    \
	   ft_strmap.c      \
	   ft_strmapi.c     \
	   ft_strsub.c      \
	   ft_strtrim.c     \
	   ft_strsplit.c    \
	   ft_isspace.c     \
	   ft_lenint.c      \
	   ft_signint.c     \
	   ft_count_words.c \
	   ft_want_size.c   \
	   ft_abs.c         \
	   ft_lstnew.c      \
	   ft_lstdelone.c   \
	   ft_lstdel.c      \
	   ft_lstadd.c      \
	   ft_lstiter.c     \
	   ft_lstmap.c      \

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@echo "\033[0;36m ___       ___  ________  ________ _________       \033[0m"
	@echo "\033[0;36m|\  \     |\  \|\   __  \|\  _____\\___   ___\     \033[0m"
	@echo "\033[0;36m\ \  \    \ \  \ \  \|\ /\ \  \__/\|___ \  \_|     \033[0m"
	@echo "\033[0;36m \ \  \    \ \  \ \   __  \ \   __\    \ \  \      \033[0m"
	@echo "\033[0;36m  \ \  \____\ \  \ \  \|\  \ \  \_|     \ \  \     \033[0m"
	@echo "\033[0;36m   \ \_______\ \__\ \_______\ \__\       \ \__\    \033[0m"
	@echo "\033[0;36m    \|_______|\|__|\|_______|\|__|        \|__|    \033[0m"
	@echo "\033[0;36m                                                   \033[0m"
	@echo "\033[1;30mCompilation des sources...\033[0m"
	@gcc $(FLAGS) -c $(SRCS)
	@echo  "\033[1;30mCreation de la librairie...\033[0m"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo  "\033[0;36mLibrairie cree avec succes\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[0;36mFichiers objets supprimes\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;36mLibrairie supprimee\033[0m"

re: fclean all
