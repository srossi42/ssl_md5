/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:30:32 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:21:26 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha224.h"

void	ft_sha224_up_state(t_sha224_struct *sha224_struct, t_sha224_word w,
		uint32_t k)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = sha224_struct->abcdefgh[7]
		+ ft_sha224_bsig1(sha224_struct->abcdefgh[4])
		+ ft_sha224_ch(sha224_struct->abcdefgh[4],
				sha224_struct->abcdefgh[5], sha224_struct->abcdefgh[6]) + k + w;
	t2 = ft_sha224_bsig0(sha224_struct->abcdefgh[0])
		+ ft_sha224_maj(sha224_struct->abcdefgh[0],
				sha224_struct->abcdefgh[1], sha224_struct->abcdefgh[2]);
	sha224_struct->abcdefgh[7] = sha224_struct->abcdefgh[6];
	sha224_struct->abcdefgh[6] = sha224_struct->abcdefgh[5];
	sha224_struct->abcdefgh[5] = sha224_struct->abcdefgh[4];
	sha224_struct->abcdefgh[4] = sha224_struct->abcdefgh[3] + t1;
	sha224_struct->abcdefgh[3] = sha224_struct->abcdefgh[2];
	sha224_struct->abcdefgh[2] = sha224_struct->abcdefgh[1];
	sha224_struct->abcdefgh[1] = sha224_struct->abcdefgh[0];
	sha224_struct->abcdefgh[0] = t1 + t2;
}

void	ft_sha224_up_hx(t_sha224_struct *sha224_struct)
{
	sha224_struct->state[0] += sha224_struct->abcdefgh[0];
	sha224_struct->state[1] += sha224_struct->abcdefgh[1];
	sha224_struct->state[2] += sha224_struct->abcdefgh[2];
	sha224_struct->state[3] += sha224_struct->abcdefgh[3];
	sha224_struct->state[4] += sha224_struct->abcdefgh[4];
	sha224_struct->state[5] += sha224_struct->abcdefgh[5];
	sha224_struct->state[6] += sha224_struct->abcdefgh[6];
	sha224_struct->state[7] += sha224_struct->abcdefgh[7];
}

void	ft_sha224_init_state(t_sha224_struct *sha224_struct)
{
	sha224_struct->abcdefgh[0] = sha224_struct->state[0];
	sha224_struct->abcdefgh[1] = sha224_struct->state[1];
	sha224_struct->abcdefgh[2] = sha224_struct->state[2];
	sha224_struct->abcdefgh[3] = sha224_struct->state[3];
	sha224_struct->abcdefgh[4] = sha224_struct->state[4];
	sha224_struct->abcdefgh[5] = sha224_struct->state[5];
	sha224_struct->abcdefgh[6] = sha224_struct->state[6];
	sha224_struct->abcdefgh[7] = sha224_struct->state[7];
}

void	ft_sha224_construct_w(t_sha224_word w[64], t_sha224_byte words[64])
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
		w[t] = w[t - 7] + ft_sha224_ssig0(w[t - 15]) + w[t - 16]
			+ ft_sha224_ssig1(w[t - 2]);
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
		ft_sha224_init_state(sha224_struct);
		ft_sha224_construct_w(w, words);
		t = 0;
		while (t < 64)
		{
			ft_sha224_up_state(sha224_struct, w[t], g_sha224_k[t]);
			t++;
		}
		ft_sha224_up_hx(sha224_struct);
		i += 64;
	}
}
