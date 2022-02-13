/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:21:19 by dground           #+#    #+#             */
/*   Updated: 2022/02/13 16:55:41 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rr_instructions(char *input, t_stack **a, t_stack **b)
{
	if (input[1] == 'a' && input[2] == '\n')
		ra(a, 0);
	else if (input[1] == 'b' && input[2] == '\n')
		rb(b, 0);
	else if (input[1] == 'r' && input[2] == '\n')
		rr(a, b, 0);
	else if (input[1] == 'r' && input[2] == 'a' && input[3] == '\n')
		rra(a, 0);
	else if (input[1] == 'r' && input[2] == 'b' && input[3] == '\n')
		rrb(b, 0);
	else if (input[1] == 'r' && input[2] == 'r' && input[3] == '\n')
		rrr(a, b, 0);
	else
		error_message("Error");
}

static void	execute_instructions(char *input, t_stack **a, t_stack **b)
{
	if (input[0] == 's')
	{
		if (input[1] == 'a' && input[2] == '\n')
			sa(a, 0);
		else if (input[1] == 'b' && input[2] == '\n')
			sb(b, 0);
		else
			error_message("Error");
	}
	else if (input[0] == 'p')
	{
		if (input[1] == 'a' && input[2] == '\n')
			pa(a, b, 0);
		else if (input[1] == 'b' && input[2] == '\n')
			pb(b, a, 0);
		else
			error_message("Error");
	}
	else if (input[0] == 'r')
		rr_instructions(input, a, b);
	else
		error_message("Error");
}

static void	print_checker_result(t_stack **a)
{
	if (sorted_stack_check(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	reading_instructions(char *input, t_stack **a, t_stack **b)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (k != 0)
	{
		k = read(0, &input[i], 1);
		if ((input[i] == '\n') && (i < 4))
		{
			input[i + 1] = '\0';
			execute_instructions(input, a, b);
			i = -1;
		}
		if (i >= 4)
			error_message("Error");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	input[6];

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
	reading_instructions(input, a, b);
	print_checker_result(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
