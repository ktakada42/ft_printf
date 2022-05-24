/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/24 15:41:56 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		print_count;
	char	arg_c;
	char	*arg_s;
	/* int		arg_i; */

	va_start(ap, fmt);
	print_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			write(1, fmt, 1);
			print_count++;
		}
		else
		{
			fmt++;
			if (*fmt == 'c')
			{
				arg_c = (char)va_arg(ap, int);
				write(1, &arg_c, 1);
				print_count++;
			}
			else if (*fmt == 's')
			{
				arg_s = va_arg(ap, char *);
				while (*arg_s != '\0')
				{
					write(1, arg_s, 1);
					print_count++;
					arg_s++;
				}
			}
			/* else if (*fmt == 'd' || *fmt == 'u') */
			/* { */
			/* 	arg_i = va_arg(ap, int); */
			/* } */
			else if (*fmt == '%')
			{
				write(1, fmt, 1);
				print_count++;
			}
			else
			{
				return (-1);
			}
		}
		fmt++;
	}
	va_end(ap);
	return print_count;
}

#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = printf("%c, %c, %c, %%\n", 'a', 'b', 'c');
	printf("%d\n", ret);
	ret = printf("%s, world!\n", "hello");
	printf("%d\n", ret);
	printf("%s\n", ft_itoa_base(0, 10));
	printf("%s\n", ft_itoa_base(2147483647, 10));
	printf("%s\n", ft_itoa_base(-2147483648, 10));
	printf("%s\n", ft_itoa_base(0, 16));
	printf("%s\n", ft_itoa_base(2147483647, 16));
	printf("%s\n", ft_itoa_base(-2147483648, 16));
	return (0);
}
