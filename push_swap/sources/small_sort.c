/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:47:43 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:59:15 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sa_and_ra(t_stack **a)
{
	sa(a, 1);
	ra(a, 1);
}

static void	sa_and_rra(t_stack **a)
{
	sa(a, 1);
	rra(a, 1);
}

void	sort_of_3(t_stack **a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *a;
	min = place_of_min_index(a, -1);
	next_min = place_of_min_index(a, min);
	if (sorted_stack_check(a))
		return ;
	if (head->index == min)
		sa_and_ra(a);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(a, 1);
		else
			rra(a, 1);
	}
	else
	{
		if (head->next->index == min)
			ra(a, 1);
		else
			sa_and_rra(a);
	}
}

static void	sort_of_5_initial(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*end_a;

	end_a = *a;
	while (end_a->next)
		end_a = end_a->next;
	if ((end_a->index == min) || (end_a->index == max))
	{
		rra(a, 1);
		pb(b, a, 1);
	}
}

void	sort_of_5(t_stack **a, t_stack **b)
{
	int		min;
	int		max;

	min = place_of_min_index(a, -1);
	max = place_of_max_index(a, -1);
	sort_of_5_initial(a, b, min, max);
	sort_of_5_initial(a, b, min, max);
	while (stack_size(*b) < 2)
	{
		if (((*a)->index == min) || ((*a)->index == max))
			pb(b, a, 1);
		else
			ra(a, 1);
	}
	sort_of_3(a);
	while (stack_size(*b) > 0)
	{
		pa(a, b, 1);
		if ((*a)->index > (*a)->next->index)
			ra(a, 1);
	}
}
