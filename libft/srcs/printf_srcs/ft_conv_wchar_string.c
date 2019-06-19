/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wchar_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:45:05 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:17 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_minus_on(t_arg *arg, int wstr_ln)
{
	int i;

	i = wstr_ln;
	while (i < LN_MAX)
	{
		if (!(FLAGS & F_ZERO))
			STR_TMP[i] = ' ';
		else
			STR_TMP[i] = '0';
		i++;
	}
	i = wstr_ln;
	while (i < LN_MAX)
	{
		if (!(FLAGS & F_ZERO))
			STR_TMP[i] = ' ';
		else
			STR_TMP[i] = '0';
		i++;
	}
}

static	void	ft_minus_off(t_arg *arg, int wstr_ln)
{
	int i;

	i = 0;
	while (i < LN_MAX - (!(F_PREC && PRECISION == -1) ? wstr_ln : 0))
	{
		if (!(FLAGS & F_ZERO))
			STR_TMP[i] = ' ';
		else
			STR_TMP[i] = '0';
		i++;
	}
}

static int		ft_init_wcharstr(char *str, t_arg *arg, wchar_t *ws)
{
	if (ws == NULL)
	{
		ft_str_null(arg);
		ft_write_buff(str, arg);
		return (LN_MAX);
	}
	return (0);
}

static	int		ft_ws_len(t_arg *arg, wchar_t *ws)
{
	int i;
	int wstr_ln;

	i = 0;
	wstr_ln = 0;
	while ((ws[i]))
	{
		ft_strlen_wchar(&ws[i], arg);
		if (MB_CUR_MAX == 1)
			NB_LN = 1;
		if (!F_PREC || PRECISION >= NB_LN + wstr_ln)
			wstr_ln += NB_LN;
		i++;
	}
	return (wstr_ln);
}

int				ft_conv_wchar_s(char *str, t_arg *arg, va_list ap)
{
	wchar_t *ws;
	int		i;
	int		wstr_ln;

	i = 0;
	ws = va_arg(ap, wchar_t*);
	if (ws == NULL || (F_PREC && PRECISION == 0 && WIDTH == 0))
		return (ft_init_wcharstr(str, arg, ws));
	wstr_ln = ft_ws_len(arg, ws);
	LN_MAX = ((PRECISION != -1) ? ft_max_int(2, wstr_ln, WIDTH) : 0);
	STR_TMP = ft_strnew(LN_MAX);
	if (!(FLAGS & F_MINUS))
		ft_minus_off(arg, wstr_ln);
	i = 0;
	while (ws[i] != '\0' && NB_LN != -1 && ((PRECISION > 0) || (!F_PREC)))
	{
		NB_LN = ft_conv_wc(arg, ws[i++]);
		PRECISION -= NB_LN;
	}
	if (FLAGS & F_MINUS)
		ft_minus_on(arg, wstr_ln);
	if (NB_LN == -1)
		return (-1);
	ft_write_wchar(str, arg);
	return (LN_MAX);
}
