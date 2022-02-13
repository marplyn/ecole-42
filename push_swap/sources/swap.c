/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:06:16 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 21:00:33 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack **a, int output)
{
	int		value_tmp;
	int		index_tmp;
	t_stack	*head;
	t_stack	*next;

	head = *a;
	next = head->next;
	if (stack_size(*a) < 2)
		return (-1);
	if (head == NULL || next == NULL)
		return (-1);
	value_tmp = head->value;
	head->value = next->value;
	next->value = value_tmp;
	index_tmp = head->index;
	head->index = next->index;
	next->index = index_tmp;
	if (output)
		write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack **b, int output)
{
	int		value_tmp;
	int		index_tmp;
	t_stack	*head;
	t_stack	*next;

	head = *b;
	next = head->next;
	if (stack_size(*b) < 2)
		return (-1);
	if (head == NULL || next == NULL)
		return (-1);
	value_tmp = head->value;
	head->value = next->value;
	next->value = value_tmp;
	index_tmp = head->index;
	head->index = next->index;
	next->index = index_tmp;
	if (output)
		write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack **a, t_stack **b, int output)
{
	if (sa(a, 0) < 0 || sa(b, 0) < 0)
		return (-1);
	if (output)
		write(1, "ss\n", 3);
	return (0);
}
