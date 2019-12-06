/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:16:32 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

int		ft_is_valid_option(char option, char *options_list)
{
	int i;
	int opt_list_len;

	i = 0;
	opt_list_len = ft_strlen(options_list);
	while (i < opt_list_len)
	{
		if (option == options_list[i])
			break ;
		i++;
	}
	if (i == opt_list_len)
		return (0);
	return (1);
}

int		ft_set_option(t_info *info, char option)
{
	if (option == 'p')
		info->options = info->options | OPT_PRINT_STDIN;
	else if (option == 'q')
		info->options = info->options | OPT_QUIET;
	else if (option == 'r')
		info->options = info->options | OPT_REV;
	else if (option == 's')
		info->options = info->options | OPT_STRING;
	else if (option == 'c')
		info->options = info->options | STRING_READ;
	else if (option == 'd')
		info->options = info->options | STRING_READING;
	else if (option == 'f')
		info->options = info->options | FILE_READ;
	else if (option == 'g')
		info->options = info->options | FILE_READING;
	else if (option == 'h')
		info->options2 = info->options2 | STDIN_READ;
	else
	{
		ft_print_usage();
		return (0);
	}
	return (1);
}

void	ft_set_valid_option(t_info *info, char **argv, int argc)
{
	if (argv[info->current_arg][1] == 's' && (info->options & STRING_READ))
		ft_set_readfile(info, argv[info->current_arg]);
	ft_set_option(info, argv[info->current_arg][1]);
	if (info->options & OPT_STRING || info->options & OPT_PRINT_STDIN)
	{
		if (argv[info->current_arg][1] == 's' && info->current_arg == argc - 1)
		{
			printf("ft_ssl: %s: %s\n", info->algo_name,
					"option requires an argument -- s");
			exit(EXIT_FAILURE);
		}
		if (info->options & OPT_PRINT_STDIN)
			info->p++;
		else
			ft_set_option(info, 'd');
	}
	if (info->options & OPT_PRINT_STDIN && !(info->options2 & STDIN_READ))
	{
		ft_read_stdin(info);
		ft_set_option(info, 'h');
	}
}
