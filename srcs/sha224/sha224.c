/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:07:24 by srossi            #+#    #+#             */
/*   Updated: 2019/08/27 20:15:24 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha224.h"

void	ft_sha224_init(t_sha224_struct *sha224_struct, char *str, size_t size)
{
	sha224_struct->input = ft_strdup(str);
	sha224_struct->input_len = size;
	sha224_struct->total_len = sha224_struct->input_len + 1;
	SHA224_H0 = 0xc1059ed8;
	SHA224_H1 = 0x367cd507;
	SHA224_H2 = 0x3070dd17;
	SHA224_H3 = 0xf70e5939;
	SHA224_H4 = 0xffc00b31;
	SHA224_H5 = 0x68581511;
	SHA224_H6 = 0x64f98fa7;
	SHA224_H7 = 0xbefa4fa4;
}

void	ft_sha224_free(t_sha224_struct *sha224_struct)
{
	if (sha224_struct->data)
	{
		ft_bzero(sha224_struct->data, sha224_struct->total_len);
		free(sha224_struct->data);
	}
	if (sha224_struct->input)
		ft_strdel(&sha224_struct->input);
}

char	*ft_sha224(char *str_to_hash, size_t size)
{
	struct s_sha224_struct	sha224_struct;
	char					*hash;
	ssize_t					len;
	ssize_t					i;
	char					*tmp;

	ft_sha224_init(&sha224_struct, str_to_hash, size);
	ft_sha224_padding(&sha224_struct);
	ft_sha224_encode(&sha224_struct);
	hash = ft_sha224_decode(&sha224_struct);
	ft_sha224_free(&sha224_struct);
	len = 32 - ft_strlen(hash);
	i = 0;
	if (len > 0)
	{
		tmp = ft_strnew(len);
		while (i < len)
		{
			tmp[i] = '0';
			i++;
		}
		hash = ft_strjoin(tmp, hash);
		ft_strdel(&tmp);
	}
	return (hash);
}
