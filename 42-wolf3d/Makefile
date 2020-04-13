# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 13:43:04 by dcognata          #+#    #+#              #
#    Updated: 2016/03/02 15:17:41 by dcognata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

PATH_SRC = ./srcs/

INCLUDES = -I./libft/ -I./minilibx/

CFLAGS = -Wall -Wextra -pedantic -g -O3 $(INCLUDES) #-Werror 

LXLIBMLX = -L ./minilibxLinux/ -lmlx
OXLIBMLX = -L ./minilibx/ -lmlx

MLXLINUX = -L/usr/X11/lib -lXext -lX11 -lm
MLXMAC = -framework OpenGL -framework AppKit -lm

LIBFT = -L ./libft/ -lft

SRC = main.c           \
	  launch.c         \
	  load_assets.c    \
	  load_tex.c       \
	  load_weapons.c   \
	  load_level.c     \
	  hook_keyboard.c  \
	  hook_motion.c    \
	  draw.c           \
	  usage.c          \
	  parsing.c        \
	  wolf.c           \
	  editor.c         \
	  hook_menu.c      \
	  hook_game.c      \
	  hook_editor.c    \
	  draw_walls.c     \
	  exitprogm.c      \
	  anim_gun.c       \
	  anim_shootgun.c  \
	  anim_rifle.c     \
	  draw_sky.c       \
	  draw_floor.c     \
	  select_weapon.c  \
	  destroy_weaps.c  \
	  editor_mouse.c   \

SRCS = $(addprefix $(PATH_SRC), $(SRC))

SRCO = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

$(NAME): $(SRCO)
	@echo "\033[1;30mWold3d : Sources compiling...\033[0m"
	$(CC) $(FLAGS) -o $@ $(SRCO) $(LIBFT) $(OXLIBMLX) $(MLXMAC) -lm
	@echo "\033[0;36mWolf3d compile with success !\033[0m"

libft:
	make -C libft

minilibx_linux:
	@make -C minilibxLinux/

minilibx:
	@make -C minilibx/

linux: libft minilibx_linux $(SRCO)
	@echo "\033[1;30mWolf3d : Sources compiling...\033[0m"
	clang $(SRCO) $(LIBFT) $(LXLIBMLX) $(MLXLINUX) -lm -o $(NAME)
	@echo "\033[0;36mWolf3d compile with success !\033[0m"

.PHONY: clean fclean minilibx_linux libft all $(NAME)

clean:
	@make -C libft/ clean
	@/bin/rm -f $(SRCO)
	@echo "\033[0;36mObjects removed...\033[0m"

fcleanlinux: clean
	@make -C libft/ fclean
	@make -C minilibxLinux/ clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mWolf3d binary removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx/ clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;36mWolf3d binary removed...\033[0m"

re: fclean all
relinux: fcleanlinux linux
