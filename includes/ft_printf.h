/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:34:06 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/30 13:04:33 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

int		ft_printf(const char *fmt, ...);
int		put_specifier(const char *fmt, va_list *ap);
char	*ft_uitoa_base(int n, unsigned int base);
char	*ft_int64tohex(int64_t n);
char	*ft_toupper_string(char	*str);
int		putstr(char *str);

#endif
