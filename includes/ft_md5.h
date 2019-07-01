/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:34:35 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:40:03 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

typedef unsigned char md5_byte_t; /* 8-bit byte */
typedef unsigned int md5_word_t; /* 32-bit word */

/* Contexte MD5. */
typedef struct  s_md5_state{
    md5_word_t state[4]; /* digest buffer (ABCD) */
    md5_word_t count[2]; /* message length in bits, lsw first */
    md5_byte_t buffer[64]; /* mémoire tampon d'entrée */
}               t_md5_state;


void    ft_md5(char *str_to_hash);
void    ft_md5_init(t_md5_state *md5_state);

#endif
