/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:15:59 by srossi            #+#    #+#             */
/*   Updated: 2019/08/27 20:17:54 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void ft_upper_string(char s[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
            s[c] = s[c] - 32;
        }
        c++;
    }
}

void ft_print_hash(t_info *info, int argc){
    ft_printf("%s\n", info->hash);
//    if (argc == 2)
//        ft_printf("%s%s\n", info->string_to_hash, info->hash);
//    else if (info->filename_to_hash){
//        ft_upper_string(info->algo_name);
//        if (info->options & OPT_REV)
//            ft_printf("%s %s\n", info->hash, info->filename_to_hash);
//        else
//            ft_printf("%s (%s) = %s\n", info->algo_name, info->filename_to_hash, info->hash);
//    }
//    else if (info->string_to_hash){
//        ft_upper_string(info->algo_name);
//        if (info->options & OPT_REV)
//            ft_printf("%s \"%s\"\n", info->hash, info->string_to_hash);
//        else
//            ft_printf("%s (\"%s\") = %s\n", info->algo_name, info->string_to_hash, info->hash);
//    }
}
