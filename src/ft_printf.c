/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/27 18:06:16 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>

static int	print_spec_cspercent(va_list *ap, int *put_count, const char *fmt);

static int	print_spec_pdiu(va_list *ap, int *put_count, const char *fmt);

static int	print_spec_xX(va_list *ap, int *put_count, const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			put_count;

	va_start(ap, fmt);
	put_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			put_count += write(1, fmt, 1);
		else
		{
			fmt++;
			if (*fmt == 'c' || *fmt == 's' || *fmt == '%')
				put_count = print_spec_cspercent(&ap, &put_count, fmt);
			else if (*fmt == 'p' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u')
				put_count = print_spec_pdiu(&ap, &put_count, fmt);
			else if (*fmt == 'x' || *fmt == 'X')
				put_count = print_spec_xX(&ap, &put_count, fmt);
			else
				return (-1);
		}
		fmt++;
	}
	va_end(ap);
	return (put_count);
}

int	print_spec_cspercent(va_list *ap, int *put_count, const char *fmt)
{
	char		*arg;
	char		arg_c;

	if (*fmt == 'c')
	{
		arg_c = va_arg(*ap, int);
		*put_count += write(1, &arg_c, 1);
	}
	else if (*fmt == 's')
	{
		arg = va_arg(*ap, char *);
		if (arg == NULL)
			arg = (char *)"(null)";
		*put_count = ft_printstr(arg, *put_count);
	}
	else if (*fmt == '%')
		*put_count += write(1, fmt, 1);
	return (*put_count);
}

int	print_spec_pdiu(va_list *ap, int *put_count, const char *fmt)
{
	int64_t	address;
	char	*arg;

	address = 0;
	arg = NULL;
	if (*fmt == 'p')
	{
		address = (int64_t)va_arg(*ap, void *);
		arg = ft_int64tohex(address);
		*put_count = ft_printstr("0x", *put_count);
		*put_count = ft_printstr(arg, *put_count);
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		arg = ft_itoa(va_arg(*ap, int));
		*put_count = ft_printstr(arg, *put_count);
	}
	else if (*fmt == 'u')
	{
		arg = ft_uitoa_base(va_arg(*ap, unsigned int), 10);
		*put_count = ft_printstr(arg, *put_count);
	}
	free (arg);
	return (*put_count);
}

int	print_spec_xX(va_list *ap, int *put_count, const char *fmt)
{
	char	*arg;
	char	*tmp_to_free;

	arg = NULL;
	tmp_to_free = NULL;
	if (*fmt == 'x')
	{
		arg = ft_uitoa_base(va_arg(*ap, int), 16);
		*put_count = ft_printstr(arg, *put_count);
	}
	else if (*fmt == 'X')
	{
		arg = ft_uitoa_base(va_arg(*ap, int), 16);
		tmp_to_free = arg;
		arg = ft_toupper_string(arg);
		*put_count = ft_printstr(arg, *put_count);
	}
	free (arg);
	free (tmp_to_free);
	return (*put_count);
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
