/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:33:24 by dground           #+#    #+#             */
/*   Updated: 2021/11/24 17:15:18 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_conversions(char *str, int *length, va_list arguments)
{
	if (*str == 'c')
		c_type(arguments, length);
	else if (*str == 's')
		s_type(arguments, length);
	else if (*str == 'd' || *str == 'i')
		d_i_type(arguments, length);
	else if (*str == 'u')
		u_type(arguments, length);
	else if (*str == 'x' || *str == 'X')
		x_type(arguments, length, str);
	else if (*str == 'p')
		p_type(arguments, length, str);
	else
		ft_putchar(*str, length);
}

int	parse_input(const char *str, va_list arguments, int length)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			parse_conversions((char *)str, &length, arguments);
			str++;
		}
		else
			ft_putchar(*str++, &length);
	}
	return (length);
}
