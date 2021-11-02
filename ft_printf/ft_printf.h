/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:37:18 by dground           #+#    #+#             */
/*   Updated: 2021/11/02 22:11:58 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			star;
	int			dot;
	int			type;
}				t_flags;

int		ft_printf(const char *format, ...);
int		parse_input(const char *str, va_list arguments);
t_flags	init_flags(void);
int		ft_putchar(char c);
int		ft_isdigit(int c);
int		is_type(int c);
int		is_symbol(int c);
int		parse_flags(const char *str, int i, t_flags *flags, va_list arguments);
t_flags	width_flag(t_flags flags, va_list arguments);
t_flags	minus_flag(t_flags flags);
int		dot_flag(const char *str, int index, t_flags *flags, va_list arguments);

#endif