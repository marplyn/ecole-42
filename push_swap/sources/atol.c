/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:37:28 by dground           #+#    #+#             */
/*   Updated: 2022/02/07 23:39:26 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_isspace(char str)
{
	if ((str == ' ') || (str == '\t') || (str == '\r'))
		return (1);
	else if ((str == '\v') || (str == '\n') || (str == '\f'))
		return (1);
	else
		return (0);
}

typedef struct s_var
{
	long	k;
	long	result;
}	t_var;

long	ft_atol(const char *str)
{
	t_var	t;

	t.result = 0;
	t.k = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
	{
		str++;
		if (*str == '-')
			return (t.result);
	}
	if (*str == '-')
	{
		t.k = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		t.result = t.result * 10 + (int)*str - '0';
		str++;
	}
	if (t.k == 1)
		return (t.result * (-1));
	return (t.result);
}
