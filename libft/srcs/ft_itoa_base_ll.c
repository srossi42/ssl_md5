/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:13:10 by srossi            #+#    #+#             */
/*   Updated: 2018/03/19 15:30:35 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	size_t	ft_nblen_llb(long long l, int ln_base)
{
	size_t i;

	i = 0;
	while (l)
	{
		l = l / ln_base;
		i++;
	}
	return (i);
}

static	int		ft_sign(long long l)
{
	if (l < 0)
		return (1);
	return (0);
}

static	char	*ft_specialcase(long long l)
{
	if (l == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	else if (l == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup(""));
}

char			*ft_itoa_base_ll(long long l, char *base)
{
	int			ln_base;
	long long	tmp;
	char		*str;
	size_t		i;
	int			j;

	ln_base = ft_strlen(base);
	i = ft_sign(l);
	j = 0;
	if (l == LLONG_MIN || l == 0)
		return (ft_specialcase(l));
	if (l < 0)
		l = -l;
	str = ft_strnew(ft_nblen_llb(l, ln_base) + i);
	while (l > 0)
	{
		tmp = l % ln_base;
		l = l / ln_base;
		str[j] = base[tmp];
		j++;
	}
	if (i == 1 && ln_base == 10)
		str[j] = '-';
	ft_strrev(str);
	return (str);
}
