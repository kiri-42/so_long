# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:07:26 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/06 20:15:11 by tkirihar         ###   ########.fr        #
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
			srcs/redraw_map.c

OBJS = 		$(SRCS:.c=.o)

MLX_LIB = 	minilibx/libmlx.a

FT_DIR = 	libft-1.5.1

FT_LIB = 	libft-1.5.1/libft.a

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

OPT = 		-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJS) $(FT_LIB)
			$(CC) $^ $(MLX_LIB) $(OPT) -o $@

$(FT_LIB):
			make -C $(@D)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			make -C $(FT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(FT_DIR) fclean