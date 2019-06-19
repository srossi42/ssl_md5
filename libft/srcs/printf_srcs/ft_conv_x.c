/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:45:14 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:20 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_minus_on(t_arg *arg)
{
	NB_LN += ((FLAGS & F_BLANK) ? 1 : 0);
	ft_def_x_space(arg);
	ft_def_x_zero(arg);
	if ((FLAGS & F_HASH) && (!(ARG_STR[0] == '0' && ARG_STR[1] == '\0')))
	{
		if (ARG_STR[0] != '0')
			STR_TMP[COUNTER++] = '0';
		STR_TMP[COUNTER++] = ((TYPE == 'x') ? 'x' : 'X');
	}
	if (COUNTER < LN_MAX && PRECISION != -1)
		COUNTER += ft_fill_nchar(&STR_TMP[COUNTER], '0', NB_ZEROS);
	else if (PRECISION >= 0)
		ft_strcat(STR_TMP, ARG_STR);
}

static	void	ft_minus_off(t_arg *arg)
{
	NB_LN += ((FLAGS & F_BLANK) ? 1 : 0);
	ft_def_x_space(arg);
	ft_def_x_zero(arg);
	if (!(FLAGS & F_ZERO) || (FLAGS & F_BLANK))
		COUNTER += ft_fill_nchar(&STR_TMP[COUNTER], ' ', NB_SPACES - COUNTER);
	if ((FLAGS & F_HASH) && ((!(ARG_STR[0] == '0' && ARG_STR[1] == '\0'))))
	{
		if (ARG_STR[0] != '0')
			STR_TMP[COUNTER++] = '0';
		STR_TMP[COUNTER++] = ((TYPE == 'x') ? 'x' : 'X');
	}
	if (COUNTER < LN_MAX && PRECISION != -1)
		COUNTER += ft_fill_nchar(&STR_TMP[COUNTER], '0', NB_ZEROS);
	if (PRECISION < 0 && WIDTH > NB_LN)
		ft_strcat(STR_TMP, " ");
	else if (PRECISION >= 0)
		ft_strcat(STR_TMP, ARG_STR);
}

int				ft_conv_x(char *str, t_arg *arg, va_list ap)
{
	ft_def_x_str(arg, ap);
	NB_LN = ft_strlen(ARG_STR);
	ft_arg_clean(arg);
	ft_def_x_lnmax(arg);
	STR_TMP = ft_strnew(LN_MAX);
	if (FLAGS & F_MINUS)
	{
		ft_minus_on(arg);
		((PRECISION != -1) ? ft_strcat(&STR_TMP[COUNTER], ARG_STR) : 0);
		COUNTER += ft_strlen(ARG_STR);
		if (COUNTER < LN_MAX)
			ft_fill_nchar(&STR_TMP[COUNTER], ' ', LN_MAX - COUNTER);
	}
	else
		ft_minus_off(arg);
	ft_write_buff(str, arg);
	return (LN_MAX);
}
