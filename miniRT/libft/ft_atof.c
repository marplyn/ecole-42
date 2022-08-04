/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:00:42 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 07:49:23 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_input(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	if (i > 16 || str[i] != '\0' || !str)
		return (0);
	return (1);
}

float	ft_atof(char *str)
{
	double	result;
	double	divider;
	int		sign;
	int		i;

	result = 0;
	divider = 1;
	sign = 1;
	i = 0;
	if (!check_input(str, &sign))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '.' && str[i] != ',' && str[i])
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (str[i])
	{
		result = (result * 10 + str[i++] - '0');
		divider /= 10;
	}
	return (result * sign * divider);
}
