//
// Created by Savinien ROSSI on 2019-08-12.
//

#include "ft_ssl.h"

char		*ft_strnjoin(char *s1, char *s2, size_t len1, size_t len2)
{
    char	*str_s1s2;
    int		i;

    i = 0;
    if (!s1 && !s2)
        return (NULL);
    if (!s2)
        return s1;
    if (!(str_s1s2 = (char *)malloc(sizeof(*str_s1s2) * (len1 + len2 + 1))))
    {
        if (s1)
            ft_strdel(&s1);
        return (NULL);
    }
    while (i < len1)
    {
        str_s1s2[i] = s1[i];
        i++;
    }
    while (i < len2)
    {
        str_s1s2[i + len1] = s2[i];
        i++;
    }
    if (s1)
        ft_strdel(&s1);
    return (str_s1s2);
}
