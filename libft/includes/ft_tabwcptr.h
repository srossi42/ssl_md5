/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabwcptr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:05:31 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 12:26:37 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABWCPTR_H
# define FT_TABWCPTR_H

# include "ft_printf.h"

typedef struct			s_tabptr_wchar
{
	void	(*f_type)(wchar_t*, char*);
}						t_tabptr_wchar;

struct s_tabptr_wchar		tab_wc[] =
{
	{&ft_unicode_1},
	{&ft_unicode_2},
	{&ft_unicode_3},
	{&ft_unicode_4},
};

#endif
