/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:35:07 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 16:10:02 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha256.h"

static void	ft_append_len(t_sha256_struct *sha256_struct, size_t bitlen)
{
	sha256_struct->data[sha256_struct->total_len] = (bitlen >> 56) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 1] = (bitlen >> 48) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 2] = (bitlen >> 40) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 3] = (bitlen >> 32) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 4] = (bitlen >> 24) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 5] = (bitlen >> 16) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 6] = (bitlen >> 8) & 0xFF;
	sha256_struct->data[sha256_struct->total_len + 7] = (bitlen) & 0xFF;
}

void		ft_sha256_padding(t_sha256_struct *sha256_struct)
{
	size_t	bitlen;
	int		msg_len;
	int		padding;

	padding = 0;
	msg_len = sha256_struct->input_len;
	bitlen = sha256_struct->input_len << 3;
	sha256_struct->count[0] = sha256_struct->input_len >> 29;
	sha256_struct->count[0] = bitlen;
	while (((sha256_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
		padding++;
	sha256_struct->total_len += padding;
	sha256_struct->data = (unsigned char *)ft_strnew(sha256_struct->total_len
			+ 8);
	ft_memcpy(sha256_struct->data, sha256_struct->input,
			sha256_struct->input_len);
	sha256_struct->data[msg_len] = (unsigned char)128;
	while (++msg_len <= sha256_struct->total_len)
		sha256_struct->data[msg_len] = 0;
	ft_append_len(sha256_struct, bitlen);
}
