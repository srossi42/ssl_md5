/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:58:14 by srossi            #+#    #+#             */
/*   Updated: 2018/05/01 10:32:42 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static	int		ft_count_words(char const *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (nb_words);
		nb_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (nb_words);
}

static	int		*ft_count_letters(char const *s, char c)
{
	int	i;
	int	j;
	int	nb_letters;
	int	*ptr;

	i = 0;
	j = 0;
	if (!(ptr = (int*)malloc(sizeof(*ptr) * ft_count_words(s, c))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (ptr);
		nb_letters = 0;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			nb_letters++;
		}
		ptr[j] = nb_letters;
		j++;
	}
	return (ptr);
}

static	void	ft_fill(char ***ptr, const char *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return ;
		while (s[i] != c && s[i] != '\0')
		{
			(*ptr)[word][j] = s[i];
			j++;
			i++;
		}
		(*ptr)[word][j] = '\0';
		word++;
	}
	return ;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_words;
	int		*nb_letters;
	char	**ptr;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	nb_letters = ft_count_letters(s, c);
	i = 0;
	if (!(ptr = (char**)malloc(sizeof(*ptr) * (nb_words + 1))))
		return (NULL);
	while (i < nb_words)
	{
		if (!(ptr[i] = (char *)malloc(sizeof(**ptr) * (nb_letters[i] + 1))))
			return (NULL);
		i++;
	}
	ptr[i] = NULL;
	ft_fill(&ptr, s, c);
	free(nb_letters);
	return (ptr);
}
