/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addressto64bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:52:12 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/26 17:04:41 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	count_digit(uint64_t u_num);

char	*ft_int64tohex(int64_t n)
{
	const char		digs[16] = {'0', '1', '2', '3', '4', '5', \
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	uint64_t		u_num;
	size_t			digit_count;
	char			*ret;

	u_num = (uint64_t)n;
	digit_count = count_digit(u_num);
	ret = (char *)malloc((digit_count + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[digit_count--] = '\0';
	if (u_num == 0)
		ret[digit_count] = '0';
	while (u_num != 0)
	{
		ret[digit_count--] = digs[u_num % 16];
		u_num /= 16;
	}
	return (ret);
}

size_t	count_digit(uint64_t u_num)
{
	size_t		count;

	count = 1;
	while (u_num >= 16)
	{
		u_num /= 16;
		count++;
	}
	return (count);
}
