/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:42:37 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/31 01:11:43 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_digit_count(unsigned int u_num);

int	printuint(unsigned int u_num)
{
	int	digit_count;
	int	print_count;
	int	print_num;

	digit_count = get_digit_count(u_num);
	print_count = 0;
	while (digit_count > 0)
	{
		digit_count--;
		print_num = u_num / recursive_power(10, digit_count);
		print_num += '0';
		print_count += write(1, &print_num, 1);
		u_num %= recursive_power(10, digit_count);
	}
	return (print_count);
}

int	get_digit_count(unsigned int u_num)
{
	int	digit_count;

	if (u_num == 0)
		return (1);
	digit_count = 0;
	while (u_num != 0)
	{
		u_num /= 10;
		digit_count++;
	}
	return (digit_count);
}
