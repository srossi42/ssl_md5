/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:28:43 by srossi            #+#    #+#             */
/*   Updated: 2019/12/02 17:22:01 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ft_sha224.h"

char	*ft_sha224_decode(t_sha224_struct *sha224_struct)
{
	char *res;

	res = ft_itoa_base_ull(sha224_struct->state[0], "0123456789abcdef");
	res = ft_strjoin(res, ft_itoa_base_ull(sha224_struct->state[1],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha224_struct->state[2],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha224_struct->state[3],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha224_struct->state[4],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha224_struct->state[5],
				"0123456789abcdef"));
	res = ft_strjoin(res, ft_itoa_base_ull(sha224_struct->state[6],
				"0123456789abcdef"));
	return (res);
}
