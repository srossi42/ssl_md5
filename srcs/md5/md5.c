/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:06:40 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:23:40 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_init(t_md5_struct *md5_struct, char *str, size_t size)
{
	md5_struct->input = str;
	md5_struct->input_len = size;
	md5_struct->total_len = md5_struct->input_len + 1;
	md5_struct->state[0] = 0x67452301;
	md5_struct->state[1] = 0xefcdab89;
	md5_struct->state[2] = 0x98badcfe;
	md5_struct->state[3] = 0x10325476;
}

void			ft_md5_free(struct s_md5_struct *md5_struct)
{
	if (md5_struct)
	{
		if (md5_struct->data)
			ft_strdel(&md5_struct->data);
	}
}

char			*ft_hash_append_zero(char *hash, uint64_t len)
{
	uint64_t	i;
	char		*tmp;
	char		*hash_def;

	i = 0;
	tmp = ft_strnew(len);
	while (i < len)
	{
		tmp[i] = '0';
		i++;
	}
	hash_def = ft_strjoin(tmp, hash);
	ft_strdel(&tmp);
	return (hash_def);
}

char			*ft_md5(char *str_to_hash, size_t size)
{
	struct s_md5_struct	md5_struct;
	char				*hash;
	char				*hash_def;
	uint64_t			len;

	ft_md5_init(&md5_struct, str_to_hash, size);
	ft_md5_padding(&md5_struct);
	ft_md5_encode(&md5_struct);
	hash = ft_md5_decode(&md5_struct);
	len = 32 - ft_strlen(hash);
	if (len > 0)
	{
		hash_def = ft_hash_append_zero(hash, len);
		ft_strdel(&hash);
		ft_md5_free(&md5_struct);
		return (hash_def);
	}
	ft_md5_free(&md5_struct);
	return (hash);
}
