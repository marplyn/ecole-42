/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:48:49 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:52:58 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pa(t_stack **dest, t_stack **src, int output)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	if (stack_size(*src) == 0)
		return (-1);
	to = *dest;
	from = *src;
	tmp = from;
	from = from->next;
	*src = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*dest = to;
	}
	else
	{
		tmp->next = to;
		*dest = tmp;
	}
	if (output)
		write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **dest, t_stack **src, int output)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	if (stack_size(*src) == 0)
		return (-1);
	to = *dest;
	from = *src;
	tmp = from;
	from = from->next;
	*src = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*dest = to;
	}
	else
	{
		tmp->next = to;
		*dest = tmp;
	}
	if (output)
		write(1, "pb\n", 3);
	return (0);
}
