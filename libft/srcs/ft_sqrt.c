/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 22:06:03 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:45:41 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;
	int j;

	i = nb;
	j = 1;
	if (nb <= 0)
		return (0);
	while (i != j)
	{
		i = j;
		j = (i + nb / i) / 2;
	}
	return (i);
}
