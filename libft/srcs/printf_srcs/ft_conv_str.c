/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:50:44 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:10 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_def_str_max(t_arg *arg, char *str)
{
	int length;

	LN_MAX = WIDTH;
	((PRECISION == 0 && F_PREC == 1) ? PRECISION = -1 : 0);
	length = ft_strlen(str);
	if (PRECISION == 0 && WIDTH == 0)
		LN_MAX = length;
	else if (length > 0)
	{
		if (PRECISION > WIDTH && PRECISION >= length)
			LN_MAX = ft_max_int(2, WIDTH, length);
		else if (WIDTH < length && PRECISION == 0)
			LN_MAX = length;
		else if (PRECISION > WIDTH && PRECISION < length)
			LN_MAX = PRECISION;
	}
}

void			ft_str_null(t_arg *arg)
{
	NB_LN = 6;
	((F_PREC && PRECISION == 0) ? NB_LN = 0 : 0);
	LN_MAX = ft_max_int(3, NB_LN, PRECISION, WIDTH);
	((PRECISION > 0 && PRECISION < LN_MAX) ? LN_MAX = PRECISION : 0);
	STR_TMP = ft_strnew(LN_MAX);
	if (FLAGS & F_MINUS)
	{
		((F_PREC && PRECISION == 0) ? NB_LN = 0 : 0);
		if (PRECISION < NB_LN && F_PREC)
			ft_strncat(STR_TMP, "(null)", PRECISION);
		else
			ft_strncat(STR_TMP, "(null)", NB_LN);
		ft_fill_nchar(&STR_TMP[NB_LN], ' ', LN_MAX - NB_LN);
	}
	else
	{
		if (!(FLAGS & F_ZERO))
			ft_fill_nchar(STR_TMP, ' ', LN_MAX - NB_LN);
		else
			ft_fill_nchar(STR_TMP, '0', LN_MAX - NB_LN);
		ft_strncat(STR_TMP, "(null)", LN_MAX - ((PRECISION == -1) ? WIDTH : 0));
	}
	COUNTER += LN_MAX;
}

static	void	ft_minus_on(t_arg *arg, char *tmp)
{
	NB_LN = ft_strlen(tmp);
	if (PRECISION < NB_LN && F_PREC == 1 && PRECISION >= 0)
		NB_LN = PRECISION;
	ft_def_str_max(arg, tmp);
	STR_TMP = ft_strnew(LN_MAX);
	ft_strncat(STR_TMP, tmp, NB_LN);
	if (!(FLAGS & F_ZERO))
		ft_fill_nchar(&STR_TMP[NB_LN], ' ', LN_MAX - NB_LN);
	else
		ft_fill_nchar(&STR_TMP[NB_LN], '0', LN_MAX - NB_LN);
}

static	void	ft_minus_off(t_arg *arg, char *tmp)
{
	NB_LN = ft_strlen(tmp);
	if (PRECISION < NB_LN && F_PREC == 1 && PRECISION >= 0)
		NB_LN = PRECISION;
	ft_def_str_max(arg, tmp);
	STR_TMP = ft_strnew(LN_MAX);
	if (!(FLAGS & F_ZERO))
		ft_fill_nchar(STR_TMP, ' ', LN_MAX - NB_LN);
	else
		ft_fill_nchar(STR_TMP, '0', LN_MAX - NB_LN);
	ft_strncat(STR_TMP, tmp, NB_LN);
}

int				ft_conv_s(char *str, t_arg *arg, va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char*);
	if (tmp == NULL)
		ft_str_null(arg);
	else
	{
		if (FLAGS & F_MINUS)
			ft_minus_on(arg, tmp);
		else
			ft_minus_off(arg, tmp);
	}
	ft_write_buff(str, arg);
	return (LN_MAX);
}
