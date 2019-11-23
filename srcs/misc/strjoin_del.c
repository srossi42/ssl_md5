/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:02:37 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 18:00:51 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

char			*ft_strjoin_del(char *s1, char *s2)
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
		str[k++] = *s2++;
	str[k] = '\0';
	if (s1)
		ft_strdel(&s1);
	return (str);
}
