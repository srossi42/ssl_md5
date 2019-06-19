/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:21:54 by srossi            #+#    #+#             */
/*   Updated: 2019/06/19 17:54:23 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "get_next_line.h"
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# define BUFF_SIZE 10

typedef struct		s_gnl
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
