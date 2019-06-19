/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:45:28 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 11:32:25 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s1 | !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (i + j + 1))))
		return (NULL);
	while (k < i && s1[k] != '\0')
	{
		str[k] = s1[k];
		k++;
	}
	while (k < (i + j) && *s2)
	{
		str[k] = *s2++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
