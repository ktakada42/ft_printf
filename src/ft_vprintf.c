/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 15:36:19 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_vprintf(const char *fmt, va_list *ap);

static int	print_cspercent(const char *fmt, va_list *ap);

static int	print_pdiu(const char *fmt, va_list *ap);

static int	print_xupperx(const char *fmt, va_list *ap);

int	ft_vprintf(const char *fmt, va_list *ap)
{
	if (*fmt == 'c' || *fmt == 's' || *fmt == '%')
		return (print_cspercent(fmt, ap));
	else if (*fmt == 'p' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u')
		return (print_pdiu(fmt, ap));
	else
		return (print_xupperx(fmt, ap));
}

int	print_cspercent(const char *fmt, va_list *ap)
{
	int			print_count;
	char		*arg;
	char		arg_c;

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

int	print_pdiu(const char *fmt, va_list *ap)
{
	int		print_count;
	int64_t	address;
	char	*arg;
	int		arg_i;

	arg = NULL;
	if (*fmt == 'p')
	{
		address = (int64_t)va_arg(*ap, void *);
		arg = ft_int64tohex(address);
		print_count = printstr("0x");
		print_count += printstr(arg);
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		arg_i = va_arg(*ap, int);
		print_count = printint(arg_i);
	}
	else
	{
		arg = ft_uitoa_base(va_arg(*ap, unsigned int), 10);
		print_count = printstr(arg);
	}
	free (arg);
	return (print_count);
}

int	print_xupperx(const char *fmt, va_list *ap)
{
	int		print_count;
	char	*arg;
	char	*tmp_to_free;

	tmp_to_free = NULL;
	if (*fmt == 'x')
	{
		arg = ft_uitoa_base(va_arg(*ap, int), 16);
		print_count = printstr(arg);
	}
	else
	{
		arg = ft_uitoa_base(va_arg(*ap, int), 16);
		tmp_to_free = arg;
		arg = ft_toupper_string(arg);
		print_count = printstr(arg);
	}
	free (arg);
	free (tmp_to_free);
	return (print_count);
}
