/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:25:01 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:22:54 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_cast_us(t_arg *arg, va_list ap)
{
	uintmax_t nb;

	if (SIZE & J || TYPE == 'p' || TYPE == 'U' || TYPE == 'O')
		nb = va_arg(ap, uintmax_t);
	else if (SIZE & HH)
		nb = (uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	else if (SIZE & H)
		nb = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	else if (SIZE & L || SIZE & LL)
		nb = (uintmax_t)va_arg(ap, unsigned long);
	else if (SIZE & Z)
		nb = (uintmax_t)(va_arg(ap, size_t));
	else
		nb = (uintmax_t)va_arg(ap, unsigned int);
	((PRECISION == 0 && nb == 0 && F_PREC == 1) ? PRECISION = -1 : 0);
	return (nb);
}

intmax_t	ft_cast_s(t_arg *arg, va_list ap)
{
	intmax_t nb;

	if (SIZE & L || SIZE & LL || TYPE == 'D')
		nb = (intmax_t)va_arg(ap, long);
	else if (SIZE & HH)
		nb = (intmax_t)((char)va_arg(ap, int));
	else if (SIZE & H)
		nb = (intmax_t)((short)va_arg(ap, int));
	else if (SIZE & J)
		nb = va_arg(ap, intmax_t);
	else if (SIZE & Z)
		nb = ft_cast_us(arg, ap);
	else
		nb = (intmax_t)va_arg(ap, int);
	F_NEG = ((nb < 0) ? 1 : 0);
	((PRECISION == 0 && nb == 0 && F_PREC == 1) ? PRECISION = -1 : 0);
	return (nb);
}
