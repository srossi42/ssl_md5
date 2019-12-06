/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:28:43 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:22:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha256.h"

char	*ft_sha256_decode(t_sha256_struct *sha256_struct)
{
	char *res;

	res = ft_itoa_base_ull(sha256_struct->state[0], "0123456789abcdef");
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[1],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[2],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[3],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[4],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[5],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[6],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha256_struct->state[7],
				"0123456789abcdef"));
	return (res);
}
