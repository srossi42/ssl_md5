//
// Created by Savinien ROSSI on 2019-06-21.
//

#ifndef FT_SHA256_H
# define FT_SHA256_H

# define SHA256_A		    sha256_struct->abcdefgh[0]
# define SHA256_B		    sha256_struct->abcdefgh[1]
# define SHA256_C		    sha256_struct->abcdefgh[2]
# define SHA256_D		    sha256_struct->abcdefgh[3]
# define SHA256_E		    sha256_struct->abcdefgh[4]
# define SHA256_F		    sha256_struct->abcdefgh[5]
# define SHA256_G		    sha256_struct->abcdefgh[6]
# define SHA256_H		    sha256_struct->abcdefgh[7]

# define SHA256_H0		    sha256_struct->state[0]
# define SHA256_H1		    sha256_struct->state[1]
# define SHA256_H2		    sha256_struct->state[2]
# define SHA256_H3		    sha256_struct->state[3]
# define SHA256_H4		    sha256_struct->state[4]
# define SHA256_H5		    sha256_struct->state[5]
# define SHA256_H6		    sha256_struct->state[6]
# define SHA256_H7		    sha256_struct->state[7]


static uint32_t	g_sha256_k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
        0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
        0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
        0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
        0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
        0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

typedef unsigned char   sha256_byte_t; /* 8-bit byte */
typedef unsigned int    sha256_word_t; /* 32-bit word */

/* Contexte SHA256. */
typedef struct      s_sha256_struct{

    sha256_word_t      state[8]; /* digest buffer (ABCD) */
    sha256_word_t      abcdefgh[8];
    sha256_word_t      count[2]; /* message length in bits, lsw first */
    sha256_byte_t      buffer[64]; /* mémoire tampon d'entrée */
    char            *input;
    unsigned char   *data;
    uint64_t          input_len;
    uint64_t          total_len;

}                   t_sha256_struct;



//void        ft_sha256_init(t_sha256_struct *sha256_struct, char *str_to_hash);
//void        ft_sha256_free(t_sha256_struct *sha256_struct);
//void        ft_sha256(char *str_to_hash);
void        ft_sha256_encode(t_sha256_struct *sha256_struct);
char        *ft_sha256_decode(t_sha256_struct *sha256_struct);
void        ft_sha256_padding(t_sha256_struct *sha256_struct);
void        ft_sha256_append_len(t_sha256_struct *sha256_struct);
uint32_t    ft_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t    ft_maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t    ft_bsig0(uint32_t x);
uint32_t    ft_bsig1(uint32_t x);
uint32_t    ft_ssig0(uint32_t x);
uint32_t    ft_ssig1(uint32_t x);

#endif
