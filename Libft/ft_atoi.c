/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:42:18 by dground           #+#    #+#             */
/*   Updated: 2021/10/07 20:01:12 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char str)
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
	int	k;
	int	result;
}	t_var;

int	ft_atoi(const char *str)
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
