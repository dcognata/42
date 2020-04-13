# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#    Updated: 2018/09/22 21:00:23 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC		=	main.c \
			parse.c \
			list.c \
			tools.c \
			sort.c \
			ft_ls.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -O3 -march=native -funroll-loops # -Werror

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft/includes
LIBLINK	= -L./libft -lft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

all: obj libft $(NAME)

obj:
	@echo ${B}Create Directory" "[${OBJDIR}]...${X}
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo ${B}Make" "[${LIBFT}]...${X}
	@make -C ./libft

$(NAME): $(OBJ)
	@echo ${B}Compiling" "[${NAME}]...${X}
	@$(CC) -o $(NAME) $(OBJ) $(LIBLINK)
	@echo ${G}Success"   "[${NAME}]${X}

clean:
	@echo ${R}Cleaning"  "[objs]...${X}
	@rm -rf $(OBJDIR)
	@make -C ./libft clean

fclean: clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all