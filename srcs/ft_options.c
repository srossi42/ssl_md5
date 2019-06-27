//
// Created by Savinien ROSSI on 2019-06-26.
//

#include "ft_ssl.h"
//#include "ft_md5.h"
//#include "ft_sha256.h"


int ft_is_valid_option(char option, char *options_list){
    int i;
    int opt_list_len;

    i = 0;
    opt_list_len = ft_strlen(options_list);
    while(i < opt_list_len){
        if (option == options_list[i])
            break;
        i++;
    }
    if (i == opt_list_len)
        return 0;
    return 1;
}

int ft_set_option(t_info *info, char option){
    if (option == 'p')
        info->options = info->options | OPT_PRINT_STDIN;
    else if (option == 'q')
        info->options = info->options | OPT_QUIET;
    else if (option == 'r')
        info->options = info->options | OPT_REV;
    else if (option == 's')
        info->options = info->options | OPT_STRING;
    else{
        ft_print_usage();
        return 0;
    }
    return 1;
}