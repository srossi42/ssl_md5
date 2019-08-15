/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:52:42 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 15:00:48 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_init_abcd(t_md5_struct *md5_struct)
{
	MD5_A = MD5_H0;
	MD5_B = MD5_H1;
	MD5_C = MD5_H2;
	MD5_D = MD5_H3;
}

static	void	ft_md5_update_abcd(t_md5_struct *md5_struct, md5_byte_t word[4], int j)
{
	int			tmp;
	uint32_t	w_g;
//
//    ft_printf("word[0] : %X\n", word[0]);
//    ft_printf("word[1] : %X\n", word[1]);
//    ft_printf("word[2] : %X\n", word[2]);
//    ft_printf("word[3] : %X\n", word[3]);
//
//    ft_printf("\nword[0] : %c\n", word[0]);
//    ft_printf("word[1] : %c\n", word[1]);
//    ft_printf("word[2] : %c\n", word[2]);
//    ft_printf("word[3] : %c\n", word[3]);

	w_g = (uint32_t)word[0] | (uint32_t)(word[1] << 8)
		| (uint32_t)(word[2] << 16) | (uint32_t)(word[3] << 24);


	tmp = MD5_D;
	MD5_D = MD5_C;
	MD5_C = MD5_B;
	MD5_B += ft_rotate_left(MD5_A + MD5_F + g_md5_k[j] + w_g, g_md5_r[j]);
	MD5_A = tmp;
//
//
//        printf("---------------------------\n");
//        ft_printf("MD5_A : %X\n", MD5_A);
//        ft_printf("MD5_B : %X\n", MD5_B);
//        ft_printf("MD5_C : %X\n", MD5_C);
//        ft_printf("MD5_D : %X\n", MD5_D);
//
//        ft_printf("\nMD5_F : %X\n", MD5_F);
//        ft_printf("MD5_G : %X\n", MD5_G);
//        ft_printf("g_md5_k[%lld] : %X\n", j, g_md5_k[j]);
//        ft_printf("g_md5_r[%lld] : %X\n", j, g_md5_r[j]);
//        ft_printf("w_g : %X\n", w_g);
//        ft_printf("res = %X\n", (MD5_A + MD5_F + g_md5_k[j] + w_g));
//        printf("---------------------------\n");
}

static	void	ft_md5_update_hx(t_md5_struct *md5_struct)
{
	MD5_H0 += MD5_A;
	MD5_H1 += MD5_B;
	MD5_H2 += MD5_C;
	MD5_H3 += MD5_D;
}

static	void	ft_md5_get_fg(t_md5_struct *md5_struct, int j)
{
	if (j < 16)
	{
		MD5_F = (MD5_B & MD5_C) | ((~MD5_B) & MD5_D);
		MD5_G = j;
	}
	else if (j < 32)
	{
		MD5_F = (MD5_D & MD5_B) | ((~MD5_D) & MD5_C);
		MD5_G = (5 * j + 1) % 16;
	}
	else if (j < 48)
	{
		MD5_F = MD5_B ^ MD5_C ^ MD5_D;
		MD5_G = (3 * j + 5) % 16;
	}
	else if (j < 64)
	{
		MD5_F = MD5_C ^ (MD5_B | (~MD5_D));
		MD5_G = (7 * j) % 16;
	}
}

void			ft_md5_encode(t_md5_struct *md5_struct)
{
	uint64_t	i;
    uint64_t	j;
	md5_byte_t	word[4];
	md5_byte_t	words[64];

	ft_bzero(word, 4);
	i = 0;
	md5_struct->total_len += 8;

	printf("md5_struct->total_len : %lld\n", md5_struct->total_len);
//    exit(0);

	while (i < md5_struct->total_len)
	{
//	    printf("*** i : %lld ***\n", i);

		ft_bzero(words, 64);
		ft_memcpy(words, md5_struct->data + i, 64);
		ft_md5_init_abcd(md5_struct);
		j = 0;
        if (i > 2152726428){
            printf("*** i : %lld ***\n", i);
            printf("---------------------------\n");
            ft_printf("MD5_H0 : %X\n", MD5_H0);
            ft_printf("MD5_H1 : %X\n", MD5_H1);
            ft_printf("MD5_H2 : %X\n", MD5_H2);
            ft_printf("MD5_H3 : %X\n\n", MD5_H3);
            ft_printf("MD5_A : %X\n", MD5_A);
            ft_printf("MD5_B : %X\n", MD5_B);
            ft_printf("MD5_C : %X\n", MD5_C);
            ft_printf("MD5_D : %X\n", MD5_D);

            printf("---------------------------\n");
        }

        while (j < 64)
		{
			ft_md5_get_fg(md5_struct, j);
			ft_memcpy(word, words + MD5_G * 4, 4);
			if (i > 2152726428 && j > 60){
                ft_printf("MD5_F : %X\n", MD5_F);
                ft_printf("MD5_G : %X\n", MD5_G);
			}
			ft_md5_update_abcd(md5_struct, word, j++);

		}

		ft_md5_update_hx(md5_struct);
		i += 64;
		//i s'arrete a 2152726528 + 64
//		if (i > 2152726592)
//		    exit(0);
	}


    printf("---------FINAL PRESQUE------------\n");
    ft_printf("MD5_F : %X\n", MD5_F);
    ft_printf("MD5_G : %X\n", MD5_G);

    ft_printf("MD5_H0 : %X\n", MD5_H0);
    ft_printf("MD5_H1 : %X\n", MD5_H1);
    ft_printf("MD5_H2 : %X\n", MD5_H2);
    ft_printf("MD5_H3 : %X\n\n", MD5_H3);
    ft_printf("MD5_A : %X\n", MD5_A);
    ft_printf("MD5_B : %X\n", MD5_B);
    ft_printf("MD5_C : %X\n", MD5_C);
    ft_printf("MD5_D : %X\n", MD5_D);
    printf("---------------------------\n");


    printf("i : %lld\n", i-64);
}
