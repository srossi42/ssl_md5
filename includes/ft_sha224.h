/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:35:44 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 17:41:54 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA224_H
# define FT_SHA224_H

static	uint32_t		g_sha224_k[64] = {
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

typedef unsigned char	t_sha224_byte;
typedef unsigned int	t_sha224_word;
typedef struct			s_sha224_struct
{
	t_sha224_word		state[8];
	t_sha224_word		abcdefgh[8];
	t_sha224_word		count[2];
	t_sha224_byte		buffer[64];
	char				*input;
	unsigned char		*data;
	uint64_t			input_len;
	uint64_t			total_len;
}						t_sha224_struct;

void					ft_sha224_encode(t_sha224_struct *sha224_struct);
char					*ft_sha224_decode(t_sha224_struct *sha224_struct);
void					ft_sha224_padding(t_sha224_struct *sha224_struct);
void					ft_sha224_append_len(t_sha224_struct *sha224_struct);
uint32_t				ft_sha224_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t				ft_sha224_maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t				ft_sha224_bsig0(uint32_t x);
uint32_t				ft_sha224_bsig1(uint32_t x);
uint32_t				ft_sha224_ssig0(uint32_t x);
uint32_t				ft_sha224_ssig1(uint32_t x);

#endif
