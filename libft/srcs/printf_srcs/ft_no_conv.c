/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:51:05 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:35 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_def_lnmax(t_arg *arg)
{
	LN_MAX = 0;
	if (TYPE != '\0')
		LN_MAX = ft_max_int(2, WIDTH, 1);
}

int				ft_no_conv(char *str, t_arg *arg)
{
	int i;

	i = 0;
	ft_def_lnmax(arg);
	STR_TMP = ft_strnew(LN_MAX);
	if (FLAGS & F_MINUS)
		STR_TMP[i++] = TYPE;
	while (i < LN_MAX - ((FLAGS & F_MINUS) ? 0 : 1))
		STR_TMP[i++] = ((FLAGS & F_ZERO) ? '0' : ' ');
	STR_TMP[i++] = TYPE;
	if (BUFF_I + LN_MAX <= BUFF_SIZE)
	{
		ft_strcat(str, STR_TMP);
		BUFF_I += LN_MAX;
	}
	else
	{
		write(1, str, BUFF_I);
		ft_bzero(str, BUFF_I);
		BUFF_I = 0;
		write(1, STR_TMP, LN_MAX);
	}
	arg->format_i++;
	return (LN_MAX);
}
