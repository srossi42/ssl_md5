/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:15:45 by srossi            #+#    #+#             */
/*   Updated: 2019/08/27 20:17:27 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void ft_free_info(t_info *info){
    if (info->filename_to_hash)
        ft_strdel(&info->filename_to_hash);
    if (info->string_to_hash)
        ft_strdel(&info->string_to_hash);
    if (info->hash)
        ft_strdel(&info->hash);
    if (info->algo_name)
        ft_strdel(&info->algo_name);
    if (info->input)
        ft_strdel(&info->input);
//    free(info);
}
