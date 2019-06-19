/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:44:14 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:08 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_load_buffer(t_arg *arg)
{
	if (!(FLAGS & F_MINUS))
	{
		ft_fill_nchar(STR_TMP, ((FLAGS & F_ZERO) ? '0' : ' '), LN_MAX - NB_LN);
		STR_TMP[LN_MAX - 1] = '%';
	}
	else
	{
		STR_TMP[0] = '%';
		ft_fill_nchar(&STR_TMP[1], ' ', LN_MAX - NB_LN);
	}
}

int				ft_conv_percent(char *str, t_arg *arg, va_list ap)
{
	COUNTER = 0;
	NB_LN = 1;
	ap = 0;
	LN_MAX = ft_max_int(2, WIDTH, 1);
	STR_TMP = ft_strnew(LN_MAX);
	ft_load_buffer(arg);
	ft_write_buff(str, arg);
	return (LN_MAX);
}
