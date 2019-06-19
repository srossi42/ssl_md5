/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:06:20 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 11:06:29 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstaddtail(t_list **elem, t_list *new_elem)
{
	t_list *tmp;

	tmp = *elem;
	if (new_elem != NULL)
	{
		if (*elem == NULL)
			*elem = new_elem;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_elem;
		}
		new_elem->next = NULL;
	}
}
