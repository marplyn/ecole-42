/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:07:41 by dground           #+#    #+#             */
/*   Updated: 2021/11/02 22:10:31 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dot_flag(const char *str, int index, t_flags *flags, va_list arguments)
{
	int	i;

	i = index;
	i++;
	if (str[i] == '*')
	{
		flags->dot = va_arg(arguments, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags->dot = (flags -> dot * 10) + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

t_flags	minus_flag(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	width_flag(t_flags flags, va_list arguments)
{
	flags.star = 1;
	flags.width = va_arg(arguments, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width = flags.width * (-1);
		flags.zero = 0;
	}
	return (flags);
}

int	parse_flags(const char *str, int i, t_flags *flags, va_list arguments)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_type(str[i]) && !is_symbol(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = dot_flag(str, i, flags, arguments);
		if (str[i] == '-')
			*flags = minus_flag(*flags);
		if (str[i] == '*')
			*flags = width_flag(*flags, arguments);
		if (str[i] == ' ')
			ft_putchar(' ');
		if (ft_isdigit(str[i]))
		/* */
		if (is_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
	}
	return (i);
}
