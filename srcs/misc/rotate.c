//
// Created by Savinien ROSSI on 2019-08-09.
//

#include "../../includes/ft_ssl.h"

uint32_t    ft_rotate_left(uint32_t x, uint32_t n)
{
    return ((x << n) | (x >> (32 - n)));
}

uint32_t	ft_rotate_right(uint32_t x, uint32_t n)
{
    return ((x >> n) | (x << (32 - n)));
}
