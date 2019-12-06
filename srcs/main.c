/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:47:41 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 19:29:30 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int				ft_set_functions(t_ptrs *ptrs, int *argc, char **argv)
{
	int		i;

	i = 0;
	while (i < NB_FUNCTIONS)
	{
		if (ft_strcmp(g_tab_ptrs[i].cmd, argv[1]) == 0)
		{
			ptrs->cmd = g_tab_ptrs[i].cmd;
			ptrs->ft_hash = g_tab_ptrs[i].ft_hash;
			ptrs->ft_parse = g_tab_ptrs[i].ft_parse;
			return (1);
		}
		i++;
	}
	ft_print_invalid_command(argv[1]);
	exit(EXIT_FAILURE);
}

void			ft_parse_opts(t_info *info, int argc, char **argv)
{
	info->input_len = ft_strlen(argv[info->current_arg]);
	if (info->options & OPT_STRING && !(info->options & STRING_READ))
	{
		ft_set_option(info, 'c');
		info->string_to_hash = ft_strdup(argv[info->current_arg]);
	}
	else if (info->input_len == 2 && argv[info->current_arg][0] == '-' &&
			ft_is_valid_option(argv[info->current_arg][1], OPTS_MD5_SHA256))
		ft_set_valid_option(info, argv, argc);
	else if (info->input_len == 2 && argv[info->current_arg][0] == '-')
		ft_print_usage_option(info, argv[info->current_arg][1]);
	else if (info->input_len != 2 || argv[info->current_arg][0] != '-')
		ft_set_readfile(info, argv[info->current_arg]);
}

static	void	ft_loop_args(t_info *info, t_ptrs *hash_p, char **argv, int ac)
{
	while (info->current_arg < ac)
	{
		hash_p->ft_parse(info, ac, argv);
		if (info->string_to_hash)
		{
			info->hash = hash_p->ft_hash(info->string_to_hash,
					info->input_len);
			if (!(info->options & OPT_QUIET || info->options & OPT_REV)
					|| info->p == 1)
				ft_read_hash_saved_str(info, ac, argv);
			else
				ft_read_hash_saved_str_rq(info, ac, argv);
		}
		ft_reinit_info(info);
		info->current_arg++;
	}
}

int				main(int argc, char **argv)
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
			ft_read_hash_stdin(&info, argc, &hash_ptrs);
		else
		{
			ft_loop_args(&info, &hash_ptrs, argv, argc);
			if (!(info.options & FILE_READ || info.options & STRING_READ))
				ft_read_hash_stdin_2(&info, &hash_ptrs, argc);
		}
	}
	ft_free_info(&info);
	return (0);
}
