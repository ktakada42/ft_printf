/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:42:37 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 17:03:46 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/* #include <stdio.h> */

static int	get_digit_count(int num);

int	printint(int num)
{
	int		digit_count;
	bool	neg;
	int		print_count;
	int		print_num;

	digit_count = get_digit_count(num);
	neg = false;
	print_count = 0;
	if (num < 0)
		neg = true;
	if (neg)
		print_count += write (1, "-", 1);
	while (digit_count > 0)
	{
		/* printf("\ndigit_count: %d\n", digit_count); */
		digit_count--;
		/* printf("\npower: %d\n", (int)recursive_power(10, digit_count)); */
		print_num = num / (int)recursive_power(10, digit_count);
		if (neg)
			print_num *= -1;
		/* printf("\nprint_num: %d\n", print_num); */
		print_num += '0';
		print_count += write(1, &print_num, 1);
		num %= (int)recursive_power(10, digit_count);
		/* printf("\n%d\n", num); */
	}
	return (print_count);
}

int	get_digit_count(int num)
{
	int		digit_count;

	if (num == 0)
		return (1);
	digit_count = 0;
	while (num != 0)
	{
		num /= 10;
		digit_count++;
	}
	return (digit_count);
}

/* int	main(void) */
/* { */
/* 	printint(-10); */
/* } */
