/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:08 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:02 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_minus_on(t_arg *arg)
{
	STR_TMP = ft_strnew(LN_MAX);
	if (!F_NEG && (FLAGS & F_BLANK))
		STR_TMP[COUNTER++] = ' ';
	if ((TYPE == 'o' || TYPE == 'O' || TYPE == 'b' || TYPE == 'B') &&
		FLAGS & F_HASH && (PRECISION <= NB_LN))
		STR_TMP[COUNTER++] = '0';
	(F_NEG ? (STR_TMP[COUNTER++] = '-') : 0);
	if ((FLAGS & F_PLUS) && !F_NEG)
		STR_TMP[COUNTER++] = '+';
	if (PRECISION > NB_LN)
		COUNTER += ft_fill_nchar(&STR_TMP[COUNTER], '0', PRECISION - NB_LN);
}

static	void	ft_minus_off(t_arg *arg)
{
	NB_LN += ((FLAGS & F_BLANK) ? 1 : 0) + (((FLAGS & F_PLUS) && !(WIDTH > 0
					&& PRECISION >= 0)) ? 1 : 0);
	STR_TMP = ft_strnew(LN_MAX);
	ft_bzero(STR_TMP, sizeof(char) * LN_MAX);
	ft_def_nb_space(arg);
	ft_def_nb_zero(arg);
	if (!(FLAGS & F_ZERO) || ((FLAGS & F_ZERO) && ((FLAGS & F_BLANK) ||
		(F_PREC == 1))))
		COUNTER += ft_fill_nchar(&STR_TMP[COUNTER], ' ', NB_SPACES - COUNTER);
	if (FLAGS & F_PLUS)
		STR_TMP[COUNTER++] = ((F_NEG) ? '-' : '+');
	if (COUNTER < LN_MAX && PRECISION != -1)
		COUNTER += ft_fill_nchar(&STR_TMP[COUNTER], '0', NB_ZEROS);
	if (PRECISION < 0 && WIDTH > NB_LN && !(FLAGS & F_HASH))
		ft_strcat(STR_TMP, " ");
	else if (PRECISION >= 0)
		ft_strcat(STR_TMP, ARG_STR);
	else if (PRECISION == -1 && FLAGS & F_HASH)
		STR_TMP[COUNTER] = '0';
}

int				ft_conv_nb(char *str, t_arg *arg, va_list ap)
{
	ft_def_nb_str(arg, ap);
	ft_arg_clean(arg);
	NB_LN = ft_strlen(ARG_STR);
	ft_def_ln_max(arg);
	ft_strdel(&STR_TMP);
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
