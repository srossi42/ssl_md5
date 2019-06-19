/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:01:00 by srossi            #+#    #+#             */
/*   Updated: 2017/11/30 12:01:06 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;
	t_list	*head;
	t_list	*elem;

	if (lst && *f)
	{
		tmp = f(lst);
		if (!(head = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		begin = head;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(elem = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			ft_lstaddtail(&begin, elem);
			head = head->next;
			lst = lst->next;
		}
		return (begin);
	}
	return (NULL);
}
