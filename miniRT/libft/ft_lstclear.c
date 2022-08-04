/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:06:53 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/11 20:10:20 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old;

	if (!del)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		old = *lst;
		*lst = old->next;
		free(old);
	}
	*lst = NULL;
}
