/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:41:09 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 17:20:07 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void	ft_print_invalid_command(char *command)
{
	int i;

	i = 0;
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n"
			"Standard commands:\n\nMessage Digest commands:\n", command);
	while (i < NB_FUNCTIONS)
	{
		ft_printf("%s\n", g_tab_ptrs[i].cmd);
		i++;
	}
	ft_printf("\nCipher commands:\n");
}

void	ft_error_opening(char *algo_name, char *arg, char *reason)
{
	printf("ft_ssl: %s: %s: %s\n", algo_name, arg, reason);
	exit(EXIT_FAILURE);
}
