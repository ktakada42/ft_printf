/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:34:06 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 17:08:24 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

int		ft_printf(const char *fmt, ...);
int		ft_vprintf(const char *fmt, va_list *ap);
char	*ft_uitoa_base(int n, unsigned int base);
char	*ft_toupper_string(char	*str);
int		printstr(char *str);
int		printint(int num);
int		printuint(unsigned int num);
int		printaddress(uint64_t num);
size_t	recursive_power(unsigned int num, int power);

#endif
