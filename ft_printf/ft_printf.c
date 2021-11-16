/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:37:13 by dground           #+#    #+#             */
/*   Updated: 2021/11/16 22:43:17 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	agruments;

	length = 0;
	va_start(agruments, format);
	length = parse_input(format, agruments, length);
	va_end(agruments);
	printf("%d\n", length);
	return (length);
}
