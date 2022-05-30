/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:49:55 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 15:07:36 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	printstr(char *str)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	return (write(1, str, strlen));
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

int	recursive_power(int num, int power)
{
	int	ret;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power % 2 == 1)
		return (num * recursive_power(num, power - 1));
	ret = recursive_power(num, power / 2);
	return (ret * ret);
}

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
		digit_count--;
		print_num = num / recursive_power(10, digit_count);
		if (neg)
			print_num *= -1;
		print_num += '0';
		print_count += write(1, &print_num, 1);
		num %= recursive_power(10, digit_count);
	}
	return (print_count);
}

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	int	ret = 0; */
/* 	ret = printint(0); */
/* 	printf(": %d\n", ret); */
/* 	ret = printint(100); */
/* 	printf(": %d\n", ret); */
/* 	ret = printint(-100); */
/* 	printf(": %d\n", ret); */
/* 	ret = printint(2147483647); */
/* 	printf(": %d\n", ret); */
/* 	ret = printint(-2147483648); */
/* 	printf(": %d\n", ret); */
/* 	ret = printint(214748364); */
/* 	printf(": %d\n", ret); */
/* 	ret = printint(-214748364); */
/* 	printf(": %d\n", ret); */
/* } */
