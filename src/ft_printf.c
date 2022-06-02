/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/06/02 11:27:55 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	is_specifier_valid(const char *fmt);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		print_count;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	print_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			print_count += write(1, fmt, 1);
		else
		{
			if (is_specifier_valid(++fmt))
				print_count += ft_vprintf(fmt, &ap);
			else
				return (-1);
		}
		fmt++;
	}
	va_end(ap);
	return (print_count);
}

bool	is_specifier_valid(const char *fmt)
{
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p'
		|| *fmt == 'd' || *fmt == 'i' || *fmt == 'u'
		|| *fmt == 'x' || *fmt == 'X' || *fmt == '%')
		return (true);
	return (false);
}

#include <assert.h>
#include <stdio.h>

int	main(void)
{
	int		ret;
	char	*s = NULL;

	printf("---Format NULL case---\n");
	ret = ft_printf(NULL);
	printf("ret:\t%d\n", ret);

	printf("\n---NULL Pointer case---\n");
	ft_printf("arg:\t");
	ret = ft_printf("%s", s);
	printf("\n");
	assert(printf("or:\t%s\n", s) == ft_printf("ft:\t%s\n", s));
	printf("ret:\t%d\n", ret);

	printf("\n---Multibyte Character case---\n");
	s = "こんにちは";
	ft_printf("string:\t");
	ret = ft_printf("こんにちは");
	printf("\n");
	assert(printf("or:\t%s\n", s) == ft_printf("ft:\t%s\n", s));
	printf("ret\t%d\n", ret);
}
