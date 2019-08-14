#include "../../includes/ft_ssl.h"

//static uint64_t	get_file_size(int fd)
//{
//    struct stat	buf;
//
//    if (fstat(fd, &buf) != 0){
//        printf("Couldn't open this file...\n");
//        return(0);
//    }
//    if (buf.st_size == 0)
//    {
//        printf("Couldn't open this file (buf.st_size = 0)\n");
//        exit(-1);
//    }
//
////    printf("return %lld \n", buf.st_size);
//    return (buf.st_size);
//}


//void			ft_read_from_file(t_info *info)
//{
//    int			fd;
//    char		*buffer;
//    uint64_t	buff_size;
//    ssize_t     char_count;
//
//    fd = open(info->filename_to_hash, O_RDONLY);
//    ft_printf("fd : %d\n", fd);
//    if (fd == -1){
//        ft_printf("Couldn't open file (%s): %s", info->current_arg, strerror(errno));
//        exit(EXIT_FAILURE);
//    }
//    buff_size = get_file_size(fd);
//    ft_printf("get file size : %lld\n", buff_size);
//    if (buff_size > 100)
//        buff_size /= 10;
//    ft_printf("buff_size  : %lld\n", buff_size);
//    info->input_len = 0;
////    buffer = ft_strnew(buff_size);
//    if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buff_size + 1)))){
//        printf("FAIL\n");
//        exit(0);
//    }
//
//    ft_printf("file size : %lld\n", get_file_size(fd));
//    while ((char_count = read(fd, buffer, buff_size)) > 0)
//    {
//        ft_printf("char_count : %lld\n", char_count);
//        ft_printf("info->input_len : %lld\n", info->input_len);
////        ft_printf(" info->string_to_hash before : %s\n", info->string_to_hash);
//        info->string_to_hash = ft_strnjoin(info->string_to_hash, buffer, info->input_len, buff_size);
////        ft_printf(" info->string_to_hash after : %s\n", info->string_to_hash);
//        ft_bzero(buffer, buff_size);
//        info->input_len += char_count;
//    }
//    ft_printf("info->input_len : %lld\n", info->input_len);
//    if (fd > 2)
//        close(fd);
//    if (buffer)
//        ft_strdel(&buffer);
//}


static char		open_handler(t_info **info, char *filename)
{
    int			fd;
    struct stat	buf;

    if ((fd = open(filename, O_RDONLY)) == -1){
        ft_printf("fd == -1\n");
        exit(0);
    }

    if (fstat(fd, &buf) == 0 && S_ISDIR(buf.st_mode)){
        ft_printf("fstat == 0 \n");
        exit(0);
    }

    return (fd);
}

static uint64_t	get_file_size(int fd)
{
    struct stat	buf;

    if (fstat(fd, &buf) != 0){
        ft_printf("return null dans get file size\n");
        return (0);
    }

    return (buf.st_size);
}

char		*strnjoinsf1(char *s1, char *s2, size_t len1, size_t len2)
{
    size_t	i;
    char	*output;

    i = 0;
    if (!s1 && !s2)
        return (NULL);
    if (!s2)
        return (s1);
    if (!(output = (char *)ft_memalloc(sizeof(char) * (len1 + len2 + 1))))
    {
        (s1) ? ft_strdel(&s1) : NULL;
        return (NULL);
    }
    while (i < len1 || i < len2)
    {
        if (i < len1)
            output[i] = s1[i];
        if (i < len2)
            output[i + len1] = s2[i];
        i++;
    }
    (s1) ? ft_strdel(&s1) : NULL;
    return (output);
}


void			read_from_file(t_info **info, char *filename)
{
    int			fd;
    char		*buffer;
    ssize_t		read_return;
    uint64_t	buff_size;

    fd = open_handler(info, filename);
    buff_size = get_file_size(fd) / 10;
    (*info)->input_len = 0;
    if (!(buffer = (char *)ft_memalloc(sizeof(char) * (buff_size + 1)))){
        ft_printf("Erreur sur read from file\n");
        exit(0);
    }

    while ((read_return = read(fd, buffer, buff_size)) > 0)
    {
//        ft_printf("char_count : %lld\n", read_return);
//        ft_printf("input_len : %lld\n", (*info)->input_len);
        if (!((*info)->string_to_hash = strnjoinsf1((*info)->string_to_hash, buffer, (*info)->input_len, read_return))){
            ft_printf("Erreur sur read from file2\n");
            exit(0);
        }
        (*info)->input_len += read_return;
        ft_bzero(buffer, buff_size);
    }
    if (fd > 2)
        close(fd);
    if (buffer)
        ft_strdel(&buffer);
    if (!(*info)->string_to_hash){
        ft_printf("input inexistant\n");
        exit(0);
    }
}
