/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:49:53 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:57:41 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_stack **a, int output)
{
	t_stack	*head;
	t_stack	*end;

	if (stack_size(*a) < 2)
		return (-1);
	head = *a;
	end = find_end_node(head);
	*a = head->next;
	head->next = NULL;
	end->next = head;
	if (output)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **b, int output)
{
	t_stack	*head;
	t_stack	*end;

	if (stack_size(*b) < 2)
		return (-1);
	head = *b;
	end = find_end_node(head);
	*b = head->next;
	head->next = NULL;
	end->next = head;
	if (output)
		write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **a, t_stack **b, int output)
{
	if (ra(a, 0) < 0 || rb(b, 0) < 0)
		return (-1);
	if (output)
		write(1, "rr\n", 3);
	return (0);
}
