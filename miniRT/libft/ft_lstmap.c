/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:16:38 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/11 20:48:34 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*item;
	t_list	*list;

	if (!f || !lst)
		return ((t_list *) NULL);
	list = NULL;
	while (lst)
	{
		item = ft_lstnew((*f)(lst->content));
		if (!item)
		{
			ft_lstclear(&list, del);
			return ((t_list *) NULL);
		}
		ft_lstadd_back(&list, item);
		lst = lst->next;
	}
	return (list);
}
