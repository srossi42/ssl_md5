/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:34 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 14:50:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_reverse_words(t_md5_struct *md5_struct)
{
	MD5_H0 = ft_reverse_bits(MD5_H0);
	MD5_H1 = ft_reverse_bits(MD5_H1);
	MD5_H2 = ft_reverse_bits(MD5_H2);
	MD5_H3 = ft_reverse_bits(MD5_H3);
}



// a mettre dans un fichier a part !!!
char		*ft_strjoin_del(char *s1, char *s2)
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
    if (s1)
        ft_strdel(&s1);
//    if (s2)
//        ft_strdel(&s2);
    return (str);
}



char			*ft_md5_decode(t_md5_struct *md5_struct)
{
	char *res;
	char *tmp;

	ft_md5_reverse_words(md5_struct);
	res = ft_itoa_base_ull(MD5_H0, "0123456789abcdef");

	tmp = ft_itoa_base_ull(MD5_H1, "0123456789abcdef");
	res = ft_strjoin_del(res, tmp);
	ft_strdel(&tmp);

	tmp = ft_itoa_base_ull(MD5_H2, "0123456789abcdef");
    res = ft_strjoin_del(res, tmp);
    ft_strdel(&tmp);

    tmp = ft_itoa_base_ull(MD5_H3, "0123456789abcdef");
	res = ft_strjoin_del(res, tmp);
    ft_strdel(&tmp);

	return (res);
}
