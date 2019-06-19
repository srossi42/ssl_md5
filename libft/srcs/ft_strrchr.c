/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:44:42 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 10:56:41 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		mem;
	char	*str;

	str = (char *)s;
	i = 0;
	mem = -1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			mem = i;
		i++;
	}
	if (str[i] == '\0' && c == 0)
		return (&str[i]);
	else if (mem > -1)
		return (&str[mem]);
	return (NULL);
}
