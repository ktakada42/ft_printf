/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:42:37 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 15:51:08 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	get_digit_count(unsigned int num);

int	printuint(unsigned int num)
{
	int		digit_count;
	int		print_count;
	int		print_num;

	digit_count = get_digit_count(num);
	print_count = 0;
	while (digit_count > 0)
	{
		digit_count--;
		print_num = num / recursive_power(10, digit_count);
		print_num += '0';
		print_count += write(1, &print_num, 1);
		num %= recursive_power(10, digit_count);
	}
	return (print_count);
}

unsigned int	get_digit_count(unsigned int num)
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
