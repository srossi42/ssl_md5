//
// Created by Savinien ROSSI on 2019-06-26.
//

#include "ft_ssl.h"

void ft_upper_string(char s[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
            s[c] = s[c] - 32;
        }
        c++;
    }
}

void ft_print_hash(t_info *info){
    if (info->string_to_hash){
        ft_upper_string(info->algo_name);
        if (info->options & OPT_REV)
            ft_printf("%s \"%s\"\n", info->hash, info->string_to_hash);
        else
        ft_printf("%s (\"%s\") = %s\n", info->algo_name, info->string_to_hash, info->hash);
    }
    else if (info->filename_to_hash){
        ft_upper_string(info->algo_name);
        if (info->options & OPT_REV)
            ft_printf("%s \"%s\"\n", info->hash, info->filename_to_hash);
        else
            ft_printf("%s (\"%s\") = %s\n", info->algo_name, info->filename_to_hash, info->hash);
    }
}
