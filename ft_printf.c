/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/22 00:07:26 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		print_count;
	t_flag	*f;

	va_start(ap, fmt);
	print_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			write(1, fmt, 1);
			print_count++;
			fmt++;
		}
		else
			ft_parse_fmt(fmt, &print_count, ap, &f);
	}
	va_end(ap);
	return print_count;
}

#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = printf("%d\n%s\n", 1, "hello");
	printf("%d\n", ret);
	return (0);
}
