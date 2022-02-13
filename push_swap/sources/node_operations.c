/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:52:49 by dground           #+#    #+#             */
/*   Updated: 2022/02/04 23:39:48 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int node)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = node;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_stack	*find_end_node(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_node_back(t_stack **a, t_stack *new)
{
	t_stack	*elem;

	if (*a)
	{
		elem = find_end_node(*a);
		elem->next = new;
		new->next = NULL;
	}
	else
	{
		*a = new;
		(*a)->next = NULL;
	}
}
