/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:47:41 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 17:53:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void    ft_print_invalid_command(char *command)
{
    int i;

    i = 0;
    ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n"
              "Standard commands:\n\nMessage Digest commands:\n", command);
    while (i < NB_FUNCTIONS)
    {
        ft_printf("%s\n", tab_ptrs[i].cmd);
        i++;
    }
    ft_printf("\nCipher commands:\n");
}

int		ft_set_functions(t_ptrs *ptrs, int *argc, char **argv)
{
	int		i;

	i = 0;
	while (i < NB_FUNCTIONS)
	{
		if (ft_strcmp(tab_ptrs[i].cmd, argv[1]) == 0)
		{
			ptrs->cmd = tab_ptrs[i].cmd;
			ptrs->ft_hash = tab_ptrs[i].ft_hash;
			ptrs->ft_parse = tab_ptrs[i].ft_parse;
			return (1);
		}
		i++;
	}
    ft_print_invalid_command(argv[1]);
	exit(EXIT_FAILURE);
}

void	ft_parse_opts(t_info *info, int argc, char **argv)
{
	if (info->options & OPT_STRING && !(info->options & STRING_READ))
	{
		ft_set_option(info, 'c');
		info->input_len = ft_strlen(argv[info->current_arg]);
		info->string_to_hash = ft_strdup(argv[info->current_arg]);
	}
	else if (ft_strlen(argv[info->current_arg]) == 2 &&
			argv[info->current_arg][0] == '-' &&
			ft_is_valid_option(argv[info->current_arg][1], OPTS_MD5_SHA256))
	{
		if (argv[info->current_arg][1] == 's' && info->options & OPT_STRING)
		{
			ft_read_from_file(info, argv[info->current_arg]);
			ft_set_option(info, 'f');
			ft_set_option(info, 'g');
		}
		ft_set_option(info, argv[info->current_arg][1]);
		if (info->options & OPT_STRING || info->options & OPT_PRINT_STDIN)
		{
			if (argv[info->current_arg][1] == 's' && info->current_arg == argc - 1)
			{
				ft_printf("probleme -s need arg\n");
			}
			if (info->options & OPT_PRINT_STDIN)
				info->p++;
			else
				ft_set_option(info, 'd');
		}
		if (info->options & OPT_PRINT_STDIN)
		{
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
		ft_read_from_file(info, argv[info->current_arg]);
		ft_set_option(info, 'f');
		ft_set_option(info, 'g');
	}
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
	t_info		info;
	t_ptrs		hash_ptrs;

	ft_bzero(&info, sizeof(t_info));
	info.current_arg += 2;
	if (argc == 1)
		ft_print_usage();
	else if (ft_set_functions(&hash_ptrs, &argc, argv))
	{
		info.algo_name = ft_strdup(hash_ptrs.cmd);
		if (argc == 2)
		{
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
				if (info.string_to_hash)
				{
					info.hash = hash_ptrs.ft_hash(info.string_to_hash,
							info.input_len);
					if (!(info.options & OPT_QUIET || info.options & OPT_REV) || info.p == 1)
					{
						if (info.options & OPT_PRINT_STDIN & (info.p <= 1))
						{
							ft_printf("%s", info.string_to_hash);
							info.p++;
						}
						else if (info.options & STRING_READING)
						{
							ft_printf("%s (\"%s\") = ", info.algo_name, info.string_to_hash);
							info.options = info.options ^ STRING_READING;
							info.options = info.options & STRING_READ;
						}
						else if (info.options & FILE_READING)
						{
							ft_printf("%s (%s) = ", info.algo_name, argv[info.current_arg]);
							info.options = info.options ^ FILE_READING;
						}
						else
							ft_printf("%s (\"%s\") = ", info.algo_name, info.string_to_hash);
						ft_print_hash(&info, argc, 1);
					}
					else
					{
						ft_print_hash(&info, argc, 0);
						if (info.options & STRING_READ && !(info.options & FILE_READING || info.options & OPT_QUIET))
							ft_printf(" \"%s\"\n", argv[info.current_arg]);
						else if (!(info.options & OPT_QUIET))
							ft_printf(" %s\n", argv[info.current_arg]);
						else
							write(1, "\n", 1);
					}
				}
				ft_reinit_info(&info);
				info.current_arg++;
			}
			if (!(info.options & FILE_READ || info.options & STRING_READ))
			{
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
	while(1){
	    int p;
	    p = 0;
	}
	return (0);
}
