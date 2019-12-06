/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:48:27 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 16:49:33 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

char	*ft_str_toupper(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
