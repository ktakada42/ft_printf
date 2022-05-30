/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:42:37 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 15:44:06 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_digit_count(int num);

static int	recursive_power(int num, int power);

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
