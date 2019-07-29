//
// Created by Savinien ROSSI on 2019-06-21.
//

#include "../includes/ft_ssl.h"
#include "../includes/ft_md5.h"

#include <stdio.h>

uint32_t	ft_rotate_left(uint32_t x, uint32_t n)
{
    return ((x << n) | (x >> (32 - n)));
}

uint32_t ft_reverse_bits(uint32_t value){
    return (value & 0xFF000000)>>24| (value & 0x00FF0000)>>8
    | (value & 0x0000FF00)<<8 | (value & 0x000000FF)<<24;
}

void ft_md5_init(t_md5_struct *md5_struct, char *str_to_hash){
    md5_struct->input = ft_strdup(str_to_hash);
    md5_struct->input_len = ft_strlen(str_to_hash);
    md5_struct->total_len = md5_struct->input_len + 1;

    md5_struct->state[0] = 0x67452301;
    md5_struct->state[1] = 0xefcdab89;
    md5_struct->state[2] = 0x98badcfe;
    md5_struct->state[3] = 0x10325476;
}

void ft_md5_free(t_md5_struct *md5_struct) {
    if (md5_struct->data){
        ft_bzero(md5_struct->data, md5_struct->total_len);
        free(md5_struct->data);
    }
    if (md5_struct->input)
        ft_strdel(&md5_struct->input);
}

void ft_md5_padding(t_md5_struct *md5_struct) {
    unsigned int    bitlen;
    int             msg_len;
    int             padding;

    padding = 0;
    msg_len = md5_struct->input_len;
    bitlen = md5_struct->input_len<<3;
    md5_struct->count[1] = md5_struct->input_len >> 29;
    md5_struct->count[0] = bitlen;
    while (((md5_struct->input_len + padding + 1) * 8 - 448) % 512 != 0)
        padding++;
    md5_struct->total_len += padding;
    md5_struct->data = (unsigned char *) ft_strnew(md5_struct->total_len + 8);
    ft_memcpy(md5_struct->data, md5_struct->input, md5_struct->input_len);
    md5_struct->data[msg_len] = (unsigned char) 128;
    while (++msg_len <= md5_struct->total_len)
        md5_struct->data[msg_len] = 0;
    ft_memcpy(md5_struct->data + md5_struct->total_len, &bitlen, 4);
}

void ft_init_abcd(t_md5_struct *md5_struct){
    MD5_A = MD5_H0;
    MD5_B = MD5_H1;
    MD5_C = MD5_H2;
    MD5_D = MD5_H3;
}

void ft_update_abcd(t_md5_struct *md5_struct, md5_byte_t word[4], int j){
    int         tmp;
    uint32_t    w_g;

    w_g = (uint32_t)word[0] | (uint32_t)(word[1]<<8) | (uint32_t)(word[2]<<16) | (uint32_t)(word[3]<<24);
    tmp = MD5_D;
    MD5_D = MD5_C;
    MD5_C = MD5_B;
    MD5_B += ft_rotate_left(MD5_A + MD5_F + g_md5_k[j] + w_g, g_md5_r[j]);
    MD5_A = tmp;
}

void ft_update_hx(t_md5_struct *md5_struct){
    MD5_H0 += MD5_A;
    MD5_H1 += MD5_B;
    MD5_H2 += MD5_C;
    MD5_H3 += MD5_D;
}

void ft_get_fg(t_md5_struct *md5_struct, int j){
    if (j < 16) {
        MD5_F = (MD5_B & MD5_C) | ((~MD5_B) & MD5_D);
        MD5_G = j;
    } else if (j < 32) {
        MD5_F = (MD5_D & MD5_B) | ((~MD5_D) & MD5_C);
        MD5_G = (5 * j + 1) % 16;
    } else if (j < 48) {
        MD5_F = MD5_B ^ MD5_C ^ MD5_D;
        MD5_G = (3 * j + 5) % 16;
    } else if (j < 64) {
        MD5_F = MD5_C ^ (MD5_B | (~MD5_D));
        MD5_G = (7 * j) % 16;
    }
}

void ft_md5_encode(t_md5_struct *md5_struct) {
    int         i;
    int         j;
    md5_byte_t  word[4];
    md5_byte_t  words[64];

    ft_bzero(word, 4);
    //i = 1;
    i = 0;
    md5_struct->total_len += 8;
    //while (i < md5_struct->total_len) {
    while (i < md5_struct->total_len - 1) {
        ft_bzero(words, 64);
        //i--;
        ft_memcpy(words, md5_struct->data + i, 64);
        //if (i > 0)
          //  i++;
        ft_init_abcd(md5_struct);
        j = 0;
        while (j < 64) {
            ft_get_fg(md5_struct, j);
            ft_memcpy(word, words + MD5_G * 4, 4);
            ft_update_abcd(md5_struct, word, j++);
        }
        ft_update_hx(md5_struct);
        i += 64;
    }
}


void ft_reverse_words(t_md5_struct *md5_struct){
    MD5_H0 = ft_reverse_bits(MD5_H0);
    MD5_H1 = ft_reverse_bits(MD5_H1);
    MD5_H2 = ft_reverse_bits(MD5_H2);
    MD5_H3 = ft_reverse_bits(MD5_H3);
}

char *ft_md5_decode(t_md5_struct *md5_struct){
    char *res;

    ft_reverse_words(md5_struct);
    res = ft_itoa_base_ull(MD5_H0, "0123456789abcdef");
    res = ft_strjoin(res, ft_itoa_base_ull(MD5_H1, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(MD5_H2, "0123456789abcdef"));
    res = ft_strjoin(res, ft_itoa_base_ull(MD5_H3, "0123456789abcdef"));
    return res;
}


void ft_md5(char *str_to_hash){
    struct s_md5_struct md5_struct;
    char *res;

    ft_md5_init(&md5_struct, str_to_hash);
    ft_md5_padding(&md5_struct);
    ft_md5_encode(&md5_struct);
    res = ft_md5_decode(&md5_struct);
    //mettre le res dans la structure pour éviter de malloc à chaque fois une string
    printf("MD5 (\"%s\") = %s\n", md5_struct.input, res);
    //ft_md5_print_res(&md5_struct);
    ft_md5_free(&md5_struct);
    //return res;
}