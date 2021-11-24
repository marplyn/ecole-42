/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:47:00 by dground           #+#    #+#             */
/*   Updated: 2021/11/24 19:22:55 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
	return (*length);
}

void	ft_putnbr(int nb, int *length)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', length);
	}
	if (nb == -2147483648)
	{
		ft_putchar('2', length);
		nb = 147483648;
	}
	if (nb < 10)
		ft_putchar(nb + '0', length);
	else
	{
		ft_putnbr(nb / 10, length);
		ft_putnbr(nb % 10, length);
	}
}

void	ft_putuns(unsigned int nb, int *length)
{
	if (nb < 10)
		ft_putchar(nb + '0', length);
	else
	{
		ft_putuns(nb / 10, length);
		ft_putuns(nb % 10, length);
	}
}

void	ft_puthex(unsigned long long nb, int *length, char *str)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, length, str);
		nb %= 16;
	}		
	if (nb > 9 && nb < 16)
	{
		if (*str == 'x' || *str == 'p')
			ft_putchar(nb % 10 + 97, length);
		else
			ft_putchar(nb % 10 + 65, length);
	}
	else
		ft_putchar(nb + '0', length);
}
