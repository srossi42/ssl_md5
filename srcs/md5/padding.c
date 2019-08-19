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
#include <string.h>

void	ft_md5_padding(t_md5_struct *md5_struct)
{
    uint64_t padding;

    padding = 0;
    while (((md5_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
        padding++;

    md5_struct->total_len += padding + 8;

    if (!(md5_struct->data = (char *)ft_memalloc((md5_struct->total_len))))
        exit(0);
    printf("POUET1\n");
//    ft_memcpy(md5_struct->data, md5_struct->input, md5_struct->input_len);

    printf("total len : %lld\n", md5_struct->total_len);
    printf("input len : %lld\n", md5_struct->input_len);
//    exit(0);


    md5_struct->data = ft_memcpy(md5_struct->data, md5_struct->input, md5_struct->input_len);
    printf("POUET2\n");
    md5_struct->data[md5_struct->input_len] = (unsigned char)0b10000000;
    printf("POUET3\n");
    md5_struct->data[md5_struct->total_len - 1] = (8 * md5_struct->input_len >> 56) & 0xFF;
    md5_struct->data[md5_struct->total_len - 2] = (8 * md5_struct->input_len >> 48) & 0xFF;
    md5_struct->data[md5_struct->total_len - 3] = (8 * md5_struct->input_len >> 40) & 0xFF;
    md5_struct->data[md5_struct->total_len - 4] = (8 * md5_struct->input_len >> 32) & 0xFF;
    md5_struct->data[md5_struct->total_len - 5] = (8 * md5_struct->input_len >> 24) & 0xFF;
    md5_struct->data[md5_struct->total_len - 6] = (8 * md5_struct->input_len >> 16) & 0xFF;
    md5_struct->data[md5_struct->total_len - 7] = (8 * md5_struct->input_len >> 8) & 0xFF;
    md5_struct->data[md5_struct->total_len - 8] = (8 * md5_struct->input_len) & 0xFF;
    md5_struct->total_len -= 8;
}

