/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:16:07 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 17:26:21 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void				ft_set_readfile(t_info *info, char *filename)
{
	ft_read_from_file(info, filename);
	ft_set_option(info, 'f');
	ft_set_option(info, 'g');
}

static	uint64_t	get_file_size(int fd, char *algo_name, char *filename)
{
	struct stat		buf;

	if (fstat(fd, &buf) != 0)
		ft_error_opening(algo_name, filename, "couldn't open file");
	else if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode))
		ft_error_opening(algo_name, filename, "is a directory");
	else if (buf.st_size == 0)
		ft_error_opening(algo_name, filename, "couldn't open file");
	return (buf.st_size);
}

static void			ft_err_malloc(void)
{
	ft_printf("%s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

static uint64_t		ft_set_buff_size(int fd, t_info *info, char *filename)
{
	uint64_t		buff_size;

	buff_size = get_file_size(fd, info->algo_name, filename);
	if (buff_size > 100)
		buff_size /= 10;
	info->input_len = 0;
	return (buff_size);
}

void				ft_read_from_file(t_info *info, char *filename_to_hash)
{
	int				fd;
	char			*buffer;
	uint64_t		buff_size;
	ssize_t			char_count;

	fd = open(filename_to_hash, O_RDONLY);
	if (fd == -1)
		ft_error_opening(info->algo_name, filename_to_hash, strerror(errno));
	else
	{
		buff_size = ft_set_buff_size(fd, info, filename_to_hash);
		if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buff_size + 1))))
			ft_err_malloc();
		while ((char_count = read(fd, buffer, buff_size)) > 0)
		{
			info->string_to_hash = ft_strnjoin(info->string_to_hash, buffer,
					info->input_len, buff_size);
			ft_bzero(buffer, buff_size);
			info->input_len += char_count;
		}
		if (fd > 2)
			close(fd);
		if (buffer)
			ft_strdel(&buffer);
	}
}
