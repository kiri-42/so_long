# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:07:26 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/08 00:38:35 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

SRCS = 		srcs/main.c \
			srcs/check_map_data.c \
			srcs/finish_error.c \
			srcs/check_arg.c \
			srcs/read_map_file.c \
			srcs/init_mlx.c \
			srcs/init_map.c \
			srcs/put_object.c \
			srcs/free.c \
			srcs/key_hook.c \
			srcs/redraw_map.c \
			srcs/close_game.c

OBJS = 		$(SRCS:.c=.o)

MLX_DIR = 	minilibx

MLX_LIB = 	minilibx/libmlx.a

FT_DIR = 	libft-1.5.1

FT_LIB = 	libft-1.5.1/libft.a

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

OPT = 		-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX_LIB) $(FT_LIB)
			$(CC) $^ $(OPT) -o $@

$(MLX_LIB):
			make -C $(@D)

$(FT_LIB):
			make -C $(@D)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			make -C $(FT_DIR) clean
			make -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(FT_DIR) fclean