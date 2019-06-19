/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:43:53 by srossi            #+#    #+#             */
/*   Updated: 2017/11/18 12:57:53 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s1_cpy;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(s1_cpy = (char *)malloc(sizeof(*s1) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}
