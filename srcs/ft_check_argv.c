/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:36:00 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 16:08:30 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <errno.h>

int	ft_check_argv(char *argv, int option)
{
	int error;

	error = 0;
	ft_printf("option : %d\nargv: %s\n", option, argv);
//	if (!ft_is_dirfile(argv))
//	{
//		if (errno == 2)
//		{
//			if (option == 1)
//				ft_dprintf(2, "ft_ls: %s: %s\n", argv, strerror(errno));
//			error = 1;
//		}
//		errno = 0;
//	}
	return (error);
}

int	ft_check_argv_all(int argc, char **argv)
{
	char	*tab[argc];
	int		error;
	int		i;
	int		j;

	i = 0;
	error = 0;
	while (argv[i] && argv[i][0] == '-')
		i++;
	j = i;
	while (j < (argc - 1))
	{
		tab[j - i] = ft_strdup(argv[j]);
		j++;
	}
	tab[j - i] = NULL;
	ft_argv_sort(&tab[0], j - i);
	j = 0;
	while (i < (argc - 1))
	{
		error += ft_check_argv(tab[j++], 1);
		i++;
	}
//	ft_del_char_tab(tab);
	return (error);
}
