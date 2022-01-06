# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:07:26 by tkirihar          #+#    #+#              #
#    Updated: 2022/01/06 14:57:25 by tkirihar         ###   ########.fr        #
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
			srcs/put_object.c

OBJS = 		$(SRCS:.c=.o)

# INCDIR =	-Iinclude

MLX_LIB = 	minilibx/libmlx.a

FT_LIB = 	libft-1.5.1/libft.a

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

OPT = 		-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $^ $(MLX_LIB) $(FT_LIB) $(OPT) -o $@

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)