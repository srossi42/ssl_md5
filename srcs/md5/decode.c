/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:34 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:23:24 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_reverse_words(t_md5_struct *md5_struct)
{
	md5_struct->state[0] = ft_reverse_bits(md5_struct->state[0]);
	md5_struct->state[1] = ft_reverse_bits(md5_struct->state[1]);
	md5_struct->state[2] = ft_reverse_bits(md5_struct->state[2]);
	md5_struct->state[3] = ft_reverse_bits(md5_struct->state[3]);
}

char			*ft_md5_decode(t_md5_struct *md5_struct)
{
	char *res;
	char *tmp;

	ft_md5_reverse_words(md5_struct);
	res = ft_itoa_base_ull(md5_struct->state[0], "0123456789abcdef");
	tmp = ft_itoa_base_ull(md5_struct->state[1], "0123456789abcdef");
	res = ft_strjoin_del(res, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa_base_ull(md5_struct->state[2], "0123456789abcdef");
	res = ft_strjoin_del(res, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa_base_ull(md5_struct->state[3], "0123456789abcdef");
	res = ft_strjoin_del(res, tmp);
	ft_strdel(&tmp);
	return (res);
}
