/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:46:38 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:32:32 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <errno.h>

//static	void	ft_load_path(t_info *info, char *path, int len)
//{
//	if (ft_strequ(&info->full_path[len + 1], path))
//	{
//		ft_load_buff(info, info->full_path);
//		if (path[0] == '.')
//			ft_load_char(info, '/');
//		ft_load_buff(info, ":\n");
//	}
//	else
//	{
//		if ((path[0] != '.' && path[1] != '/') && path[0] != '/')
//			ft_load_buff(info, "./");
//		else if (path[0] == '.')
//			ft_load_char(info, '/');
//		ft_load_buff(info, path);
//		ft_load_buff(info, ":\n");
//	}
//}

void			ft_error(t_info *info, char *argv)
{
	int len;

	len = 0;
//	if (info->full_path)
//	{
//		ft_load_char(info, '\n');
//		len = ft_strlen(info->full_path);
//		while (len >= 0 && info->full_path[len] != '/')
//			len--;
//		ft_load_path(info, path, len);
//	}
//	ft_print_buff(info->buff);
//	ft_bzero(info->buff, sizeof(char) * (LS_BUFF_SIZE + 1));
//	len = ft_strlen(path);
    t_info *p;
    p = info;
	while (len >= 0 && argv[len] != '/')
		len--;
	ft_dprintf(2, "ft_ssl: %s: %s\n", &argv[len + 1], strerror(errno));
	errno = 0;
}

void			ft_errno_error(t_info *info, char *argv)
{
	if (errno == 13)
		ft_error(info, argv);
	else
		errno = 0;
}

void			ft_error_option(char option)
{
	ft_printf("ft_ssl: illegal option -- %c\n", option);
	ft_print_usage();
	exit(EXIT_FAILURE);
}
