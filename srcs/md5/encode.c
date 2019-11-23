/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:52:42 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 17:50:09 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_init_abcd(t_md5_struct *md5_struct)
{
	MD5_A = MD5_H0;
	MD5_B = MD5_H1;
	MD5_C = MD5_H2;
	MD5_D = MD5_H3;
}

static	void	ft_md5_update_abcd(t_md5_struct *md5_struct,
		t_md5_byte word[4], int j, uint64_t i)
{
	int			tmp;
	uint32_t	w_g;

	w_g = (uint32_t)((uint32_t)word[0] | (uint32_t)(word[1] << 8) |
			(uint32_t)(word[2] << 16) | (uint32_t)(word[3] << 24));
	tmp = MD5_D;
	MD5_D = MD5_C;
	MD5_C = MD5_B;
	MD5_B += ft_rotate_left(MD5_A + MD5_F + g_md5_k[j] + w_g, g_md5_r[j]);
	MD5_A = tmp;
}

static	void	ft_md5_update_hx(t_md5_struct *md5_struct)
{
	MD5_H0 += MD5_A;
	MD5_H1 += MD5_B;
	MD5_H2 += MD5_C;
	MD5_H3 += MD5_D;
}

static	void	ft_md5_get_fg(t_md5_struct *md5_struct, int j)
{
	if (j < 16)
	{
		MD5_F = (MD5_B & MD5_C) | ((~MD5_B) & MD5_D);
		MD5_G = j;
	}
	else if (j < 32)
	{
		MD5_F = (MD5_D & MD5_B) | ((~MD5_D) & MD5_C);
		MD5_G = (5 * j + 1) % 16;
	}
	else if (j < 48)
	{
		MD5_F = MD5_B ^ MD5_C ^ MD5_D;
		MD5_G = (3 * j + 5) % 16;
	}
	else if (j < 64)
	{
		MD5_F = MD5_C ^ (MD5_B | (~MD5_D));
		MD5_G = (7 * j) % 16;
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
			ft_memcpy(word, words + MD5_G * 4, 4);
			ft_md5_update_abcd(md5_struct, word, j, i);
			j++;
		}
		ft_md5_update_hx(md5_struct);
		i += 64;
	}
}
