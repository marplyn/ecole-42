/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:22:02 by dground           #+#    #+#             */
/*   Updated: 2022/02/09 22:57:48 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	place_of_min_index(t_stack **a, int value)
{
	t_stack	*head;
	int		min;

	head = *a;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && (head->index != value))
			min = head->index;
	}
	return (min);
}

int	place_of_max_index(t_stack **a, int value)
{
	t_stack	*head;
	int		max;

	head = *a;
	max = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index > max) && (head->index != value))
			max = head->index;
	}
	return (max);
}
