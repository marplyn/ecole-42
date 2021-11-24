/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:59:17 by dground           #+#    #+#             */
/*   Updated: 2021/11/24 20:01:53 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_type(va_list arguments, int *length, char *str)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_puthex(nb, length, str);
}

void	p_type(va_list arguments, int *length, char *str)
{
	unsigned long	adr;

	adr = va_arg(arguments, unsigned long long);
	ft_putchar('0', length);
	ft_putchar('x', length);
	ft_puthex(adr, length, str);
}
