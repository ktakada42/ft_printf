/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:54:16 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/25 21:23:38 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_printstr(char *str, int print_count)
{
	size_t	print_len;

	print_len = ft_strlen(str);
	if (print_count + print_len > INT_MAX)
		return (-1);
	write(1, str, print_len);
	return (print_count + print_len);
}
