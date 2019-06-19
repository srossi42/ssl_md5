/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:52:20 by srossi            #+#    #+#             */
/*   Updated: 2017/11/18 18:37:18 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*src_cpy;

	i = 0;
	str = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	while (i < n)
	{
		str[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
