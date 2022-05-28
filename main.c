/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:01:27 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/29 00:59:14 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;
	int		ret;

	s = (char *)malloc(sizeof(char) * INT_MAX + 1);
	s[INT_MAX] = '\0';
	memset(s, 'a', INT_MAX);
	s[INT_MAX - 3] = '\0';
	ret = printf("%s%s", "ab", s);
	printf("\n\n%d\n", ret);
}

/* INT_MAX - 3, "abc" -> print INT_MAX - 3, ret -1 */
/* INT_MAX - 3, "ab" -> print INT_MAX - 3 & ab, ret INT_MAX - 1 */
/* abcINT_MAX - 3 -> print , ret -1 */
/* INT_MAX - 3abc -> print INT_MAX - 3, ret -1 */
/* "abc", INT_MAX - 3 -> print "abc", ret -1 */
/* "ab", INT_MAX - 3 -> print "ab" & INT_MAX - 3, ret INT_MAX - 1 */
