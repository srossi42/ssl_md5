/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:44:01 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:05 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_def_p_lnmax(t_arg *arg)
{
	NB_LN = ft_strlen(ARG_STR);
	LN_MAX = ft_max_int(3, NB_LN + 2, WIDTH, PRECISION + 2) -
		((F_PREC && PRECISION == 0) ? 1 : 0);
}

static	void	ft_minus_off(t_arg *arg, uintmax_t p)
{
	if (!(FLAGS & F_ZERO))
	{
		while (COUNTER < LN_MAX - ft_max_int(2, PRECISION, NB_LN) - 2)
			STR_TMP[COUNTER++] = ' ';
		ft_strcat(STR_TMP, "0x");
		COUNTER += 2;
		while (COUNTER < LN_MAX - NB_LN)
			STR_TMP[COUNTER++] = '0';
		if (!p && PRECISION != 0)
			ft_strcat(STR_TMP, "0");
		else
			ft_strcat(STR_TMP, ARG_STR);
	}
	else
	{
		ft_strcat(STR_TMP, "0x");
		COUNTER += 2;
		while (COUNTER < LN_MAX - NB_LN)
			STR_TMP[COUNTER++] = '0';
		if (!p)
			ft_strcat(STR_TMP, "0");
		else
			ft_strcat(STR_TMP, ARG_STR);
	}
}

static	void	ft_minus_on(t_arg *arg, uintmax_t p)
{
	COUNTER = NB_LN + 2;
	ft_strcat(STR_TMP, "0x");
	if (!p && PRECISION != 0)
		ft_strcat(STR_TMP, "0");
	else
		ft_strcat(STR_TMP, ARG_STR);
	while (COUNTER < LN_MAX)
		STR_TMP[COUNTER++] = ' ';
}

int				ft_conv_p(char *str, t_arg *arg, va_list ap)
{
	uintmax_t	p;

	COUNTER = 0;
	p = va_arg(ap, uintmax_t);
	ARG_STR = ft_itoa_base_ull(p, "0123456789abcdef");
	ft_def_p_lnmax(arg);
	STR_TMP = ft_strnew(LN_MAX);
	if (FLAGS & F_MINUS)
		ft_minus_on(arg, p);
	else
		ft_minus_off(arg, p);
	ft_write_buff(str, arg);
	return (LN_MAX);
}
