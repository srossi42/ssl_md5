/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:04:53 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:22:58 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_def_char_lnmax(t_arg *arg)
{
	NB_LN = 1;
	LN_MAX = ft_max_int(3, WIDTH, PRECISION, 1);
}

static	void	ft_minus_on(char c, t_arg *arg)
{
	STR_TMP[0] = c;
	if (!(FLAGS & F_ZERO))
		ft_fill_nchar(&STR_TMP[1], ' ', LN_MAX - NB_LN);
	else
		ft_fill_nchar(&STR_TMP[1], '0', LN_MAX - NB_LN);
}

static	void	ft_minus_off(char c, t_arg *arg)
{
	if (!(FLAGS & F_ZERO))
		ft_fill_nchar(STR_TMP, ' ', LN_MAX - NB_LN);
	else
		ft_fill_nchar(STR_TMP, '0', LN_MAX - NB_LN);
	STR_TMP[LN_MAX - 1] = c;
}

int				ft_conv_c(char *str, t_arg *arg, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	COUNTER = 0;
	ft_def_char_lnmax(arg);
	if (!c)
		LN_MAX = ft_max_int(3, 1, PRECISION - NB_LN, WIDTH);
	if (F_PREC && WIDTH < PRECISION)
		LN_MAX = 1;
	STR_TMP = ft_strnew(LN_MAX);
	if (FLAGS & F_MINUS)
		ft_minus_on(c, arg);
	else
		ft_minus_off(c, arg);
	write(1, str, BUFF_I);
	ft_bzero(str, BUFF_I);
	BUFF_I = 0;
	write(1, STR_TMP, LN_MAX);
	return (LN_MAX);
}
