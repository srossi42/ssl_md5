/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:14:30 by srossi            #+#    #+#             */
/*   Updated: 2018/02/07 15:21:40 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t		ft_nblen_ullb(unsigned long long l, int ln_base)
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

char				*ft_itoa_base_ull(unsigned long long l, char *base)
{
	int					ln_base;
	unsigned long long	tmp;
	char				*str;
	int					j;

	ln_base = ft_strlen(base);
	j = 0;
	if (l == 0)
		return (ft_strdup("0"));
	str = ft_strnew(ft_nblen_ullb(l, ln_base));
	while (l > 0)
	{
		tmp = l % ln_base;
		l = l / ln_base;
		str[j] = base[tmp];
		j++;
	}
	ft_strrev(str);
	return (str);
}
