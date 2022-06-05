/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:01:38 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 20:02:02 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_check(void *arg)
{
	t_args	*args;
	long	current_time;

	args = arg;
	while (1)
	{
		current_time = get_time();
		if (current_time - args->philo.time_of_last_meal > args->time_to_die)
		{
			sem_wait(args->stdout_s);
			printf("%ld %lu died\n", get_time() - args->start_time,
				args->philo.philo_id + 1);
			sem_post(args->stop_s);
			exit(0);
		}
	}
	return (0);
}

void	kill_philos(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philos)
	{
		kill(args->philo_pid[i], SIGKILL);
		i++;
	}
}
