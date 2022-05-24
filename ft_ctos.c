/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:09:10 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/24 22:13:54 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctos(char c)
{
	char	*chr;

	chr = (char *)malloc(sizeof(char) * 2);
	if (chr == NULL)
		return (NULL);
	chr[0] = c;
	chr[1] = '\0';
	return (chr);
}
