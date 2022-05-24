# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 15:10:14 by ktakada           #+#    #+#              #
#    Updated: 2022/05/24 23:12:59 by ktakada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_ctos.c \
	ft_itoa_base.c \
	ft_uitoa.c \
	ft_toupper_string.c \
	ft_printstr.c \
	ft_join_address.c \
# B_SRCS = 

OBJS = $(SRCS:.c=.o)

# B_OBJS = $(B_SRCS:.c=.o)

# ifeq ($(MAKECMDGOALS), bonus)
# 	OBJS += $(B_OBJS)
# endif

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

# bonus: all

.PHONY:	all clean fclean re bonus
