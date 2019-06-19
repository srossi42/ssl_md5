/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:53:16 by srossi            #+#    #+#             */
/*   Updated: 2018/03/01 14:26:16 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_min_int(int nb_int, ...)
{
	int		argument;
	int		int_min;
	int		i;
	va_list ap;

	i = 0;
	int_min = INT_MAX;
	if (nb_int <= 0)
		return (-1);
	va_start(ap, nb_int);
	while (i < nb_int)
	{
		argument = va_arg(ap, int);
		if (argument < int_min)
			int_min = argument;
		i++;
	}
	va_end(ap);
	return (int_min);
}
