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
	char	*arg;

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
				arg = va_arg(ap, char *);
				write(1, arg, 1);
				print_count++;
			}
			else if (*fmt == 's')
			{
				arg = va_arg(ap, char *);
				while (*arg != '\0')
				{
					write(1, arg, 1);
					print_count++;
					arg++;
				}
			}
			else if (*fmt == 'p')
			{
				arg = va_arg(ap, char *);
				while (*arg != '\0')
				{
					write(1, arg, 1);
					print_count++;
					arg++;
				}
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				arg = ft_itoa_base(va_arg(ap, int), 10);
				while (*arg != '\0')
				{
					write(1, arg, 1);
					print_count++;
					arg++;
				}
			}
			else if (*fmt == 'u')
			{
				arg = ft_uitoa(va_arg(ap, unsigned int));
				while (*arg != '\0')
				{
					write(1, arg, 1);
					print_count++;
					arg++;
				}
			}
			else if (*fmt == 'x')
			{
				arg = ft_itoa_base(va_arg(ap, int), 16);
				while (*arg != '\0')
				{
					write(1, arg, 1);
					print_count++;
					arg++;
				}
			}
			else if (*fmt == 'X')
			{
				arg = ft_itoa_base(va_arg(ap, int), 16);
				arg = ft_toupper_string(arg);
				while (*arg != '\0')
				{
					write(1, arg, 1);
					print_count++;
					arg++;
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
	printf("%p\n", &ret);
	ft_printf("%p\n", &ret);
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
	ft_printf("%u\n", 0);
	ft_printf("4294967295: %u\n", -1);
	ft_printf("%u\n", 2147483647);
	ft_printf("2147483648: %u\n", -2147483648);
	ft_printf("%u\n", 4294967295);
	return (0);
}
