/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:44:14 by dground           #+#    #+#             */
/*   Updated: 2022/02/08 20:50:49 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	stack_indexing(t_stack **a);
void	stack_a_init(t_stack **a, int argc, char **argv);
void	free_stack(t_stack **list);
t_stack	*new_node(int node);
t_stack	*find_end_node(t_stack *a);
void	add_node_back(t_stack **a, t_stack *new);
int		is_numeric(char *c);
void	error_message(char *str);
int		find_duplicates(char **arguments, int tmp, int i);
void	argument_checker(int argc, char **argv);
int		sorted_stack_check(t_stack **a);
int		stack_size(t_stack *head);
void	stack_sorting(t_stack **a, t_stack **b);
int		sa(t_stack **a, int output);
int		sb(t_stack **b, int output);
int		ss(t_stack **a, t_stack **b, int output);
int		pa(t_stack **dest, t_stack **src, int output);
int		pb(t_stack **dest, t_stack **src, int output);
int		ra(t_stack **a, int output);
int		rb(t_stack **b, int output);
int		rr(t_stack **a, t_stack **b, int output);
int		rra(t_stack **a, int output);
int		rrb(t_stack **b, int output);
int		rrr(t_stack **a, t_stack **b, int output);
int		place_of_min_index(t_stack **a, int value);
int		place_of_max_index(t_stack **a, int value);
void	sort_of_3(t_stack **a);
void	sort_of_5(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
int		count_bits(t_stack **a);
void	radix_sort(t_stack **a, t_stack **b);
long	ft_atol(const char *str);

#endif