# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 15:10:14 by ktakada           #+#    #+#              #
#    Updated: 2022/05/26 17:05:22 by ktakada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

INCLUDESDIR := ./includes

SRCSDIR := ./src/

SRCS := ft_printf.c \
	ft_uitoa_base.c \
	ft_toupper_string.c \
	ft_printstr.c \
	ft_join_address.c \
	ft_int64tohex.c \

SRCS := $(addprefix $(SRCSDIR), $(SRCS))

OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDESDIR) -c $< -o $@

all: $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
