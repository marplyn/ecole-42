/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:55:16 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 19:23:39 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*next_indexed_elem(t_stack **a)
{
	t_stack	*head;
	t_stack	*min;
	int		current_min;

	min = NULL;
	current_min = 0;
	head = *a;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1)
				&& (!current_min || head->value < min->value))
			{
				min = head;
				current_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	stack_indexing(t_stack **a)
{
	int		index;
	t_stack	*head;

	index = 0;
	head = next_indexed_elem(a);
	while (head)
	{
		head->index = index++;
		head = next_indexed_elem(a);
	}
}

void	stack_a_init(t_stack **a, int argc, char **argv)
{
	int		i;
	char	**arguments;
	t_stack	*new;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arguments = argv;
	}
	while (arguments[i])
	{
		new = new_node(ft_atol(arguments[i]));
		add_node_back(a, new);
		i++;
	}
	stack_indexing(a);
	if (argc == 2)
		free(arguments);
}

void	free_stack(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*begin_list;

	begin_list = *list;
	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
	free(list);
}

int	stack_size(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
