/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:44:13 by srossi            #+#    #+#             */
/*   Updated: 2017/11/18 17:43:27 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len)
	{
		dst[i] = src[i];
		len--;
		i++;
	}
	if (len)
	{
		while (len)
		{
			dst[i] = '\0';
			len--;
			i++;
		}
	}
	return (dst);
}
