/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:46:32 by ktaka             #+#    #+#             */
/*   Updated: 2022/05/24 21:49:50 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digit(unsigned int n);

char	*ft_uitoa(unsigned int n)
{
	size_t			digit_count;
	char			*ret;

	digit_count = count_digit(n);
	ret = (char *)malloc((digit_count + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[digit_count--] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (digit_count >= 0 && n != 0)
	{
		ret[digit_count--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

size_t	count_digit(unsigned int n)
{
	size_t		count;

	count = 1;
	while (n >= 10)
	{
		n/= 10;
		count++;
	}
	return (count);
}

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	printf("%s\n", ft_uitoa(0)); */
/* 	printf("%s\n", ft_uitoa(1)); */
/* 	printf("4294967295: %s\n", ft_uitoa(-1)); */
/* 	printf("%s\n", ft_uitoa(2147483647)); */
/* 	printf("2147483648: %s\n", ft_uitoa(-2147483648)); */
/* 	printf("%s\n", ft_uitoa(4294967295)); */
/* } */
