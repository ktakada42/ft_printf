/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/31 01:10:10 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_cspercent(const char *fmt, va_list *ap);

static int	print_pdiuxupperx(const char *fmt, va_list *ap);

int	ft_vprintf(const char *fmt, va_list *ap)
{
	if (*fmt == 'c' || *fmt == 's' || *fmt == '%')
		return (print_cspercent(fmt, ap));
	else
		return (print_pdiuxupperx(fmt, ap));
}

int	print_cspercent(const char *fmt, va_list *ap)
{
	int		print_count;
	char	*arg;
	char	arg_c;

	if (*fmt == 'c')
	{
		arg_c = (char)va_arg(*ap, int);
		print_count = write(1, &arg_c, 1);
	}
	else if (*fmt == 's')
	{
		arg = va_arg(*ap, char *);
		if (arg == NULL)
			arg = (char *)"(null)";
		print_count = printstr(arg);
	}
	else
		print_count = write(1, fmt, 1);
	return (print_count);
}

int	print_pdiuxupperx(const char *fmt, va_list *ap)
{
	int	print_count;

	if (*fmt == 'p')
		print_count = printaddress((int64_t)va_arg(*ap, void *));
	else if (*fmt == 'd' || *fmt == 'i')
		print_count = printint(va_arg(*ap, int));
	else if (*fmt == 'u')
		print_count = printuint(va_arg(*ap, unsigned int));
	else
		print_count = printhex(va_arg(*ap, int), fmt);
	return (print_count);
}
