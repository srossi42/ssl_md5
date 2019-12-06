/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:46:46 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 16:47:11 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void	ft_init(t_info *info, char *options)
{
	info->options = 0;
	info->options = 0;
	ft_printf("options : %s\n", options);
}

void	ft_reinit_info(t_info *info)
{
	if (info->string_to_hash)
		ft_strdel(&info->string_to_hash);
	if (info->hash)
		ft_strdel(&info->hash);
}
