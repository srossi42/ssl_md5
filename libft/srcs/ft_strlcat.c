/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:44:26 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 10:52:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t src_ln;
	size_t dst_ln;

	i = 0;
	j = 0;
	src_ln = ft_strlen(src);
	dst_ln = ft_strlen(dst);
	if (size <= dst_ln)
		return (size + src_ln);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_ln + src_ln);
}
