/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:27:40 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:53:27 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_bits(t_stack **a)
{
	t_stack	*head;
	int		max_num;
	int		max_bits;

	head = *a;
	max_num = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max_num)
			max_num = head->index;
		head = head->next;
	}
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	int		size_a;
	int		max_bits;
	int		i;
	int		j;

	head_a = *a;
	size_a = stack_size(head_a);
	max_bits = count_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size_a)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(b, a, 1);
		}
		while (stack_size(*b) > 0)
			pa(a, b, 1);
		i++;
	}
}
