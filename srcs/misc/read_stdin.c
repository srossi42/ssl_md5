//
// Created by Savinien ROSSI on 2019-08-12.
//

#include "../../includes/ft_ssl.h"

void			ft_read_stdin(t_info *info)
{
    char	buffer[1025];
    char	*stdin;
    ssize_t	char_count;

    stdin = NULL;
    info->input_len = 0;
    ft_bzero(buffer, 1025);
    while ((char_count = read(STDIN_FILENO, buffer, 1025)) > 0)
    {
        info->string_to_hash = ft_strnjoin( info->string_to_hash, buffer, info->input_len, char_count);
        info->input_len += char_count;
        ft_bzero(buffer, 1025);
    }

}
