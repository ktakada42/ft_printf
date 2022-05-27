/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/27 13:41:25 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			print_count;
	char		*arg;
	int64_t		address;
	char		arg_c;
	char		*arg_to_free;

	va_start(ap, fmt);
	print_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			print_count += write(1, fmt, 1);
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
				address = (int64_t)va_arg(ap, void *);
				arg = ft_int64tohex(address);
				print_count = ft_printstr("0x", print_count);
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
				arg = ft_uitoa_base(va_arg(ap, unsigned int), 10);
				print_count = ft_printstr(arg, print_count);
				free(arg);
			}
			else if (*fmt == 'x')
			{
				arg = ft_uitoa_base(va_arg(ap, int), 16);
				print_count = ft_printstr(arg, print_count);
				free(arg);
			}
			else if (*fmt == 'X')
			{
				arg = ft_uitoa_base(va_arg(ap, int), 16);
				arg_to_free = arg;
				arg = ft_toupper_string(arg);
				print_count = ft_printstr(arg, print_count);
				free(arg);
				free(arg_to_free);
			}
			else if (*fmt == '%')
				print_count += write(1, fmt, 1);
			else
				return (-1);
		}
		fmt++;
	}
	va_end(ap);
	return (print_count);
}

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	int	*p; */
/* 	int	*q; */
/* 	p = (int*)-1; */

/* 	printf("or: %p \n", p); */
/* 	ft_printf("ft: %p \n", p); */
/* 	p = (int*)1; */
/* 	printf("or: %p \n", p); */
/* 	ft_printf("ft: %p \n", p); */
/* 	p = (int*)15; */
/* 	printf("or: %p \n", p); */
/* 	ft_printf("ft: %p \n", p); */
/* 	p = (int*)16; */
/* 	printf("or: %p \n", p); */
/* 	ft_printf("ft: %p \n", p); */
/* 	p = (int*)17; */
/* 	printf("or: %p \n", p); */
/* 	ft_printf("ft: %p \n", p); */
/* 	p = (int*)LONG_MIN; */
/* 	q = (int*)LONG_MAX; */
/* 	printf("or: %p %p \n", p, q); */
/* 	ft_printf("ft: %p %p \n", p, q); */
/* 	p = (int*)INT_MIN; */
/* 	q = (int*)INT_MAX; */
/* 	printf("or: %p %p \n", p, q); */
/* 	ft_printf("ft: %p %p \n", p, q); */
/* 	p = (int*)ULONG_MAX; */
/* 	q = (int*)-ULONG_MAX; */
/* 	printf("or: %p %p \n", p, q); */
/* 	ft_printf("ft: %p %p \n", p, q); */
/* 	p = (int*)0; */
/* 	q = (int*)0; */
/* 	printf("or: %p %p \n", p, q); */
/* 	ft_printf("ft: %p %p \n", p, q); */
/* } */

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
