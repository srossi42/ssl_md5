/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdetect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:58 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:29 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "-+#0 ";
	while (flags[i] && flags[i] != c)
		i++;
	if (i == 5)
		return (-1);
	return (i);
}

int	ft_issize(char c)
{
	char	*sizes;
	int		i;

	i = 0;
	sizes = "hhlljz";
	while (sizes[i])
	{
		if (c == sizes[i])
			return (1);
		i++;
	}
	return (-1);
}

int	ft_istypeconv(char c)
{
	char	*types;
	int		i;

	i = 0;
	types = "\%sSpdDioOuUxXcCbB";
	while (types[i] && types[i] != c)
		i++;
	if (types[i] == '\0')
		return (-1);
	return (i);
}

int	ft_isprecision(char *str)
{
	int i;

	i = 0;
	if (str[i] == '.')
		i++;
	else
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (ft_atoi(&str[1]));
}
