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

static	void	ft_md5_init(t_md5_struct *md5_struct, char *str_to_hash)
{
	md5_struct->input = ft_strdup(str_to_hash);
	md5_struct->input_len = ft_strlen(str_to_hash);
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

void			ft_md5(char *str_to_hash)
{
	struct s_md5_struct	md5_struct;
	char				*hash;

	ft_md5_init(&md5_struct, str_to_hash);
	ft_md5_padding(&md5_struct);
	ft_md5_encode(&md5_struct);
	hash = ft_md5_decode(&md5_struct);
	//mettre le res dans la structure pour
	//// éviter de malloc à chaque fois une string
	ft_printf("MD5 (\"%s\") = %s\n", md5_struct.input, hash);
	//ft_md5_print_res(&md5_struct);
	ft_md5_free(&md5_struct);
	//return hash;
}
