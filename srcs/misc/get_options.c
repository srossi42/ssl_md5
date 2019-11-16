/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:46:42 by srossi            #+#    #+#             */
/*   Updated: 2019/06/19 10:22:45 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static	int		ft_is_option(char c)
{
	int i;
	int	valid;

	i = 0;
	valid = 0;
	while (OPTS[i])
	{
		if (OPTS[i] == c)
		{
			valid = 1;
			break ;
		}
		i++;
	}
	return (valid);
}




//static	void	ft_add_option(t_info *info, char option)
//{
//	if (option == 'p')
//		info->options = info->options | OPT_PRINT_STDIN;
//	else if (option == 'q')
//		info->options = info->options | OPT_QUIET;
//	else if (option == 'r')
//		info->options = info->options | OPT_REV;
//	else if (option == 's')
//		info->options = info->options | OPT_STRING;
//  else if (option == 'c')
//        info->options = info->options | STRING_READ;
//    else if (option == 'f')
//        info->options = info->options | FILE_READ;
//}

void			ft_get_options(char option, t_info *info)
{
	int i;
//    int j;
//    int opt_len;

	i = 1;
//	ft_printf("options = %s\n", *options);
//    ft_printf("argc = %d\n", argc);
//    ft_printf("len options = %d\n", ft_strlen(*options));
//	while (++i < argc)
//	{
//	    if (options[i][0] == '-'){
//	        j = 0;
//	        opt_len = ft_strlen(options[i]);
//	        while (++j < opt_len){
//	            ft_printf("opt = %c\n", options[i][j]);
//                if (ft_is_option(options[i][j]))
//                    ft_add_option(info, options[i][j]);
//                else
//                    ft_error_option(options[i][j]);
//	        }
//	    }
        ft_printf("option = %c\n", option);
		if (ft_is_option(option))
			ft_add_option(info, option);
		else
			ft_error_option(option);
//	}
//	if (i == 1)
//	{
//		ft_printf("ft_ssl: %s: %s\n", "-", strerror(2));
//		exit(EXIT_FAILURE);
//	}
}
