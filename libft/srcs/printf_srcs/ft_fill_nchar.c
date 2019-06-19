/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:32:48 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill_nchar(char *str, char c, int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	return (i);
}
