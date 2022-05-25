/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:17:41 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/25 21:23:46 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

char	*ft_toupper_string(char	*str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup(str);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			ret[i] = str[i] - 'a' + 'A';
		i++;
	}
	return (ret);
}

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	char	*before = "Hello"; */
/* 	char	*after = ft_toupper_string(before); */

/* 	printf("before: %s\n", before); */
/* 	printf("after: %s\n", after); */
/* } */
