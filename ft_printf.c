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
#include "libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		print_count;
	char	arg_c;
	char	*arg_s;

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
			else if (*fmt == 'd' || *fmt == 'i')
			{
				arg_s = ft_itoa_base(va_arg(ap, int), 10);
				while (*arg_s != '\0')
				{
					write(1, arg_s, 1);
					print_count++;
					arg_s++;
				}
			}
			/* else if (*fmt == 'u') */
			/* { */

			/* } */
			else if (*fmt == 'x')
			{
				arg_s = ft_itoa_base(va_arg(ap, int), 16);
				while (*arg_s != '\0')
				{
					write(1, arg_s, 1);
					print_count++;
					arg_s++;
				}
			}
			else if (*fmt == 'X')
			{
				arg_s = ft_itoa_base(va_arg(ap, int), 16);
				arg_s = ft_toupper_string(arg_s);
				while (*arg_s != '\0')
				{
					write(1, arg_s, 1);
					print_count++;
					arg_s++;
				}
			}
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
	ft_printf("%d\n", 0);
	ft_printf("%i\n", 0);
	ft_printf("%d\n", 2147483647);
	ft_printf("%i\n", 2147483647);
	ft_printf("%d\n", -2147483648);
	ft_printf("%i\n", -2147483648);
	ft_printf("%x\n", 0);
	ft_printf("%X\n", 0);
	ft_printf("%x\n", 2147483647);
	ft_printf("%X\n", 2147483647);
	ft_printf("%x\n", -2147483648);
	ft_printf("%X\n", -2147483648);
	return (0);
}
