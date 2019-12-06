/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:35:07 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 15:25:54 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha224.h"

static void	ft_append_len(t_sha224_struct *sha224_struct, size_t bitlen)
{
	sha224_struct->data[sha224_struct->total_len] = (bitlen >> 56) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 1] = (bitlen >> 48) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 2] = (bitlen >> 40) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 3] = (bitlen >> 32) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 4] = (bitlen >> 24) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 5] = (bitlen >> 16) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 6] = (bitlen >> 8) & 0xFF;
	sha224_struct->data[sha224_struct->total_len + 7] = (bitlen) & 0xFF;
}

void		ft_sha224_padding(t_sha224_struct *sha224_struct)
{
	size_t	bitlen;
	int		msg_len;
	int		padding;

	padding = 0;
	msg_len = sha224_struct->input_len;
	bitlen = sha224_struct->input_len << 3;
	sha224_struct->count[0] = sha224_struct->input_len >> 29;
	sha224_struct->count[0] = bitlen;
	while (((sha224_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
		padding++;
	sha224_struct->total_len += padding;
	sha224_struct->data = (unsigned char *)ft_strnew(sha224_struct->total_len
			+ 8);
	ft_memcpy(sha224_struct->data, sha224_struct->input,
			sha224_struct->input_len);
	sha224_struct->data[msg_len] = (unsigned char)128;
	while (++msg_len <= sha224_struct->total_len)
		sha224_struct->data[msg_len] = 0;
	ft_append_len(sha224_struct, bitlen);
}
