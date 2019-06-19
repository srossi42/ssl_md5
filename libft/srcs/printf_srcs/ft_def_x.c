/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:46:34 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:26 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_def_x_space(t_arg *arg)
{
	if ((PRECISION != -1) || FLAGS & F_BLANK || WIDTH > 0)
		NB_SPACES = LN_MAX - ft_max_int(2, PRECISION, NB_LN);
	if (FLAGS & F_HASH && !((ARG_STR[0] == '0' && ARG_STR[1] == '\0')))
		NB_SPACES -= 2;
}

void	ft_def_x_zero(t_arg *arg)
{
	NB_ZEROS = 0;
	if (PRECISION > NB_LN && (1 || (LN_MAX > NB_LN && WIDTH > PRECISION)))
		NB_ZEROS = PRECISION - NB_LN;
	if (FLAGS & F_ZERO)
		NB_ZEROS = LN_MAX - NB_LN - ((FLAGS & F_HASH && ARG_STR[0] != '0') ? 2
			: 0);
}

void	ft_def_x_lnmax(t_arg *arg)
{
	int nul;

	nul = 0;
	((ARG_STR[0] == '0' && ARG_STR[1] == '\0') ? nul = 1 : 0);
	LN_MAX = ft_max_int(3, NB_LN + ((FLAGS & F_HASH) && (!nul || (WIDTH == 0))
		? 2 : 0), PRECISION + (((FLAGS & F_HASH) && (!nul || (WIDTH == 0))) ? 2
		: 0), WIDTH);
	if ((FLAGS & F_HASH) && nul && (((PRECISION == 0 && WIDTH <= PRECISION)) ||
		(WIDTH == 0)))
		LN_MAX -= 2;
	if ((PRECISION == -1 && WIDTH == 0))
		LN_MAX--;
}

void	ft_def_x_str(t_arg *arg, va_list ap)
{
	if (TYPE == 'x')
		ARG_STR = ft_itoa_base_ull((ft_cast_us(arg, ap)), "0123456789abcdef");
	else if (TYPE == 'X')
		ARG_STR = ft_itoa_base_ull((ft_cast_us(arg, ap)), "0123456789ABCDEF");
}
