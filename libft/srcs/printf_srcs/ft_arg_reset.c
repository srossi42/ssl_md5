/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:40:47 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:22:49 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_reset(t_arg *arg, int n)
{
	if (n == 0)
		INDEX = 0;
	LN_MAX = 0;
	FLAGS = 0;
	WIDTH = -1;
	PRECISION = 0;
	TYPE = 0;
	COUNTER = 0;
	F_PREC = 0;
	F_NEG = 0;
	ARG_NB = 0;
	ARG_UL_NB = 0;
	NB_SPACES = 0;
	NB_ZEROS = 0;
	SIZE = 0;
	if ((ARG_STR) != NULL)
		ft_strdel(&(ARG_STR));
	if ((STR_TMP) != NULL)
		ft_strdel(&(STR_TMP));
	if (n == 2)
		return (-1);
	return (0);
}
