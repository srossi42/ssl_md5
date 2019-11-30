/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:04:07 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 16:05:15 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

uint32_t	ft_bsig0(uint32_t x)
{
	return (ft_rotate_right(x, 2) ^ ft_rotate_right(x, 13)
		^ ft_rotate_right(x, 22));
}

uint32_t	ft_bsig1(uint32_t x)
{
	return (ft_rotate_right(x, 6) ^ ft_rotate_right(x, 11)
		^ ft_rotate_right(x, 25));
}

uint32_t	ft_ssig0(uint32_t x)
{
	return (ft_rotate_right(x, 7) ^ ft_rotate_right(x, 18) ^ (x >> 3));
}

uint32_t	ft_ssig1(uint32_t x)
{
	return (ft_rotate_right(x, 17) ^ ft_rotate_right(x, 19) ^ (x >> 10));
}
