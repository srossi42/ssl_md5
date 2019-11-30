/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:28:43 by srossi            #+#    #+#             */
/*   Updated: 2019/08/09 15:30:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha224.h"

char	*ft_sha224_decode(t_sha224_struct *sha224_struct)
{
	char *res;

	res = ft_itoa_base_ull(SHA224_H0, "0123456789abcdef");
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H1, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H2, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H3, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H4, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H5, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H6, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA224_H7, "0123456789abcdef"));
	return (res);
}
