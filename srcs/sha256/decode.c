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
#include "../../includes/ft_sha256.h"

char	*ft_sha256_decode(t_sha256_struct *sha256_struct)
{
	char *res;

	res = ft_itoa_base_ull(SHA256_H0, "0123456789abcdef");
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H1, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H2, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H3, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H4, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H5, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H6, "0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(SHA256_H7, "0123456789abcdef"));
	return (res);
}
