/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:56 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/31 01:11:14 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_digit(unsigned int u_num);

int	printhex(unsigned int u_num, const char *fmt)
{
	int		digit_count;
	int		print_count;
	int		print_num;
	bool	upper;

	digit_count = count_digit(u_num);
	print_count = 0;
	upper = false;
	if (*fmt == 'X')
		upper = true;
	while (digit_count > 0)
	{
		digit_count--;
		print_num = u_num / recursive_power(16, digit_count);
		if (0 <= print_num && print_num <= 9)
			print_num += '0';
		else if (upper)
			print_num += 'A' - 10;
		else
			print_num += 'a' - 10;
		print_count += write(1, &print_num, 1);
		u_num %= recursive_power(16, digit_count);
	}
	return (print_count);
}

int	count_digit(unsigned int u_num)
{
	int	digit_count;

	if (u_num == 0)
		return (1);
	digit_count = 0;
	while (u_num != 0)
	{
		u_num /= 16;
		digit_count++;
	}
	return (digit_count);
}
