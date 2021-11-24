/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:37:18 by dground           #+#    #+#             */
/*   Updated: 2021/11/24 20:01:44 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		parse_input(const char *str, va_list arguments, int length);
void	parse_conversions(char *str, int *length, va_list arguments);
void	c_type(va_list arguments, int *length);
void	s_type(va_list arguments, int *length);
void	d_i_type(va_list arguments, int *length);
void	u_type(va_list arguments, int *length);
void	x_type(va_list arguments, int *length, char *str);
void	p_type(va_list arguments, int *length, char *str);
int		ft_putchar(char c, int *length);
void	ft_putnbr(int nb, int *length);
void	ft_putuns(unsigned int nb, int *length);
void	ft_puthex(unsigned long long nb, int *length, char *str);

#endif