/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:19:28 by srossi            #+#    #+#             */
/*   Updated: 2019/06/19 17:57:27 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fillstk(char *stkfd, int ret, char *buf)
{
	char	*tmp;

	buf[ret] = '\0';
	tmp = stkfd;
	if (!(stkfd = ft_strjoin(stkfd, buf)))
		return (0);
	ft_strdel(&tmp);
	return (stkfd);
}

static char	*ft_retpositif(char *stkfd, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stkfd[i] != '\n' && stkfd[i])
		i++;
	tmp = stkfd;
	if (!(*line = ft_strsub(stkfd, 0, i)))
	{
		ft_strdel(&tmp);
		return (0);
	}
	if (stkfd[i] == '\0')
		i--;
	if (!(stkfd = ft_strdup(stkfd + i + 1)))
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (stkfd);
}

int			get_next_line(const int fd, char **line)
{
	t_gnl		s;
	static char	*stk[3000];

	if (read(fd, 0, 0) < 0 || fd > 3000 || line == 0)
		return (-1);
	ft_bzero(&s, sizeof(t_gnl));
	if (!stk[fd])
		if (!(stk[fd] = ft_strnew(0)))
			return (-1);
	while ((ft_strchr(stk[fd], '\n') == 0) &&
			(s.ret = read(fd, s.buf, BUFF_SIZE)) > 0)
		if (!(stk[fd] = ft_fillstk(stk[fd], s.ret, s.buf)))
			return (-1);
	if (s.ret < 0)
		return (-1);
	if (s.ret == 0 && *stk[fd] == '\0')
	{
		ft_strdel(&stk[fd]);
		return (0);
	}
	if (!(stk[fd] = ft_retpositif(stk[fd], line)))
		return (-1);
	return (1);
}
