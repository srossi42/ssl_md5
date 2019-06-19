/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:45:44 by srossi            #+#    #+#             */
/*   Updated: 2017/11/21 16:06:50 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_cpy;

	i = (size_t)start;
	j = 0;
	if (!(s_cpy = (char *)malloc(sizeof(*s_cpy) * (len + 1))) || !s)
		return (NULL);
	while (s[i] != '\0' && i < (len + start))
	{
		s_cpy[j] = s[i];
		i++;
		j++;
	}
	s_cpy[j] = '\0';
	return (s_cpy);
}
