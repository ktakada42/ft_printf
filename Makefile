# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 15:10:14 by ktakada           #+#    #+#              #
#    Updated: 2022/05/21 15:10:30 by ktakada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = 

B_SRCS = 

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

ifeq ($(MAKECMDGOALS), bonus)
	OBJS += $(B_OBJS)
endif

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY:	all clean fclean re bonus
