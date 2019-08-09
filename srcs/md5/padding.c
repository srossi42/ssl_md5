/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:08:34 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 15:10:19 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void	ft_md5_padding(t_md5_struct *md5_struct)
{
	unsigned int	bitlen;
	int				msg_len;
	int				padding;

	padding = 0;
	msg_len = md5_struct->input_len;
	bitlen = md5_struct->input_len << 3;
	md5_struct->count[1] = md5_struct->input_len >> 29;
	md5_struct->count[0] = bitlen;
	while (((md5_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
		padding++;
	md5_struct->total_len += padding;
	md5_struct->data = (unsigned char *)ft_strnew(md5_struct->total_len + 8);
	ft_memcpy(md5_struct->data, md5_struct->input, md5_struct->input_len);
	md5_struct->data[msg_len] = (unsigned char)128;
	while (++msg_len <= md5_struct->total_len)
		md5_struct->data[msg_len] = 0;
	ft_memcpy(md5_struct->data + md5_struct->total_len, &bitlen, 4);
}
