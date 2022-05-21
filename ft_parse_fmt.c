/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:02:36 by ktakada           #+#    #+#             */
/*   Updated: 2022/05/22 00:03:36 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_fmt(t_flag *f)
{
	f->flag[0] = 0; // '#' x, X変換の場合かつ0でなければ0x(X)を前に付与
	f->flag[1] = 0; // '0' 左側を0で埋める、-が優先
	f->flag[2] = 0; // '-' 左揃え
	f->flag[3] = 0; // ' ' 空白(or 空文字列)が置かれる、+が優先
	f->flag[4] = 0; // '+' 正の数の前に、符号(+)を置く
	f->field = 0; // m$はm番目の引数をフィールド幅として使う、フィールド幅が負の数の場合、-フラグとみなされる
	f->precision = 0; // m$使用可、.のみの場合精度は0、精度が負の数のとき、精度は指定されなかったとみなす
	f->modifier = 0; // 長さ修飾子、ft_printfではなし?
	f->specifier = 0; // cspdiuxX%に対応
}

void	ft_parse_fmt(const char *fmt, int *print_count, va_list *ap, t_flag *f)
{
	while (!(ft_strchr("cspdiuxX", *fmt)) && *fmt != '\0')
	{
		if (*fmt == '#')
		{
			f->flag[0] = 1;
			fmt++;
		}
		if (*fmt == '0')
		{
			f->flag[1] = 1;
			fmt++;
		}
		if (*fmt == '-')
		{
			f->flag[2] = 1;
			fmt++;
		}
		if (*fmt == ' ')
		{
			f->flag[3] = 1;
			fmt++;
		}
		if (*fmt == '+')
		{
			f->flag[4] = 1;
			fmt++;
		}
	}
}
