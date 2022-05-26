/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:46:32 by ktaka             #+#    #+#             */
/*   Updated: 2022/05/26 17:15:58 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	count_digit_base(unsigned int u_num, unsigned int base);

char	*ft_uitoa_base(int n, unsigned int base)
{
	const char		digs[16] = {'0', '1', '2', '3', '4', '5', \
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	size_t			digit_count;
	char			*ret;
	unsigned int	u_num;

	u_num = (unsigned int)n;
	digit_count = count_digit_base(u_num, base);
	ret = (char *)malloc((digit_count + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[digit_count--] = '\0';
	if (u_num == 0)
		ret[0] = '0';
	while (u_num != 0)
	{
		ret[digit_count--] = digs[u_num % base];
		u_num /= base;
	}
	return (ret);
}

size_t	count_digit_base(unsigned int u_num, unsigned int base)
{
	size_t		count;

	count = 1;
	while (u_num >= base)
	{
		u_num /= base;
		count++;
	}
	return (count);
}
