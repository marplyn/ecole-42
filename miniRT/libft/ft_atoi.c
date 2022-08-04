/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:53:21 by sserwyn           #+#    #+#             */
/*   Updated: 2022/07/27 20:50:27 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (c == '\f' || c == '\r' || c == ' ');
}

static int	sign_detection(int *sign, char str)
{
	*sign = 1;
	if (str == '-' || str == '+')
	{
		if (str == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	res;
	int		sign;

	while (my_isspace(*str))
		str++;
	str += sign_detection(&sign, *str);
	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > 9223372036854775807 && sign == 1)
			return (-1);
		if (res > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (sign * res);
}
