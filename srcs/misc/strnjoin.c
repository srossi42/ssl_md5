//
// Created by Savinien ROSSI on 2019-08-12.
//

#include "ft_ssl.h"

char		*ft_strnjoin(char *s1, char *s2, size_t len1, size_t len2)
{
    size_t	i;
    char	*output;

    i = 0;
    if (!s1 && !s2){
        ft_printf("RETURN NULL JOIN\n");
        return (NULL);
    }

    if (!s2)
        return (s1);
    if (!(output = (char *)ft_memalloc(sizeof(char) * (len1 + len2 + 1))))
    {
        (s1) ? ft_strdel(&s1) : NULL;
        ft_printf("RETURN NULL JOIN MALLOC FAILED\n");
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
    printf("Malloc join de len1 + len2 : %zu => OK\n", (len1 + len2 + 1));
    return (output);
}


//size_t	i;
//char	*output;
//
//i = 0;
//if (!s1 && !s2)
//return (NULL);
//if (!s2)
//return (s1);
//if (!(output = (char *)ft_memalloc(sizeof(char) * (len1 + len2 + 1))))
//{
//(s1) ? ft_strdel(&s1) : NULL;
//return (NULL);
//}
//while (i < len1 || i < len2)
//{
//if (i < len1)
//output[i] = s1[i];
//if (i < len2)
//output[i + len1] = s2[i];
//i++;
//}
//(s1) ? ft_strdel(&s1) : NULL;
//return (output);


//char    *s3;
//int     i;
//
//i = 0;
//if (!s1 && !s2)
//return (NULL);
//if (!s2)
//return s1;
////    s3 = ft_strnew(len1 + len2);
//
//if (!(s3 = (char *)ft_memalloc(sizeof(char) * (len1 + len2 + 1))))
//{
//(s1) ? ft_strdel(&s1) : NULL;
//printf("FAIL JOIN\n");
//exit(0);
//}
//
//while (i < len1)
//{
//s3[i] = s1[i];
//i++;
//}
//while (i < (len1 + len2))
//{
//s3[i] = s2[i - len1];
//i++;
//}
//if (s1)
//ft_strdel(&s1);
//return (s3);