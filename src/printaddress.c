/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printaddress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:56 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 17:07:50 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_digit(uint64_t u_64num);

int	printaddress(uint64_t num)
{
	uint64_t	u_64num;
	int			digit_count;
	int			print_count;
	int			print_num;

	u_64num = num;
	digit_count = count_digit(u_64num);
	print_count = printstr("0x");
	while (digit_count > 0)
	{
		digit_count--;
		print_num = u_64num / recursive_power(16, digit_count);
		if (0 <= print_num && print_num <= 9)
			print_num += '0';
		else
			print_num += 87;
		print_count += write(1, &print_num, 1);
		u_64num %= recursive_power(16, digit_count);
	}
	return (print_count);
}

int	count_digit(uint64_t u_64num)
{
	int	digit_count;

	if (u_64num == 0)
		return (1);
	digit_count = 0;
	while (u_64num != 0)
	{
		u_64num /= 16;
		digit_count++;
	}
	return (digit_count);
}

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	int	ret; */

/* 	ret = printaddress(0); */
/* 	printf(": %d\n", ret); */
/* 	ret = printaddress(100); */
/* 	printf(": %d\n", ret); */
/* 	ret = printaddress(255); */
/* 	printf(": %d\n", ret); */
/* 	ret = printaddress(256); */
/* 	printf(": %d\n", ret); */
/* 	ret = printaddress(-1); */
/* 	printf(": %d\n", ret); */
/* } */
