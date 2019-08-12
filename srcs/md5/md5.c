/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:06:40 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 15:08:22 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_init(t_md5_struct *md5_struct, char *str_to_hash, size_t size)
{
	md5_struct->input = ft_strdup(str_to_hash);
	md5_struct->input_len = size;
	printf("input len : %lld\n", md5_struct->input_len);
	md5_struct->total_len = md5_struct->input_len + 1;
	MD5_H0 = 0x67452301;
	MD5_H1 = 0xefcdab89;
	MD5_H2 = 0x98badcfe;
	MD5_H3 = 0x10325476;
}

void			ft_md5_free(struct s_md5_struct *md5_struct)
{
	if (md5_struct->input)
		ft_strdel(&md5_struct->input);
}

char			*ft_md5(char *str_to_hash, size_t size)
{
	struct s_md5_struct	md5_struct;
	char				*hash;
    uint64_t             len;
    uint64_t             i;
    char                *tmp;

    ft_printf("MD5 START\n");
	ft_md5_init(&md5_struct, str_to_hash, size);

	ft_md5_padding(&md5_struct);

	ft_md5_encode(&md5_struct);
	hash = ft_md5_decode(&md5_struct);
	//mettre le res dans la structure pour
	//// éviter de malloc à chaque fois une string
//	ft_printf("MD5 (\"%s\") = %s\n", md5_struct.input, hash);
	//ft_md5_print_res(&md5_struct);
	ft_md5_free(&md5_struct);
	len = 32 - ft_strlen(hash);
	ft_printf("len : %d\n", len);
    i = 0;
	if (len > 0)
    {
        tmp = ft_strnew(len);
        while (i < len)
        {
            tmp[i] = '0';
            i++;
        }
        ft_printf("tmp : %s\n", tmp);
        hash = ft_strjoin(tmp, hash);
        ft_strdel(&tmp);
    }
	return hash;
}
