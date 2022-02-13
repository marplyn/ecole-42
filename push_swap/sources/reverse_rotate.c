/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:19:22 by dground           #+#    #+#             */
/*   Updated: 2022/02/09 22:57:39 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_stack **a, int output)
{
	t_stack	*head;
	t_stack	*end;

	if (stack_size(*a) < 2)
		return (-1);
	head = *a;
	end = find_end_node(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	end->next = *a;
	*a = end;
	if (output)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **b, int output)
{
	t_stack	*head;
	t_stack	*end;

	if (stack_size(*b) < 2)
		return (-1);
	head = *b;
	end = find_end_node(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	end->next = *b;
	*b = end;
	if (output)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack **a, t_stack **b, int output)
{
	if (rra(a, 0) < 0 || rrb(b, 0) < 0)
		return (-1);
	if (output)
		write(1, "rrr\n", 4);
	return (0);
}
