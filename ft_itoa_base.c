/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:46:32 by ktaka             #+#    #+#             */
/*   Updated: 2022/05/25 18:39:10 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digit_base(unsigned int num, unsigned int base);

char	*ft_itoa_base(int n, unsigned int base)
{
	const char		digs[16] = {'0', '1', '2', '3', '4', '5', \
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	size_t			digit_count;
	char			*ret;
	unsigned int	num;

	num = n;
	digit_count = count_digit_base(num, base);
	ret = (char *)malloc((digit_count + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[digit_count--] = '\0';
	if (num == 0)
		ret[0] = '0';
	while (digit_count >= 0 && num != 0)
	{
		ret[digit_count--] = digs[num % base];
		num /= base;
	}
	return (ret);
}

size_t	count_digit_base(unsigned int num, unsigned int base)
{
	size_t		count;

	count = 1;
	while (num >= base)
	{
		num /= base;
		count++;
	}
	return (count);
}
