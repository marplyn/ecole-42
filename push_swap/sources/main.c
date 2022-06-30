/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:11:59 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:26:24 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (-1);
	argument_checker(argc, argv);
	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	if (!a || !b)
		return (-1);
	*a = NULL;
	*b = NULL;
	stack_a_init(a, argc, argv);
	if (sorted_stack_check(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	stack_sorting(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
