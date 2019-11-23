/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:16:07 by srossi            #+#    #+#             */
/*   Updated: 2019/08/27 20:16:10 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

static uint64_t	get_file_size(int fd)
{
    struct stat	buf;

    if (fstat(fd, &buf) != 0){
        printf("Couldn't open this file...\n");
        return(0);
    }
    if (buf.st_size == 0)
    {
        printf("Couldn't open this file (buf.st_size = 0)\n");
        exit(-1);
    }
    return (buf.st_size);
}


void			ft_read_from_file(t_info *info, char *filename_to_hash)
{
    int			fd;
    char		*buffer;
    uint64_t	buff_size;
    ssize_t     char_count;

    fd = open(filename_to_hash, O_RDONLY);
    if (fd == -1){
        ft_printf("Couldn't open file '%s': %s.\n", filename_to_hash, strerror(errno));
    }
    else {
        buff_size = get_file_size(fd);
        if (buff_size > 100)
            buff_size /= 10;
        info->input_len = 0;
        if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buff_size + 1)))){
            ft_printf("%s.\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        while ((char_count = read(fd, buffer, buff_size)) > 0)
        {
            info->string_to_hash = ft_strnjoin(info->string_to_hash, buffer, info->input_len, buff_size);
            ft_bzero(buffer, buff_size);
            info->input_len += char_count;
        }
        if (fd > 2)
            close(fd);
        if (buffer)
            ft_strdel(&buffer);
    }

}
