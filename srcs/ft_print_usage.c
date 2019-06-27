/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:47:28 by srossi            #+#    #+#             */
/*   Updated: 2018/09/12 11:40:52 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_usage(void)
{
    ft_printf("usage: ft_ssl command [command opts] [command args]\n");
    exit(EXIT_FAILURE);
}

void ft_print_usage_option(t_info *info, char option){
    ft_printf("%s: illegal option -- %c\n", info->algo_name, option);
    exit(EXIT_FAILURE);
}
