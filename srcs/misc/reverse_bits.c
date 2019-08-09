//
// Created by Savinien ROSSI on 2019-08-09.
//

#include "../../includes/ft_ssl.h"

uint32_t    ft_reverse_bits(uint32_t value){
    return (value & 0xFF000000)>>24| (value & 0x00FF0000)>>8
           | (value & 0x0000FF00)<<8 | (value & 0x000000FF)<<24;
}