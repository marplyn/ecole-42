/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:34:43 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 20:08:00 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (init_args(&args, argc, argv) == -1)
		return (-1);
	init_semaphores(&args);
	init_monitor(&args);
	ft_philo(&args);
	kill_philos(&args);
	return (0);
}
