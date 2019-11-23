/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:16:12 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 16:57:28 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void			ft_read_stdin(t_info *info)
{
	char	buffer[1025];
	char	*stdin;
	ssize_t	char_count;

	stdin = NULL;
	info->input_len = 0;
	ft_bzero(buffer, 1025);
	while ((char_count = read(STDIN_FILENO, buffer, 1024)) > 0)
	{
		info->string_to_hash = ft_strnjoin(info->string_to_hash,
				buffer, info->input_len, char_count);
		info->input_len += char_count;
		ft_bzero(buffer, 1025);
	}
}
