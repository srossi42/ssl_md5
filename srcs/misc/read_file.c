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

//    printf("return %lld \n", buf.st_size);
    return (buf.st_size);
}


void			ft_read_from_file(t_info *info)
{
    int			fd;
    char		*buffer;
    uint64_t	buff_size;
    ssize_t     char_count;

    fd = open(info->filename_to_hash, O_RDONLY);
    ft_printf("fd : %d\n", fd);
    if (fd == -1){
        ft_printf("Couldn't open file (%s): %s", info->current_arg, strerror(errno));
        exit(EXIT_FAILURE);
    }
    buff_size = get_file_size(fd);
    ft_printf("get file size : %lld\n", buff_size);
    if (buff_size > 100)
        buff_size /= 10;

    ft_printf("buff_size  : %lld\n", buff_size);
    info->input_len = 0;
    buffer = ft_strnew(buff_size);
    ft_printf("file size : %lld\n", get_file_size(fd));
    while ((char_count = read(fd, buffer, buff_size)) > 0)
    {
        ft_printf("char_count : %lld\n", char_count);
        ft_printf("info->input_len : %lld\n", info->input_len);
//        ft_printf(" info->string_to_hash before : %s\n", info->string_to_hash);
        info->string_to_hash = ft_strnjoin(info->string_to_hash, buffer, info->input_len, buff_size);
//        ft_printf(" info->string_to_hash after : %s\n", info->string_to_hash);
        ft_bzero(buffer, buff_size);
        info->input_len += char_count;
    }
    ft_printf("info->input_len : %lld\n", info->input_len);
    if (fd > 2)
        close(fd);
    if (buffer)
        ft_strdel(&buffer);
}