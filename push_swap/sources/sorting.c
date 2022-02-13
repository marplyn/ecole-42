/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:29:47 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:59:20 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;

	if (stack_size(*a) < 2)
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_of_3(a);
	else
		sort_of_5(a, b);
}

void	stack_sorting(t_stack **a, t_stack **b)
{
	if ((stack_size(*a) < 4) || (stack_size(*a) == 5))
		small_sort(a, b);
	else
		radix_sort(a, b);
}
