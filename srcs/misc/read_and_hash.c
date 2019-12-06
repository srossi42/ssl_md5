/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:48:09 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 16:49:07 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void	ft_read_hash_stdin(t_info *info, int argc, t_ptrs *hash_ptrs)
{
	ft_read_stdin(info);
	if (info->string_to_hash)
	{
		info->hash = hash_ptrs->ft_hash(info->string_to_hash, info->input_len);
		ft_print_hash(info, argc, 1);
	}
}

void	ft_read_hash_saved_str(t_info *info, int argc, char **argv)
{
	if (info->options & OPT_PRINT_STDIN & (info->p <= 1))
	{
		ft_printf("%s", info->string_to_hash);
		info->p++;
	}
	else if (info->options & STRING_READING)
	{
		ft_printf("%s (\"%s\") = ", ft_str_toupper(info->algo_name),
				info->string_to_hash);
		info->options = info->options ^ STRING_READING;
		info->options = info->options & STRING_READ;
	}
	else if (info->options & FILE_READING)
	{
		ft_printf("%s (%s) = ", ft_str_toupper(info->algo_name),
				argv[info->current_arg]);
		info->options = info->options ^ FILE_READING;
	}
	else
		ft_printf("%s (\"%s\") = ", ft_str_toupper(info->algo_name),
				info->string_to_hash);
	ft_print_hash(info, argc, 1);
}

void	ft_read_hash_saved_str_rq(t_info *info, int argc, char **argv)
{
	ft_print_hash(info, argc, 0);
	if (info->options & STRING_READ && !(info->options & FILE_READING
				|| info->options & OPT_QUIET))
		ft_printf(" \"%s\"\n", argv[info->current_arg]);
	else if (!(info->options & OPT_QUIET))
		ft_printf(" %s\n", argv[info->current_arg]);
	else
		write(1, "\n", 1);
}

void	ft_read_hash_stdin_2(t_info *info, t_ptrs *hash_ptrs, int argc)
{
	ft_read_stdin(info);
	if (info->string_to_hash)
	{
		info->hash = hash_ptrs->ft_hash(info->string_to_hash,
				info->input_len);
		ft_print_hash(info, argc, 1);
	}
}
