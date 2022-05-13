/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:10:49 by dground           #+#    #+#             */
/*   Updated: 2022/05/12 21:14:30 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_nbrlen(int i)
{
	if (i < 0)
	{
		if (-i < 0)
			return (ft_nbrlen(-(i / 10)) + 2);
		else
			return (ft_nbrlen(-i) + 1);
	}
	else if (i > 9)
		return (ft_nbrlen(i / 10) + 1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		sign;

	length = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	sign = (n < 0);
	if (sign)
	{
		str[0] = '-';
		str[length - 1] = -(n % 10) + '0';
		n = -(n / 10);
		length--;
	}
	while (length > sign)
	{
		str[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (str);
}
