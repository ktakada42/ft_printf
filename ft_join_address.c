/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:00:50 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/24 23:20:29 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join_address(char const *address)
{
	const char	*prefix1 = "0x1";
	const char	*prefix10 = "0x10";
	int			prefix_flag;
	size_t	address_len;
	char	*joined_str;
	
	address_len = ft_strlen(address);
	prefix_flag = 0;
	if (address_len == 8)
		prefix_flag = 1;
	joined_str = (char *)malloc((11 + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	if (prefix_flag)
		ft_strlcpy(joined_str, prefix1, 3 + 1);
	else
		ft_strlcpy(joined_str, prefix10, 4 + 1);
	ft_strlcat(joined_str, address, 11 + 1);
	return (joined_str);
}

