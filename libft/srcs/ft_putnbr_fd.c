/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:56:10 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 10:56:21 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long l;

	l = (long)n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l >= 10)
	{
		ft_putnbr_fd((l / 10), fd);
		ft_putnbr_fd((l % 10), fd);
	}
	else
		ft_putchar_fd(l + 48, fd);
}
