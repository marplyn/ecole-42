/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:33:24 by dground           #+#    #+#             */
/*   Updated: 2021/11/02 22:10:12 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.star = 0;
	flags.dot = -1;
	flags.type = 0;
	return (flags);
}

int	parse_input(const char *str, va_list arguments)
{
	t_flags	flags;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (1)
	{
		flags = init_flags();
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			i = parse_flags(str, ++i, &flags, arguments);
		}
		else if (str[i] != '%')
			length += ft_putchar(str[i]);
		i++;
	}
	return (length);
}
