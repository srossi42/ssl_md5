//
// Created by Savinien ROSSI on 2019-06-21.
//

#include "../includes/ft_ssl.h"
#include "../includes/ft_sha256.h"

#include <stdio.h>

uint32_t	ft_rotate_left(uint32_t x, uint32_t n)
{
    return ((x << n) | (x >> (32 - n)));
}

uint32_t	ft_rotate_right(uint32_t x, uint32_t n)
{
    return ((x >> n) | (x << (32 - n)));
}

uint32_t    ft_ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ ((~x) & z);
}

uint32_t    ft_maj(uint32_t x, uint32_t y, uint32_t z){
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t    ft_bsig0(uint32_t x){
    return ft_rotate_right(x, 2) ^ ft_rotate_right(x, 13) ^ ft_rotate_right(x, 22);
}

uint32_t    ft_bsig1(uint32_t x){
    return ft_rotate_right(x, 6) ^ ft_rotate_right(x, 11) ^ ft_rotate_right(x, 25);
}

uint32_t    ft_ssig0(uint32_t x){
    return ft_rotate_right(x, 7) ^ ft_rotate_right(x, 18) ^ (x >> 3);
}

uint32_t    ft_ssig1(uint32_t x){
    return ft_rotate_right(x, 17) ^ ft_rotate_right(x, 19) ^ (x >> 10);
}


uint32_t ft_reverse_bits(uint32_t value){
    return (value & 0xFF000000)>>24| (value & 0x00FF0000)>>8
           | (value & 0x0000FF00)<<8 | (value & 0x000000FF)<<24;
}

void ft_sha256_init(t_sha256_struct *sha256_struct, char *str_to_hash){
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

void ft_sha256_free(t_sha256_struct *sha256_struct) {
    if (sha256_struct->data){
        ft_bzero(sha256_struct->data, sha256_struct->total_len);
        free(sha256_struct->data);
    }
    if (sha256_struct->input)
        ft_strdel(&sha256_struct->input);
}

void ft_sha256_padding(t_sha256_struct *sha256_struct) {
    size_t          bitlen;
    int             msg_len;
    int             padding;

    padding = 0;
    msg_len = sha256_struct->input_len;
    bitlen = sha256_struct->input_len << 3;
    sha256_struct->count[0] = sha256_struct->input_len >> 29;
    sha256_struct->count[0] = bitlen;
    while (((sha256_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
        padding++;
    sha256_struct->total_len += padding;
    sha256_struct->data = (unsigned char *) ft_strnew(sha256_struct->total_len + 8);
    ft_memcpy(sha256_struct->data, sha256_struct->input, sha256_struct->input_len);
    sha256_struct->data[msg_len] = (unsigned char) 128;
    while (++msg_len <= sha256_struct->total_len)
        sha256_struct->data[msg_len] = 0;
    sha256_struct->data[sha256_struct->total_len] = (bitlen >> 56) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 1] = (bitlen >> 48) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 2] = (bitlen >> 40) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 3] = (bitlen >> 32) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 4] = (bitlen >> 24) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 5] = (bitlen >> 16) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 6] = (bitlen >> 8) & 0xFF;
    sha256_struct->data[sha256_struct->total_len + 7] = (bitlen) & 0xFF;
}

void ft_init_abcdefgh(t_sha256_struct *sha256_struct){
    SHA256_A = SHA256_H0;
    SHA256_B = SHA256_H1;
    SHA256_C = SHA256_H2;
    SHA256_D = SHA256_H3;
    SHA256_E = SHA256_H4;
    SHA256_F = SHA256_H5;
    SHA256_G = SHA256_H6;
    SHA256_H = SHA256_H7;
}

void ft_update_abcdefgh(t_sha256_struct *sha256_struct, sha256_word_t w, uint32_t k){
    uint32_t    t1;
    uint32_t    t2;

    t1 = SHA256_H + ft_bsig1(SHA256_E) + ft_ch(SHA256_E, SHA256_F, SHA256_G) + k + w;
    t2 = ft_bsig0(SHA256_A) + ft_maj(SHA256_A, SHA256_B, SHA256_C);
    SHA256_H = SHA256_G;
    SHA256_G = SHA256_F;
    SHA256_F = SHA256_E;
    SHA256_E = SHA256_D + t1;
    SHA256_D = SHA256_C;
    SHA256_C = SHA256_B;
    SHA256_B = SHA256_B;
    SHA256_A = t1 + t2;

}

void ft_update_hx(t_sha256_struct *sha256_struct){
    SHA256_H0 += SHA256_A;
    SHA256_H1 += SHA256_B;
    SHA256_H2 += SHA256_C;
    SHA256_H3 += SHA256_D;
    SHA256_H4 += SHA256_E;
    SHA256_H5 += SHA256_F;
    SHA256_H6 += SHA256_G;
    SHA256_H7 += SHA256_H;
}

void ft_sha256_encode(t_sha256_struct *sha256_struct) {
    int             i;
    int             j;
    int             t;
    sha256_word_t   w[64];
    sha256_byte_t   words[64];

    ft_bzero(w, 64 * sizeof(sha256_word_t));
    i = 0;
    j = 0;
    sha256_struct->total_len += 8;
    while (i < sha256_struct->total_len - 1) {
        ft_bzero(words, 64);
        ft_memcpy(words, sha256_struct->data + i, 64);
//        printf("---------------------\n");
//        t = 0;
//        while (t < 64) {
//            printf("words[%d] : %x\n", t, words[t]);
//            t++;
//        }
        ft_init_abcdefgh(sha256_struct);
        t = 0;
        while (t < 16){
            w[t] = (uint32_t)((unsigned char)(words[j + 0]) << 24)
            | (uint32_t)((unsigned char)(words[j + 1]) << 16)
            | (uint32_t)((unsigned char)(words[j + 2]) << 8)
            | (uint32_t)((unsigned char)(words[j + 3]));
            t++;
            j += 4;
        }
        while (t < 64){
            w[t] = w[t - 7] + ft_ssig0(w[t - 15]) + w[t - 16] + ft_ssig1(w[t - 2]);
            t++;
        }
        t = 0;
        printf("---------------------\n");
        while (t < 64) {
            printf("w[%d] : %x\n", t, w[t]);
            t++;
        }
        t = 0;
        while (t < 64){
            ft_update_abcdefgh(sha256_struct, w[t], g_sha256_k[t]);
            t++;
        }
        ft_update_hx(sha256_struct);
        i += 64;
    }
}


void ft_reverse_words(t_sha256_struct *sha256_struct){
    SHA256_H0 = ft_reverse_bits(SHA256_H0);
    SHA256_H1 = ft_reverse_bits(SHA256_H1);
    SHA256_H2 = ft_reverse_bits(SHA256_H2);
    SHA256_H3 = ft_reverse_bits(SHA256_H3);
    SHA256_H4 = ft_reverse_bits(SHA256_H4);
    SHA256_H5 = ft_reverse_bits(SHA256_H5);
    SHA256_H6 = ft_reverse_bits(SHA256_H6);
    SHA256_H7 = ft_reverse_bits(SHA256_H7);
}

char *ft_sha256_decode(t_sha256_struct *sha256_struct){
    char *res;

    ft_reverse_words(sha256_struct);
    res = ft_itoa_base_ull(SHA256_H0, "0123456789abcdef");
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H1, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H2, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H3, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H4, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H5, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H6, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H7, "0123456789abcdef"));
    return res;
}


void    ft_sha256(char *str_to_hash){
    struct s_sha256_struct sha256_struct;
    char                *hash;

    ft_sha256_init(&sha256_struct, str_to_hash);
    ft_sha256_padding(&sha256_struct);
    ft_sha256_encode(&sha256_struct);
    hash = ft_sha256_decode(&sha256_struct);
    //mettre le res dans la structure pour éviter de malloc à chaque fois une string
    printf("sha256 (\"%s\") = %s\n", sha256_struct.input, hash);
    //ft_sha256_print_res(&sha256_struct);
    ft_sha256_free(&sha256_struct);
    //return hash;
}