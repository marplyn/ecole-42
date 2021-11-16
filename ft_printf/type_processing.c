/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:04:36 by dground           #+#    #+#             */
/*   Updated: 2021/11/16 22:14:01 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_type(int *length, va_list arguments)
{
	char	c;

	c = va_arg(arguments, int);
	ft_putchar(c, length);
}

void	s_type(int *length, va_list arguments)
{
	char	*s;

	s = va_arg(arguments, char *);
	if (!*s)
		s = "(NULL)";
	while (*s)
		ft_putchar(*s++, length);
}
