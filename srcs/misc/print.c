/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:15:59 by srossi            #+#    #+#             */
/*   Updated: 2019/11/23 16:56:30 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void	ft_upper_string(char s[])
{
	int c;

	c = 0;
	while (s[c] != '\0')
	{
		if (s[c] >= 'a' && s[c] <= 'z')
			s[c] = s[c] - 32;
		c++;
	}
}

void	ft_print_hash(t_info *info, int argc, int n)
{
	if (n)
		ft_printf("%s\n", info->hash);
	else
		ft_printf("%s", info->hash);
}
