//
// Created by Savinien ROSSI on 2019-06-21.
//

#include "../includes/ft_ssl.h"
#include "../includes/ft_md5.h"

#include <stdio.h>

/* Initialisation de l'état (ABCD) et du nb de bits*/

void ft_md5_init (t_md5_state *md5){
    md5->count[0] = 0;
    md5->count[1] = 0;
    md5->state[0] = 0x67452301;
    md5->state[1] = 0xefcdab89;
    md5->state[2] = 0x98badcfe;
    md5->state[3] = 0x10325476;
}


/*
void ft_f(x, y, z){
    (((x) & (y)) | ((~x) & (z)));
}

void ft_g(x, y, z){
    (((x) & (z)) | ((y) & (~z)));
}

void ft_h(x, y, z){
    ((x) ^ (y) ^ (z));
}

void ft_i(x, y, z){
    ((y) ^ ((x) | (~z)));
}
*/
/* ROTATE_LEFT fait une rotation de x de n bits à gauche. */
/*void ft_rotate_left(x, n){
    (((x) << (n)) | ((x) >> (32-(n))));
}*/


static int ft_convert(char *text){
    int len = strlen(text);

    char hex[100], string[50];

    // Convert text to hex.
    for (int i = 0, j = 0; i < len; ++i, j += 2)
        sprintf(hex + j, "%02x", text[i] & 0xff);

    printf("'%s' in hex is %s.\n", text, hex);

    // Convert the hex back to a string.
    len = strlen(hex);
    for (int i = 0, j = 0; j < len; ++i, j += 2) {
        int val[1];
        sscanf(hex + j, "%2x", val);
        string[i] = val[0];
        string[i + 1] = '\0';
    }

    printf("%s as a string is '%s'.\n", hex, string);

    return 0;
}


void ft_md5(char *str_to_hash){
    int msg_len;
    int padding;
    unsigned char *str_pad;
    int total_len;


    ft_printf("ft_md5\n");

    ft_printf("chaine avant padding : %s\n", str_to_hash);
    ft_convert(str_to_hash);
    msg_len = ft_strlen(str_to_hash);

    padding = msg_len;
    while ((padding + msg_len) % 56 != 0)
        padding++;

    total_len = msg_len + padding + 8;

    ft_printf("msg_len : %d\n", msg_len);
    ft_printf("padding : %d\n", padding);
    ft_printf("total len : %d\n", total_len);

    str_pad = (unsigned char*)ft_strnew(msg_len + padding + 8);
    ft_memcpy(str_pad, str_to_hash, msg_len);
    str_pad[msg_len] = (char)128;
    while (++msg_len <= (total_len - 8))
    {
        str_pad[msg_len] = 0;
        ft_printf("msg len : %d\n", msg_len);
    }

    int i = 0;
    ft_printf("msg original en b :\n");
    while (i < msg_len)
    {
        ft_printf("%b ", (char)str_to_hash[i]);
        if ((i + 1) % 16 == 0)
            ft_printf("\n");
        i++;
    }
    ft_printf("\n");
    i = 0;
    ft_printf("msg padded en b :\n");
    while (i < total_len)
    {
        ft_printf("%b ", (char)str_pad[i]);
        if ((i + 1) % 16 == 0)
            ft_printf("\n");
        i++;
    }
    ft_printf("\n");

/*    while (i < msg_len / 8){
        ft_printf("char : %c\n", str_to_hash[i]);
        str_pad[i] = str_to_hash[i];
        i++;
    }*/
    ft_printf("chaine apres padding : %s\n", str_to_hash);
    ft_printf("chaineb apre padding : %s\n", str_pad);
    //ft_printf("msgLen (bits) = %d\n", msg_len);
    //ft_printf("msgLen (bits) = %d\n", msg_len);
    //ft_printf("msgLen (bits) = %d\n", msg_len);
}
