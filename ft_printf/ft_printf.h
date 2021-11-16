/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:37:18 by dground           #+#    #+#             */
/*   Updated: 2021/11/16 22:38:17 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		parse_input(const char *str, va_list arguments, int length);
void	parse_conversions(char *str, int *length, va_list arguments);
void	c_type(int *length, va_list arguments);
void	s_type(int *length, va_list arguments);
int		ft_putchar(char c, int *length);

#endif