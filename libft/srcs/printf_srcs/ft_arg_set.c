/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:55:11 by srossi            #+#    #+#             */
/*   Updated: 2018/04/02 12:14:16 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_set_flags(char c, t_arg *arg)
{
	if (c == '-')
		FLAGS |= F_MINUS;
	else if (c == '+')
		FLAGS |= F_PLUS;
	else if (c == '#')
		FLAGS |= F_HASH;
	else if (c == '0')
		FLAGS |= F_ZERO;
	else if (c == ' ')
		FLAGS |= F_BLANK;
}

static	int		ft_set_precision(const char *str, t_arg *arg)
{
	F_PREC = 1;
	PRECISION = ft_atoi(&str[++COUNTER]);
	while (ft_isdigit(str[COUNTER]))
		COUNTER++;
	return (COUNTER);
}

static	int		ft_set_size(const char *c, t_arg *arg)
{
	char	*sizes;
	int		i;

	i = 0;
	sizes = "hhlljz";
	while (sizes[i])
	{
		if (*c == sizes[i] && (*c == *(c + 1)))
		{
			SIZE |= 1 << (i + 1);
			return (i + 1);
		}
		else if (*c == sizes[i])
		{
			SIZE |= 1 << i;
			return (i);
		}
		i++;
	}
	return (-1);
}

static	int		ft_arg_set_noconv(const char *str, t_arg *arg)
{
	int i;

	i = 0;
	COUNTER = 0;
	ARG_STR = ft_strdup(&str[MEM]);
	while (ft_isflag(str[COUNTER]) != -1)
		ft_set_flags(str[COUNTER++], arg);
	MEM = COUNTER;
	while (ft_isdigit(str[COUNTER]))
		COUNTER++;
	WIDTH = ft_val_abs(ft_atoi(&str[MEM]));
	MEM = COUNTER;
	if (str[COUNTER] == '.')
		ft_set_precision(str, arg);
	ft_set_size(&str[COUNTER], arg);
	TYPE = str[COUNTER];
	FORMAT_I += COUNTER;
	return (0);
}

int				ft_arg_set(const char *str, t_arg *arg)
{
	ARG_STR = NULL;
	while (ft_isflag(str[COUNTER]) != -1)
		ft_set_flags(str[COUNTER++], arg);
	MEM = COUNTER;
	while (ft_isdigit(str[COUNTER]))
		COUNTER++;
	WIDTH = ft_val_abs(ft_atoi(&str[MEM]));
	if (str[COUNTER] == '.')
		ft_set_precision(str, arg);
	ft_set_size(&str[COUNTER], arg);
	MEM = COUNTER;
	while (str[COUNTER] && ft_istypeconv(str[COUNTER]) == -1 &&
			str[COUNTER] != '*')
		COUNTER++;
	if (ft_istypeconv(str[COUNTER]) >= 0 && str[COUNTER] != '\0')
		TYPE = str[COUNTER];
	else if (str[COUNTER] == '\0' || ft_istypeconv(TYPE) == -1)
		return (ft_arg_set_noconv(str, arg));
	if ((TYPE == 's') && ((SIZE & L) || (SIZE & LL)))
		TYPE = 'S';
	if ((TYPE == 'c') && ((SIZE & L)))
		TYPE = 'C';
	FORMAT_I += COUNTER;
	MEM = BUFF_I;
	return (0);
}
