/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:35:20 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/21 15:47:09 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *fmt, ...)
{
	if (fmt == NULL)
	{
		return -1;
	}
	return 0;
}

#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = ft_printf(NULL);
	printf("%d\n", ret);
	return (0);
}
