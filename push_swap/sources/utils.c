/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:23:39 by dground           #+#    #+#             */
/*   Updated: 2022/02/09 22:57:11 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_numeric(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-')
		i++;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

int	find_duplicates(char **arguments, int tmp, int i)
{
	i++;
	while (arguments[i])
	{
		if (ft_atol(arguments[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

void	argument_checker(int argc, char **argv)
{
	int		i;
	char	**arguments;
	long	tmp;

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
		tmp = ft_atol(arguments[i]);
		if (!is_numeric(arguments[i]))
			error_message("Error");
		if (find_duplicates(arguments, tmp, i))
			error_message("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			error_message("Error");
		i++;
	}
	if (argc == 2)
		free(arguments);
}

int	sorted_stack_check(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while (head && head->next)
	{
		if ((head->value) > (head->next->value))
			return (0);
		head = head->next;
	}
	return (1);
}
