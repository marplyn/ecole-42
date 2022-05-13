/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:09:06 by dground           #+#    #+#             */
/*   Updated: 2022/05/03 21:39:14 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	disp_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\nError\n", 2);
	exit (EXIT_FAILURE);
}
