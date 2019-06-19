/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:48:20 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:22:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_arg_clean(t_arg *arg)
{
	if (F_NEG)
		FLAGS |= F_PLUS;
	if ((FLAGS & F_BLANK) && (((FLAGS & F_PLUS) || F_NEG)
				|| TYPE == 'o' || TYPE == 'O'))
		FLAGS ^= F_BLANK;
	if ((FLAGS & F_ZERO) && ((PRECISION > 0) || (FLAGS & F_MINUS)))
		FLAGS ^= F_ZERO;
	if (ARG_STR[0] == '-')
		ARG_STR = ft_strsub(ARG_STR, 1, ft_strlen(ARG_STR) - 1);
	if (FLAGS & F_HASH && TYPE != 'x' && TYPE != 'X' && ((TYPE != 'o' &&
					TYPE != 'O') || (ARG_STR[0] == '0' && PRECISION != -1)))
		FLAGS ^= F_HASH;
	COUNTER = 0;
	if (TYPE == 'u' || TYPE == 'U')
	{
		((FLAGS & F_BLANK) ? (FLAGS ^= F_BLANK) : 0);
		((FLAGS & F_PLUS) ? (FLAGS ^= F_PLUS) : 0);
	}
	if ((FLAGS & F_PLUS) && (TYPE == 'o' || TYPE == 'O'))
		FLAGS ^= F_PLUS;
	return (0);
}
