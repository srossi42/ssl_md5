/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:04:53 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:25:52 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_tabwcptr.h"

static	void	ft_minus_on(t_arg *arg)
{
	COUNTER = 0;
	while (COUNTER < LN_MAX - NB_LN)
	{
		STR_TMP[NB_LN + COUNTER] = ' ';
		COUNTER++;
	}
}

static	void	ft_minus_off(t_arg *arg)
{
	COUNTER = 0;
	while (COUNTER < LN_MAX - NB_LN)
	{
		STR_TMP[COUNTER] = ' ';
		COUNTER++;
	}
}

int				ft_write_wchar(char *buff, t_arg *arg)
{
	write(1, buff, BUFF_I);
	ft_bzero(buff, BUFF_I);
	BUFF_I = 0;
	write(1, STR_TMP, LN_MAX);
	return (0);
}

int				ft_conv_wc(t_arg *arg, wchar_t c)
{
	char	w_str[5];

	ft_bzero(w_str, 5);
	if (c > 0x10ffff || (c >= 0xd800 && c <= 0xdfff) || c < 0)
		return (-1);
	ft_strlen_wchar(&c, arg);
	if (c >= 128 && c <= 255 && MB_CUR_MAX == 1)
		NB_LN = 1;
	if (MB_CUR_MAX < NB_LN)
	{
		if (MB_CUR_MAX == 1)
			return (-1);
		NB_LN = 1;
	}
	if (c == 0)
		w_str[0] = '\0';
	else
		tab_wc[NB_LN - 1].f_type(&c, w_str);
	ft_strcat(STR_TMP, w_str);
	return (NB_LN);
}

int				ft_conv_wchar(char *str, t_arg *arg, va_list ap)
{
	wchar_t c;
	char	w_str[5];

	ft_bzero(w_str, 5);
	c = va_arg(ap, wchar_t);
	if (c > 0x10ffff || (c >= 0xd800 && c <= 0xdfff) || c < 0)
		return (-1);
	ft_strlen_wchar(&c, arg);
	if (c >= 128 && c <= 255 && MB_CUR_MAX == 1)
		NB_LN = 1;
	LN_MAX = ft_max_int(2, WIDTH, NB_LN);
	STR_TMP = ft_strnew(LN_MAX);
	if (MB_CUR_MAX < NB_LN)
		return (-1);
	if (!(FLAGS & F_MINUS))
		ft_minus_off(arg);
	if (c == 0)
		w_str[0] = '\0';
	else
		tab_wc[NB_LN - 1].f_type(&c, w_str);
	ft_strcat(STR_TMP, w_str);
	if (FLAGS & F_MINUS)
		ft_minus_on(arg);
	ft_write_wchar(str, arg);
	return (LN_MAX);
}
