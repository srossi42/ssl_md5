/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:54:28 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 11:36:52 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static	int	ft_def_start(char *s)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static	int	ft_def_end(char *s)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] != '\0' && s[i] != ' ' && s[i] != '\n' && s[i] != '\t' &&
				((s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] != '\t')))
			end = i;
	}
	return (end);
}

static void	ft_fill(char const *s, char *s_cpy, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		s_cpy[i] = s[start];
		i++;
		start++;
	}
	s_cpy[i] = '\0';
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*s_cpy;

	i = 0;
	if (!s)
		return (NULL);
	start = ft_def_start((char *)s);
	end = ft_def_end((char *)s);
	if (end < start)
	{
		start = 0;
		if (!(s_cpy = (char *)malloc(sizeof(char) * (end - start + 1))))
			return (NULL);
		s_cpy[i] = '\0';
	}
	else
	{
		if (!(s_cpy = (char *)malloc(sizeof(char) * (end - start + 2))))
			return (NULL);
		ft_fill(s, s_cpy, start, end);
	}
	return (s_cpy);
}
