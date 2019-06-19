/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmodify_cont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:02:23 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 11:02:46 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstmodify_cont(t_list *list, int elem_pos, void *content)
{
	int i;
	int imax;

	imax = ft_lstlen(&list);
	i = 0;
	if ((list != NULL) && elem_pos >= 0 && content != NULL && elem_pos < imax)
	{
		while (i < elem_pos)
		{
			list = list->next;
			i++;
		}
		list->content = content;
	}
}
