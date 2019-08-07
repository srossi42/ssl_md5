/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:47:41 by srossi            #+#    #+#             */
/*   Updated: 2019/06/19 13:55:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int ft_set_functions(t_ptrs *ptrs, int *argc, char **argv){
    int i;

    t_ptrs      tab_ptrs[] =
            {
                    {"md5", &ft_md5, &ft_parse_opts},
                    {"sha256", &ft_sha256, &ft_parse_opts},
            };

    i = 0;
    while(i < NB_FUNCTIONS){
        //ft_printf("%d\n", i);
        //ft_printf("cmd dans tab : %s\n", tab_ptrs[i].cmd);
        //ft_printf("argv[1] : %s\n", argv[1]);
        if (ft_strcmp(tab_ptrs[i].cmd, argv[1]) == 0) {
            ft_printf("found\n");
            ptrs->cmd = tab_ptrs[i].cmd;
            ptrs->ft_hash = tab_ptrs[i].ft_hash;
            ptrs->ft_parse = tab_ptrs[i].ft_parse;
            return 1;
        }
        i++;
    }
    //ft_printf("liste des fonctions (usage bis)\n");
    return 0;
}


void ft_parse_opts(t_info *info, int argc, char **argv){
    ft_printf("ft_parse_opts\n");
    //ft_printf("arg en cours : %s\n",   argv[info->current_arg]);
    //ft_printf("info options before : %x\n", info->options);
    if (info->options & OPT_STRING){
        //si option 's' est déjà active on hash l'argument courant qui doit etre considéré comme une str(si existe)
        //on ajouter la string à hasher (apres l'avoir paddé)
        info->string_to_hash = ft_strdup(argv[info->current_arg]);

        //on désactive l'option
        info->options = info->options ^ OPT_STRING;
    }

    if (ft_strlen(argv[info->current_arg]) == 2 && argv[info->current_arg][0] == '-' &&
        ft_is_valid_option(argv[info->current_arg][1], OPTS_MD5_SHA256)){
        ft_printf("%c is an option\n", argv[info->current_arg][1]);
        ft_set_option(info, argv[info->current_arg][1]);
    }
    else if (ft_strlen(argv[info->current_arg]) == 2 && argv[info->current_arg][0] == '-'){

        ft_print_usage_option(info, argv[info->current_arg][1]);

    }

    else{
        //on est pas sur une option (ne commence pas par '-' ou bien > à 2 char)
        ft_printf("on ouvre le fichier et on le parse pour le hasher\n");
    }
    //ft_printf("info options after : %x\n", info->options);
}




void ft_print_info(t_info *info){
    ft_printf("--------------\n");
    if (info->options)
        ft_printf("Options : %c\n", info->options);
    if (info->filename_to_hash)
        ft_printf("Filename : %s\n", info->filename_to_hash);
    if (info->string_to_hash)
        ft_printf("Str to hash : %s\n", info->string_to_hash);
    if (info->hash)
        ft_printf("Hash : %s\n", info->hash);
    ft_printf("Current arg : %i\n--------------\n", info->current_arg);
    if (info->ready_to_hash)
        ft_printf("ready_to_hash : %b", info->ready_to_hash);
}

/*
void ft_read_from_file(int fd){
    char        buffer[BUFFER_SIZE];
    char        *stdin;

    stdin = ft_strnew(1);
    if (fd == 1){

        while(read(STDIN_FILENO, buffer, BUFFER_SIZE) > 0)
        {
            ft_strcat(stdin, buffer);
            ft_printf("string : %s.\n", buffer);
            ft_printf("stdin : %s.\n", stdin);
        }
    }

}
*/

void ft_reinit_info(t_info *info){
    //ft_printf("Reinit function\n");
    if (info->filename_to_hash)
        ft_strdel(&info->filename_to_hash);
    if (info->string_to_hash)
        ft_strdel(&info->string_to_hash);
    if (info->hash)
        ft_strdel(&info->hash);
}

int	main(int argc, char **argv)
{

    t_info      info;
    t_ptrs      hash_ptrs;

    ft_bzero(&info, sizeof(t_info));
    ft_print_info(&info);
    info.current_arg += 2;
    ft_print_info(&info);
	if (argc == 1)
		    ft_print_usage();
    else if (ft_set_functions(&hash_ptrs, &argc, argv)){
        //ft_printf("algo : %s\n", hash_ptrs.cmd);
        info.algo_name = ft_strdup(hash_ptrs.cmd);

        while (info.current_arg < argc){

            hash_ptrs.ft_parse(&info, argc, argv);

            //a suppr
            //info.string_to_hash = ft_strdup("test str to hash");
            //
            if (info.string_to_hash){
                hash_ptrs.ft_hash(info.string_to_hash);
                //a suppr
                //sha 256
                info.hash = ft_strdup("ab530a13e45914982b79f9b7e3fba994cfd1f3fb22f71cea1afbf02b460c6d1d");
                //
                ft_print_hash(&info);
            }
            ft_reinit_info(&info);
            info.current_arg++;
        }
    }
    //ft_print_info(&info);
    ft_free_info(&info);
    return (0);
}
