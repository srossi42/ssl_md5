/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:30:32 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 17:51:01 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha224.h"

void	ft_up_state(t_sha224_struct *sha224_struct, t_sha224_word w, uint32_t k)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = SHA224_H + ft_bsig1(SHA224_E) + ft_ch(SHA224_E, SHA224_F, SHA224_G)
		+ k + w;
	t2 = ft_bsig0(SHA224_A) + ft_maj(SHA224_A, SHA224_B, SHA224_C);
	SHA224_H = SHA224_G;
	SHA224_G = SHA224_F;
	SHA224_F = SHA224_E;
	SHA224_E = SHA224_D + t1;
	SHA224_D = SHA224_C;
	SHA224_C = SHA224_B;
	SHA224_B = SHA224_A;
	SHA224_A = t1 + t2;
}

void	ft_up_hx(t_sha224_struct *sha224_struct)
{
	SHA224_H0 += SHA224_A;
	SHA224_H1 += SHA224_B;
	SHA224_H2 += SHA224_C;
	SHA224_H3 += SHA224_D;
	SHA224_H4 += SHA224_E;
	SHA224_H5 += SHA224_F;
	SHA224_H6 += SHA224_G;
	SHA224_H7 += SHA224_H;
}

void	ft_init_state(t_sha224_struct *sha224_struct)
{
	SHA224_A = SHA224_H0;
	SHA224_B = SHA224_H1;
	SHA224_C = SHA224_H2;
	SHA224_D = SHA224_H3;
	SHA224_E = SHA224_H4;
	SHA224_F = SHA224_H5;
	SHA224_G = SHA224_H6;
	SHA224_H = SHA224_H7;
}

void	ft_construct_w(t_sha224_word w[64], t_sha224_byte words[64])
{
	int	t;
	int	j;

	j = 0;
	t = 0;
	while (t < 16)
	{
		w[t] = (uint32_t)((unsigned char)(words[j + 0]) << 24)
			| (uint32_t)((unsigned char)(words[j + 1]) << 16)
			| (uint32_t)((unsigned char)(words[j + 2]) << 8)
			| (uint32_t)((unsigned char)(words[j + 3]));
		t++;
		j += 4;
	}
	while (t < 64)
	{
		w[t] = w[t - 7] + ft_ssig0(w[t - 15]) + w[t - 16] + ft_ssig1(w[t - 2]);
		t++;
	}
}

void	ft_sha224_encode(t_sha224_struct *sha224_struct)
{
	int				i;
	int				t;
	t_sha224_word	w[64];
	t_sha224_byte	words[64];

	ft_bzero(w, 64 * sizeof(t_sha224_word));
	i = 0;
	sha224_struct->total_len += 8;
	while (i < sha224_struct->total_len - 1)
	{
		ft_bzero(words, 64);
		ft_memcpy(words, sha224_struct->data + i, 64);
		ft_init_state(sha224_struct);
		ft_construct_w(w, words);
		t = 0;
		while (t < 64)
		{
			ft_up_state(sha224_struct, w[t], g_sha224_k[t]);
			t++;
		}
		ft_up_hx(sha224_struct);
		i += 64;
	}
}
