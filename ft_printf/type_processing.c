/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:04:36 by dground           #+#    #+#             */
/*   Updated: 2021/11/24 20:01:51 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_type(va_list arguments, int *length)
{
	char	c;

	c = va_arg(arguments, int);
	ft_putchar(c, length);
}

void	s_type(va_list arguments, int *length)
{
	char	*s;

	s = va_arg(arguments, char *);
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, length);
}

void	d_i_type(va_list arguments, int *length)
{
	int	nb;

	nb = va_arg(arguments, int);
	ft_putnbr(nb, length);
}

void	u_type(va_list arguments, int *length)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_putuns(nb, length);
}
