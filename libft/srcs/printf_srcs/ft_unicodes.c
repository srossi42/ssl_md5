/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:31:53 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:23:43 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strlen_wchar(wchar_t *c, t_arg *arg)
{
	NB_BITS = 0;
	while (*c >> NB_BITS)
		NB_BITS++;
	if (NB_BITS <= 7)
		NB_LN = 1;
	else if (NB_BITS > 7 && NB_BITS <= 11)
		NB_LN = 2;
	else if (NB_BITS > 11 && NB_BITS <= 16)
		NB_LN = 3;
	else if (NB_BITS > 16 && NB_BITS <= 21)
		NB_LN = 4;
	else if (NB_BITS > 21)
		NB_LN = -1;
}

void	ft_unicode_4(wchar_t *c, char str[5])
{
	str[0] = (*c >> 18) | 0xf0;
	str[1] = ((*c >> 12) & 0x3f) | 0x80;
	str[2] = ((*c >> 6) & 0x3f) | 0x80;
	str[3] = (*c & 0x3f) | 0x80;
}

void	ft_unicode_3(wchar_t *c, char str[5])
{
	str[0] = (*c >> 12) | 0xe0;
	str[1] = ((*c >> 6) & 0x3f) | 0x80;
	str[2] = (*c & 0x3f) | 0x80;
}

void	ft_unicode_2(wchar_t *c, char str[5])
{
	str[0] = (*c >> 6) | 0xc0;
	str[1] = (*c & 0x3f) | 0x80;
}

void	ft_unicode_1(wchar_t *c, char str[5])
{
	str[0] = *c;
}
