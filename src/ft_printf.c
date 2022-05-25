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

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			print_count;
	char		*arg;
	intptr_t	address;
	char		arg_c;
	char		*arg_to_free;

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
				arg_c = va_arg(ap, int);
				write(1, &arg_c, 1);
				print_count++;
			}
			else if (*fmt == 's')
			{
				arg = va_arg(ap, char *);
				if (arg == NULL)
					arg = (char *)"(null)";
				print_count = ft_printstr(arg, print_count);
			}
			else if (*fmt == 'p')
			{
				address = (intptr_t)va_arg(ap, void *);
				arg = ft_itoa_base(address, 16);
				arg = ft_join_address(arg);
				print_count = ft_printstr(arg, print_count);
				free(arg);
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				arg = ft_itoa(va_arg(ap, int));
				print_count = ft_printstr(arg, print_count);
				free(arg);
			}
			else if (*fmt == 'u')
			{
				arg = ft_uitoa(va_arg(ap, unsigned int));
				print_count = ft_printstr(arg, print_count);
				free(arg);
			}
			else if (*fmt == 'x')
			{
				arg = ft_itoa_base(va_arg(ap, int), 16);
				print_count = ft_printstr(arg, print_count);
				free(arg);
			}
			else if (*fmt == 'X')
			{
				arg = ft_itoa_base(va_arg(ap, int), 16);
				arg_to_free = arg;
				arg = ft_toupper_string(arg);
				print_count = ft_printstr(arg, print_count);
				free(arg);
				free(arg_to_free);
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

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	char  *a = NULL; */
/* 	int	  ret = 0; */
/* 	char  *str = "Hello"; */

/* 	ft_printf("%c, %c, %c, %%\n", 'a', 'b', 'c'); */
/* 	ft_printf("%s, world!\n", "hello"); */
/* 	ft_printf("%s\n", NULL); */
/* 	printf("%s\n", a); */
/* 	ft_printf("ft: %p\n", &ret); */
/* 	printf("or: %p\n", &ret); */
/* 	ft_printf("ft: %p\n", str); */
/* 	printf("or: %p\n", str); */
/* 	ft_printf("ft: %p\n", &str); */
/* 	printf("or: %p\n", &str); */
/* 	ft_printf("%d\n", 0); */
/* 	ft_printf("%i\n", 0); */
/* 	ft_printf("%d\n", 2147483647); */
/* 	ft_printf("%i\n", 2147483647); */
/* 	ft_printf("%d\n", -2147483648); */
/* 	ft_printf("%i\n", -2147483648); */
/* 	ft_printf("%u\n", 0); */
/* 	ft_printf("4294967295: %u\n", -1); */
/* 	ft_printf("%u\n", 2147483647); */
/* 	ft_printf("2147483648: %u\n", -2147483648); */
/* 	ft_printf("%u\n", 4294967295); */
/* 	ft_printf("%x\n", 0); */
/* 	ft_printf("%X\n", 0); */
/* 	ft_printf("%x\n", 2147483647); */
/* 	ft_printf("%X\n", 2147483647); */
/* 	ft_printf("%x\n", -2147483648); */
/* 	ft_printf("%X\n", -2147483648); */
/* 	system("leaks -q a.out"); */
/* 	return (0); */
/* } */
