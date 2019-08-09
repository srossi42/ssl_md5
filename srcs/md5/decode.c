/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:34 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 14:50:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_md5.h"

static	void	ft_md5_reverse_words(t_md5_struct *md5_struct)
{
	MD5_H0 = ft_reverse_bits(MD5_H0);
	MD5_H1 = ft_reverse_bits(MD5_H1);
	MD5_H2 = ft_reverse_bits(MD5_H2);
	MD5_H3 = ft_reverse_bits(MD5_H3);
}

char			*ft_md5_decode(t_md5_struct *md5_struct)
{
	char *res;

	ft_md5_reverse_words(md5_struct);
	res = ft_itoa_base_ull(MD5_H0, "0123456789abcdef");
	res = ft_strjoin(res, ft_itoa_base_ull(MD5_H1, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(MD5_H2, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(MD5_H3, "0123456789abcdef"));
	return (res);
}
