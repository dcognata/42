# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#*   Updated: 2016/01/27 16:53:10 by dcognata         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

LXLIBMLX = -I ./minilibxLinux/ ./minilibxLinux/libmlx.a
OXLIBMLX = -I ./minilibx/ ./minilibx/libmlx.a

LIBFT = -I ./libft/ ./libft/libft.a

MLXLINUX = -L /usr/X11/lib -lXext -lX11
MLXMAC = -framework OpenGL -framework AppKit

INCLUDES = -I ./fdf.h -I ./libft/libft.h -I ./minilibx/mlx.h

SRCS = main.c      \
	   hook.c      \
	   parsing.c   \
	   tools.c     \
	   draw.c      \
	   math.c      \
	   bresenham.c \
	   setpoints.c \
	   hookfunctions.c

SRCO = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@echo "\033[1;30mFDF : Sources compiling...\033[0m"
	@make -C libft/
	@make -C minilibx/
	@$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(OXLIBMLX) $(MLXMAC)
	@echo "\033[0;36mFDF compile with success !\033[0m"

linux:
	@echo "\033[1;30mFDF : Sources compiling...\033[0m"
	@make -C libft/
	@make -C minilibxLinux/
	@clang $(FLAGS) $(INCLUDES) -c $(SRCS)
	@clang $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(LXLIBMLX) $(MLXLINUX)
	@echo "\033[0;36mFDF compile with success !\033[0m"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(SRCO)
	@echo "\033[0;36mObjects removed...\033[0m"

fcleanlinux: clean
	@make -C libft/ fclean
	@make -C minilibxLinux/ clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mFDF binary removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx/ clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mFDF binary removed...\033[0m"

re: fclean all
relinux: fcleanlinux linux
