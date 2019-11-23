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
#include "../../includes/ft_sha256.h"

void	ft_up_state(t_sha256_struct *sha256_struct, t_sha256_word w, uint32_t k)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = SHA256_H + ft_bsig1(SHA256_E) + ft_ch(SHA256_E, SHA256_F, SHA256_G)
		+ k + w;
	t2 = ft_bsig0(SHA256_A) + ft_maj(SHA256_A, SHA256_B, SHA256_C);
	SHA256_H = SHA256_G;
	SHA256_G = SHA256_F;
	SHA256_F = SHA256_E;
	SHA256_E = SHA256_D + t1;
	SHA256_D = SHA256_C;
	SHA256_C = SHA256_B;
	SHA256_B = SHA256_A;
	SHA256_A = t1 + t2;
}

void	ft_up_hx(t_sha256_struct *sha256_struct)
{
	SHA256_H0 += SHA256_A;
	SHA256_H1 += SHA256_B;
	SHA256_H2 += SHA256_C;
	SHA256_H3 += SHA256_D;
	SHA256_H4 += SHA256_E;
	SHA256_H5 += SHA256_F;
	SHA256_H6 += SHA256_G;
	SHA256_H7 += SHA256_H;
}

void	ft_init_state(t_sha256_struct *sha256_struct)
{
	SHA256_A = SHA256_H0;
	SHA256_B = SHA256_H1;
	SHA256_C = SHA256_H2;
	SHA256_D = SHA256_H3;
	SHA256_E = SHA256_H4;
	SHA256_F = SHA256_H5;
	SHA256_G = SHA256_H6;
	SHA256_H = SHA256_H7;
}

void	ft_construct_w(t_sha256_word w[64], t_sha256_byte words[64])
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

void	ft_sha256_encode(t_sha256_struct *sha256_struct)
{
	int				i;
	int				t;
	t_sha256_word	w[64];
	t_sha256_byte	words[64];

	ft_bzero(w, 64 * sizeof(t_sha256_word));
	i = 0;
	sha256_struct->total_len += 8;
	while (i < sha256_struct->total_len - 1)
	{
		ft_bzero(words, 64);
		ft_memcpy(words, sha256_struct->data + i, 64);
		ft_init_state(sha256_struct);
		ft_construct_w(w, words);
		t = 0;
		while (t < 64)
		{
			ft_up_state(sha256_struct, w[t], g_sha256_k[t]);
			t++;
		}
		ft_up_hx(sha256_struct);
		i += 64;
	}
}
