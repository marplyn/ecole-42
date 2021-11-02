/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:37:13 by dground           #+#    #+#             */
/*   Updated: 2021/11/01 19:16:48 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	agruments;

	length = 0;
	va_start(agruments, format);
	length += parse_input(format, agruments);
	va_end(agruments);
	return (length);
}
