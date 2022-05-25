/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:34:06 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/25 23:58:41 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_flag
{
	int	flag[5];
	int	field;
	int	precision;
	int	modifier;
	int	specifier;
}	t_flag;

int		ft_printf(const char *fmt, ...);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa_base(int n, unsigned int base);
char	*ft_toupper_string(char	*str);
int		ft_printstr(char *str, int print_count);
char	*ft_join_address(char const *address);

#endif
