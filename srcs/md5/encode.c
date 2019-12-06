/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:52:42 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:25:30 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_init_abcd(t_md5_struct *md5_struct)
{
	md5_struct->abcdfg[0] = md5_struct->state[0];
	md5_struct->abcdfg[1] = md5_struct->state[1];
	md5_struct->abcdfg[2] = md5_struct->state[2];
	md5_struct->abcdfg[3] = md5_struct->state[3];
}

static	void	ft_md5_update_abcd(t_md5_struct *md5_struct,
		t_md5_byte word[4], int j, uint64_t i)
{
	int			tmp;
	uint32_t	w_g;

	w_g = (uint32_t)((uint32_t)word[0] | (uint32_t)(word[1] << 8)
			| (uint32_t)(word[2] << 16) | (uint32_t)(word[3] << 24));
	tmp = md5_struct->abcdfg[3];
	md5_struct->abcdfg[3] = md5_struct->abcdfg[2];
	md5_struct->abcdfg[2] = md5_struct->abcdfg[1];
	md5_struct->abcdfg[1] += ft_rotate_left(md5_struct->abcdfg[0]
			+ md5_struct->abcdfg[4] + g_md5_k[j] + w_g, g_md5_r[j]);
	md5_struct->abcdfg[0] = tmp;
}

static	void	ft_md5_update_hx(t_md5_struct *md5_struct)
{
	md5_struct->state[0] += md5_struct->abcdfg[0];
	md5_struct->state[1] += md5_struct->abcdfg[1];
	md5_struct->state[2] += md5_struct->abcdfg[2];
	md5_struct->state[3] += md5_struct->abcdfg[3];
}

static	void	ft_md5_get_fg(t_md5_struct *md5_struct, int j)
{
	if (j < 16)
	{
		md5_struct->abcdfg[4] = (md5_struct->abcdfg[1]
				& md5_struct->abcdfg[2]) | ((~md5_struct->abcdfg[1])
					& md5_struct->abcdfg[3]);
		md5_struct->abcdfg[5] = j;
	}
	else if (j < 32)
	{
		md5_struct->abcdfg[4] = (md5_struct->abcdfg[3]
				& md5_struct->abcdfg[1]) | ((~md5_struct->abcdfg[3])
					& md5_struct->abcdfg[2]);
		md5_struct->abcdfg[5] = (5 * j + 1) % 16;
	}
	else if (j < 48)
	{
		md5_struct->abcdfg[4] = md5_struct->abcdfg[1]
			^ md5_struct->abcdfg[2] ^ md5_struct->abcdfg[3];
		md5_struct->abcdfg[5] = (3 * j + 5) % 16;
	}
	else if (j < 64)
	{
		md5_struct->abcdfg[4] = md5_struct->abcdfg[2]
			^ (md5_struct->abcdfg[1] | (~md5_struct->abcdfg[3]));
		md5_struct->abcdfg[5] = (7 * j) % 16;
	}
}

void			ft_md5_encode(t_md5_struct *md5_struct)
{
	uint64_t	i;
	uint64_t	j;
	t_md5_byte	word[4];
	t_md5_byte	words[64];

	ft_bzero(word, 4);
	i = 0;
	md5_struct->total_len += 8;
	while (i < md5_struct->total_len)
	{
		ft_bzero(words, 64);
		ft_memcpy(words, md5_struct->data + i, 64);
		ft_md5_init_abcd(md5_struct);
		j = 0;
		while (j < 64)
		{
			ft_md5_get_fg(md5_struct, j);
			ft_memcpy(word, words + md5_struct->abcdfg[5] * 4, 4);
			ft_md5_update_abcd(md5_struct, word, j, i);
			j++;
		}
		ft_md5_update_hx(md5_struct);
		i += 64;
	}
}
