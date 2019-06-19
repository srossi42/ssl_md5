/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:11:41 by srossi            #+#    #+#             */
/*   Updated: 2018/02/26 11:31:03 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_val_abs(long long nb)
{
	unsigned long long ullong_nb;

	if (nb < 0)
		return (ullong_nb = -nb);
	return (ullong_nb = nb);
}
