/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:07:24 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:22:33 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha256.h"

void	ft_sha256_init(t_sha256_struct *sha256_struct, char *str, size_t size)
{
	sha256_struct->input = ft_strdup(str);
	sha256_struct->input_len = size;
	sha256_struct->total_len = sha256_struct->input_len + 1;
	sha256_struct->state[0] = 0x6a09e667;
	sha256_struct->state[1] = 0xbb67ae85;
	sha256_struct->state[2] = 0x3c6ef372;
	sha256_struct->state[3] = 0xa54ff53a;
	sha256_struct->state[4] = 0x510e527f;
	sha256_struct->state[5] = 0x9b05688c;
	sha256_struct->state[6] = 0x1f83d9ab;
	sha256_struct->state[7] = 0x5be0cd19;
}

void	ft_sha256_free(t_sha256_struct *sha256_struct)
{
	if (sha256_struct->data)
	{
		ft_bzero(sha256_struct->data, sha256_struct->total_len);
		free(sha256_struct->data);
	}
	if (sha256_struct->input)
		ft_strdel(&sha256_struct->input);
}

char	*ft_sha256(char *str_to_hash, size_t size)
{
	struct s_sha256_struct	sha256_struct;
	char					*hash;
	ssize_t					len;
	ssize_t					i;
	char					*tmp;

	ft_sha256_init(&sha256_struct, str_to_hash, size);
	ft_sha256_padding(&sha256_struct);
	ft_sha256_encode(&sha256_struct);
	hash = ft_sha256_decode(&sha256_struct);
	ft_sha256_free(&sha256_struct);
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
