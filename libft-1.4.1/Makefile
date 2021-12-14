# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:29:24 by tkirihar          #+#    #+#              #
#    Updated: 2021/12/13 13:29:25 by tkirihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCS =		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_isspace.c \
			ft_long_atoi.c \
			check_int.c

SRCS_B =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS =		$(SRCS:.c=.o)

OBJS_B =	$(SRCS_B:.c=.o)

ifdef WITH_BONUS
OBJS +=		$(OBJS_B)
endif

CC =		gcc
RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I ./includes/ -c $< -o $(<:%.c=%.o)

fclean:		clean
			$(RM) $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_B)

re:			fclean all

bonus:
			make WITH_BONUS=1

.PHONY:		all clean fclean re bonus
