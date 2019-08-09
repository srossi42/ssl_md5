/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:07:24 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 16:10:27 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha256.h"

void	ft_sha256_init(t_sha256_struct *sha256_struct, char *str_to_hash)
{
	sha256_struct->input = ft_strdup(str_to_hash);
	sha256_struct->input_len = ft_strlen(str_to_hash);
	sha256_struct->total_len = sha256_struct->input_len + 1;
	SHA256_H0 = 0x6a09e667;
	SHA256_H1 = 0xbb67ae85;
	SHA256_H2 = 0x3c6ef372;
	SHA256_H3 = 0xa54ff53a;
	SHA256_H4 = 0x510e527f;
	SHA256_H5 = 0x9b05688c;
	SHA256_H6 = 0x1f83d9ab;
	SHA256_H7 = 0x5be0cd19;
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

void	ft_sha256(char *str_to_hash)
{
	struct s_sha256_struct	sha256_struct;
	char					*hash;

	ft_sha256_init(&sha256_struct, str_to_hash);
	ft_sha256_padding(&sha256_struct);
	ft_sha256_encode(&sha256_struct);
	hash = ft_sha256_decode(&sha256_struct);
	//mettre le res dans la structure pour éviter de malloc à chaque fois une string
	ft_printf("sha256 (\"%s\") = %s\n", sha256_struct.input, hash);
	//ft_sha256_print_res(&sha256_struct);
	ft_sha256_free(&sha256_struct);
	//return hash;
}
