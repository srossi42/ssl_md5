/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:18:32 by srossi            #+#    #+#             */
/*   Updated: 2019/08/27 20:18:39 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

char		*ft_strnjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	char    *s3;
	int     i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return s1;
	s3 = ft_strnew(len1 + len2);
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		s3[i] = s2[i - len1];
		i++;
	}
	if (s1)
		ft_strdel(&s1);
	return (s3);
};
