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

void	ft_md5_padding(t_md5_struct *md5_struct) {
    unsigned int bitlen;
    uint64_t msg_len;
    uint64_t padding;

    padding = 0;
    msg_len = md5_struct->input_len;
    bitlen = md5_struct->input_len << 3;
    md5_struct->count[1] = md5_struct->input_len >> 29;
    md5_struct->count[0] = bitlen;
    while (((md5_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
        padding++;

    md5_struct->total_len += padding;

    printf("padding : %llu\n", padding); //                                               55
    printf("md5_struct->input_len :    %lld\n", md5_struct->input_len); //     2 152 726 528
    printf("md5_struct->total_len : %llu\n", md5_struct->total_len); //        2 152 726 584
    printf("md5_struct->total_len + 8 : %lld\n", md5_struct->total_len + 8);// 2 152 726 592

    if (!(md5_struct->data = (char *)ft_memalloc((md5_struct->total_len + 8)))){
        ft_printf("Erreur sur le malloc de data\n");
        exit(0);
    }

//    printf(md5_struct->input)

//    GROS SEGFAULT ICI : INPUT n'aurait pas assez de donnees et n'arrive pas a copier autant de char que demandé :
//    md5_struct->input_len (2 152 726 528 char)

      md5_struct->data = ft_memcpy(md5_struct->data, md5_struct->input, md5_struct->input_len);


//    printf("copy OK \n");

	md5_struct->data[msg_len] = (unsigned char)128;
    printf("data 128 OK \n");
	while (++msg_len <= md5_struct->total_len)
		md5_struct->data[msg_len] = 0;
    printf("data full 0 OK \n");
	ft_memcpy(md5_struct->data + md5_struct->total_len, &bitlen, 4);
    printf("last memcopy OK \n");
}

