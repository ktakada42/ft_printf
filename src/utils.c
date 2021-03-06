/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:49:55 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/31 01:02:11 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	recursive_power(size_t num, int power)
{
	size_t	ret;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power % 2 == 1)
		return (num * recursive_power(num, power - 1));
	ret = recursive_power(num, power / 2);
	return (ret * ret);
}
