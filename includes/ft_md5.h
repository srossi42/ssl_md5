/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:34:35 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:40:03 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# define MD5_A		    md5_struct->abcdfg[0]
# define MD5_B		    md5_struct->abcdfg[1]
# define MD5_C		    md5_struct->abcdfg[2]
# define MD5_D		    md5_struct->abcdfg[3]
# define MD5_F		    md5_struct->abcdfg[4]
# define MD5_G		    md5_struct->abcdfg[5]

# define MD5_H0		    md5_struct->state[0]
# define MD5_H1		    md5_struct->state[1]
# define MD5_H2		    md5_struct->state[2]
# define MD5_H3		    md5_struct->state[3]

static uint32_t	g_md5_r[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static uint32_t	g_md5_k[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

typedef unsigned char   md5_byte_t; /* 8-bit byte */
typedef unsigned int    md5_word_t; /* 32-bit word */

/* Contexte MD5. */
typedef struct      s_md5_struct{

    md5_word_t      state[4]; /* digest buffer (ABCD) */
    md5_word_t      abcdfg[6];
    md5_word_t      count[2]; /* message length in bits, lsw first */
    md5_byte_t      buffer[64]; /* mémoire tampon d'entrée */
    char            *input;
    unsigned char   *data;
    size_t          input_len;
    size_t          total_len;

}                   t_md5_struct;



void    ft_md5_init(t_md5_struct *md5_struct, char *str_to_hash);
void    ft_md5_free(t_md5_struct *md5_struct);
void    ft_md5(char *str_to_hash);
void    ft_md5_encode(t_md5_struct *md5_struct);
void    ft_md5_padding(t_md5_struct *md5_struct);
void    ft_md5_append_len(t_md5_struct *md5_struct);

#endif
