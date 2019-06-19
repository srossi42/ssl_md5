/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:06:53 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 11:12:40 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static	int	ft_nb_len(int n)
{
	int		nb_len;

	nb_len = 0;
	if (n == 0)
		nb_len = 1;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		nb_len++;
	}
	return (nb_len);
}

static	int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		nb_len;
	long	l;
	int		ln_max;

	l = (long)n;
	l = l * (ft_sign(n));
	nb_len = ft_nb_len(n);
	if (n < 0)
		nb_len++;
	ln_max = nb_len;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (nb_len + 1))))
		return (NULL);
	while (nb_len > 0)
	{
		nb_len--;
		ptr[nb_len] = l % 10 + 48;
		l = l / 10;
	}
	if (n < 0)
		ptr[0] = '-';
	ptr[ln_max] = '\0';
	return (ptr);
}
