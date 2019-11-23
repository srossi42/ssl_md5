/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:47:41 by srossi            #+#    #+#             */
/*   Updated: 2019/08/27 20:05:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_set_functions(t_ptrs *ptrs, int *argc, char **argv)
{
	int		i;
	t_ptrs	tab_ptrs[] =
	{
		{"md5", &ft_md5, &ft_parse_opts},
		{"sha256", &ft_sha256, &ft_parse_opts},
	};

	i = 0;
	while (i < NB_FUNCTIONS)
	{
		if (ft_strcmp(tab_ptrs[i].cmd, argv[1]) == 0)
		{
			//ft_printf("function found\n");
			ptrs->cmd = tab_ptrs[i].cmd;
			ptrs->ft_hash = tab_ptrs[i].ft_hash;
			ptrs->ft_parse = tab_ptrs[i].ft_parse;
			return 1;
		}
		i++;
	}
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n"
           "Standard commands:\n\nMessage Digest commands:\n", argv[1]);

    i = 0;
    while (i < 2)
    {
        ft_printf("%s\n", tab_ptrs[i].cmd);
        i++;
    }
    ft_printf("\nCipher commands:\n");
	return 0;
}

void	ft_parse_opts(t_info *info, int argc, char **argv)
{
	//ft_printf("ft_parse_opts, %d\n", argc);
	//ft_printf("info options before : %x\n", info->options);
	if (info->options & OPT_STRING && !(info->options & STRING_READ))
	{
        ft_set_option(info, 'c');
		//si option 's' est déjà active on hash l'argument courant qui doit etre considéré comme une str(si existe)
		//on ajoute la string à hasher (apres l'avoir paddé)
		info->input_len = ft_strlen(argv[info->current_arg]);
		//printf("string : %s\n", argv[info->current_arg]);
		//printf("string len : %zu\n", ft_strlen(argv[info->current_arg]));
		info->string_to_hash = ft_strdup(argv[info->current_arg]);
		//info->string_to_hash = argv[info->current_arg];
		//on désactive l'option
		info->options = info->options ^ OPT_STRING;
	}
	else if (ft_strlen(argv[info->current_arg]) == 2 &&
			argv[info->current_arg][0] == '-' &&
			ft_is_valid_option(argv[info->current_arg][1], OPTS_MD5_SHA256))
	{
		ft_set_option(info, argv[info->current_arg][1]);
		//ft_printf("activation option : %c\n", argv[info->current_arg][1]);
        if (info->options & OPT_STRING || info->options & OPT_PRINT_STDIN){
            if (info->options & OPT_PRINT_STDIN)
                info->p++;
            else
                ft_set_option(info, 'd');
        }
		if (info->options & OPT_STRING && !(info->options & STRING_READ)){
		    //ft_printf("première activation de '-s'. Option STR READ ACTIVEE\n");
            //ft_set_option(info, 'c');
        }
        if (info->options & OPT_PRINT_STDIN)
        {
            //ft_printf("p option ! info options : %x\n", info->options);
            ft_read_stdin(info);
        }

	}
	else if (ft_strlen(argv[info->current_arg]) == 2 &&
			argv[info->current_arg][0] == '-')
	{
		ft_print_usage_option(info, argv[info->current_arg][1]);
	}
	else if (ft_strlen(argv[info->current_arg]) != 2 ||
              argv[info->current_arg][0] != '-')
	{
		//on est pas sur une option (ne commence pas par '-' ou bien > à 2 char, l'option s n'est pas activée)
		//ft_printf("on ouvre le fichier et on le parse pour le hasher\n");
		ft_read_from_file(info, argv[info->current_arg]);
        ft_set_option(info, 'f');
        ft_set_option(info, 'g');
	}

}

void	ft_print_info(t_info *info)
{
	ft_printf("--------------\n");
	if (info->options)
		ft_printf("Options : %c\n", info->options);
//	if (info->filename_to_hash)
//		ft_printf("Filename : %s\n", info->filename_to_hash);
	if (info->string_to_hash)
		ft_printf("Str to hash : %s\n", info->string_to_hash);
	if (info->hash)
		ft_printf("Hash : %s\n", info->hash);
	ft_printf("Current arg : %i\n--------------\n", info->current_arg);
	if (info->ready_to_hash)
		ft_printf("ready_to_hash : %b", info->ready_to_hash);
}

void	ft_reinit_info(t_info *info)
{
//	if (info->filename_to_hash)
//		ft_strdel(&info->filename_to_hash);
	if (info->string_to_hash)
		ft_strdel(&info->string_to_hash);
	if (info->hash)
		ft_strdel(&info->hash);
}

int		main(int argc, char **argv)
{
	t_info      info;
	t_ptrs      hash_ptrs;

	ft_bzero(&info, sizeof(t_info));
	info.current_arg += 2;
	if (argc == 1){
    ft_printf("ici 2\n");
        ft_print_usage();
    }
	else if (ft_set_functions(&hash_ptrs, &argc, argv))
	{
		info.algo_name = ft_strdup(hash_ptrs.cmd);
		if (argc == 2)
		{
			//ft_printf("on lit entree standard\n");
			ft_read_stdin(&info);
			if (info.string_to_hash)
			{
				info.hash = hash_ptrs.ft_hash(info.string_to_hash,
						info.input_len);
				ft_print_hash(&info, argc, 1);
			}
		}
		else
		{
			while (info.current_arg < argc)
			{
				hash_ptrs.ft_parse(&info, argc, argv);
                //ft_print_info(&info);
				if (info.string_to_hash)
				{
					info.hash = hash_ptrs.ft_hash(info.string_to_hash,
							info.input_len);
					//if (info.options & OPT_PRINT_STDIN)
					//ft capitalize sur algo name !!!!!
					if (!(info.options & OPT_QUIET || info.options & OPT_REV))
                    {
					    //tester pour savoir si 'opt -s" ON
                        if (info.options & OPT_PRINT_STDIN & (info.p <= 1)){
                            ft_printf(".%s", info.string_to_hash);
                            info.p++;
                        }
                        else if (info.options & STRING_READING){
                            ft_printf("%s (\"%s\") = ", info.algo_name, info.string_to_hash);
                            info.options = info.options ^ STRING_READING;
                        }
                        else if (info.options & FILE_READING){
                            ft_printf("%s (%s) = ", info.algo_name, argv[info.current_arg]);
                            info.options = info.options ^ FILE_READING;
                        }
                        else
                            ft_printf("..%s (%s) = ", info.algo_name, info.string_to_hash);
                        ft_print_hash(&info, argc, 1);
                    }
					else {
                        ft_print_hash(&info, argc, 0);
                        ft_printf(" %s\n", argv[info.current_arg]);
					}

				}

				ft_reinit_info(&info);
				info.current_arg++;
			}
			if (!(info.options & FILE_READ || info.options & STRING_READ )){
			    //ft_printf("on a pas eu de string à hasher donc on regarde stdin\n");
                ft_read_stdin(&info);
                if (info.string_to_hash)
                {
                    info.hash = hash_ptrs.ft_hash(info.string_to_hash,
                                                  info.input_len);
                    ft_print_hash(&info, argc, 1);
                }
			}
		}
	}
	ft_free_info(&info);
	return (0);
}
