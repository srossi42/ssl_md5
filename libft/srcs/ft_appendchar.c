/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:01:08 by srossi            #+#    #+#             */
/*   Updated: 2018/01/05 18:58:58 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_appendchar(char **s1, char c)
{
	char	*tmp;
	int		i;

	if (*s1 && c)
	{
		i = ft_strlen(*s1);
		tmp = ft_strnew(i + 1);
		ft_strncpy(tmp, *s1, i);
		tmp[i] = c;
		ft_strdel(s1);
		*s1 = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (!s1 && c)
	{
		ft_putendl("chaine vide");
		*s1 = ft_strnew(1);
		*s1[0] = c;
	}
}
