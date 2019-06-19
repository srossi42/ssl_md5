/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabptr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:45:40 by srossi            #+#    #+#             */
/*   Updated: 2018/03/30 16:24:15 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABPTR_H
# define FT_TABPTR_H

# include "ft_printf.h"

typedef struct			s_tabptr_conv
{
	char		c;
	int			(*f_type)(char*, t_arg*, va_list);
}						t_tabptr_conv;

struct s_tabptr_conv	tabtype[] =
{
	{'d', &ft_conv_nb},
	{'D', &ft_conv_nb},
	{'i', &ft_conv_nb},
	{'u', &ft_conv_nb},
	{'U', &ft_conv_nb},
	{'o', &ft_conv_nb},
	{'O', &ft_conv_nb},
	{'b', &ft_conv_nb},
	{'x', &ft_conv_x},
	{'X', &ft_conv_x},
	{'s', &ft_conv_s},
	{'S', &ft_conv_wchar_s},
	{'c', &ft_conv_c},
	{'C', &ft_conv_wchar},
	{'p', &ft_conv_p},
	{'%', &ft_conv_percent},
};

#endif
