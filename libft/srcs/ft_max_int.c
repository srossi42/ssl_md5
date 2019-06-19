/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:14:46 by srossi            #+#    #+#             */
/*   Updated: 2018/01/29 15:16:40 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_int(int nb_int, ...)
{
	int		argument;
	int		int_max;
	int		i;
	va_list ap;

	i = 0;
	int_max = 0;
	if (nb_int <= 0)
		return (-1);
	va_start(ap, nb_int);
	while (i < nb_int)
	{
		argument = va_arg(ap, int);
		if (argument > int_max)
			int_max = argument;
		i++;
	}
	va_end(ap);
	return (int_max);
}
