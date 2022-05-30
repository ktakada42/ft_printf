# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 15:10:14 by ktakada           #+#    #+#              #
#    Updated: 2022/05/31 00:24:40 by ktakada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

INCLUDESDIR := ./includes

SRCSDIR := ./src/

SRCS := ft_printf.c \
	ft_vprintf.c \
	printstr.c \
	printint.c \
	printuint.c \
	printaddress.c \
	printhex.c \
	utils.c \

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
