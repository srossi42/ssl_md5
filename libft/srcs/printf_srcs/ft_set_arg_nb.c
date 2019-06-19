/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_arg_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:50:07 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:41 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_def_nb_space(t_arg *arg)
{
	if ((PRECISION != -1) || FLAGS & F_BLANK || WIDTH > 0)
		NB_SPACES = LN_MAX - ft_max_int(2, PRECISION, NB_LN);
	if (!(FLAGS & F_ZERO))
	{
		if (PRECISION != -1 && (FLAGS & F_BLANK))
		{
			((PRECISION < NB_LN || WIDTH > PRECISION || (PRECISION > NB_LN &&
				WIDTH <= PRECISION)) ? NB_SPACES++ : 0);
			((PRECISION > NB_LN || (LN_MAX > NB_LN && WIDTH > PRECISION &&
				PRECISION >= NB_LN)) ? NB_SPACES-- : 0);
		}
		else
			((FLAGS & F_BLANK) ? NB_SPACES = 1 : 0);
	}
	else
		NB_SPACES = ((FLAGS & F_BLANK) ? 1 : 0);
	if ((FLAGS & F_PLUS) || (FLAGS & F_HASH && PRECISION <= NB_LN))
		NB_SPACES--;
	if (F_PREC == 1 && PRECISION == 0)
		NB_SPACES = LN_MAX - NB_LN - (((FLAGS & F_HASH)) ? 1 : 0);
	if (PRECISION == -1 && FLAGS & F_HASH)
		NB_SPACES++;
}

void	ft_def_nb_zero(t_arg *arg)
{
	NB_ZEROS = LN_MAX - ft_max_int(3, NB_LN, WIDTH, PRECISION);
	if (PRECISION > NB_LN)
	{
		NB_ZEROS += PRECISION - NB_LN;
		((FLAGS & F_BLANK && WIDTH > PRECISION) ? NB_ZEROS++ : 0);
		((FLAGS & F_PLUS && PRECISION >= WIDTH && WIDTH > 0) ? NB_ZEROS-- : 0);
		((FLAGS & F_HASH && WIDTH > NB_LN && PRECISION > 0) ? NB_ZEROS-- : 0);
	}
	else
	{
		if (FLAGS & F_ZERO)
			NB_ZEROS = LN_MAX - NB_LN - ((FLAGS & F_PLUS) ? 1 : 0);
		else
		{
			((FLAGS & F_PLUS && WIDTH != 0) ? NB_ZEROS-- : 0);
			((FLAGS & F_BLANK && WIDTH > PRECISION && PRECISION == NB_LN) ?
				NB_ZEROS++ : 0);
		}
	}
	if (F_PREC == 1 && PRECISION == 0)
		NB_ZEROS = ((FLAGS & F_HASH) ? 1 : 0);
	if (PRECISION >= 0 && WIDTH > NB_LN && FLAGS & F_HASH && !(FLAGS & F_ZERO))
		NB_ZEROS++;
}

void	ft_def_ln_max(t_arg *arg)
{
	LN_MAX = ft_max_int(3, NB_LN + ((FLAGS & F_PLUS) ? 1 : 0), PRECISION +
			((FLAGS & F_PLUS) ? 1 : 0), WIDTH);
	((PRECISION == -1 && WIDTH <= 0) ? LN_MAX-- : 0);
	if (((FLAGS & F_BLANK) && (WIDTH <= PRECISION || WIDTH <= NB_LN)) ||
			(PRECISION <= NB_LN && WIDTH <= NB_LN && (FLAGS & F_HASH)))
		LN_MAX++;
}

void	ft_def_nb_str(t_arg *arg, va_list ap)
{
	if (TYPE == 'u' || TYPE == 'U')
		ARG_STR = ft_itoa_base_ull(ft_cast_us(arg, ap), "0123456789");
	else if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		ARG_STR = ft_itoa_base_ll(ft_val_abs(ft_cast_s(arg, ap)), "0123456789");
	else if (TYPE == 'o' || TYPE == 'O')
		ARG_STR = ft_itoa_base_ull((ft_cast_us(arg, ap)), "01234567");
	else if (TYPE == 'b' || TYPE == 'B')
		ARG_STR = ft_itoa_base_ull((ft_cast_us(arg, ap)), "01");
}
