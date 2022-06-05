/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:44:38 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:51:41 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ate_enough(t_args *args)
{
	int	i;

	i = 0;
	if (args->meals_to_eat == -1)
		return (0);
	while (i < args->number_of_philos)
	{
		pthread_mutex_lock(&args->last_time_eated_m);
		if (args->philo[i]->total_num_of_meals < args->meals_to_eat)
		{
			pthread_mutex_unlock(&args->last_time_eated_m);
			return (0);
		}
		pthread_mutex_unlock(&args->last_time_eated_m);
		i++;
	}
	pthread_mutex_lock(&args->stop_m);
	args->stop = 1;
	pthread_mutex_unlock(&args->stop_m);
	return (1);
}

int	is_dead(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philos)
	{
		pthread_mutex_lock(&args->last_time_eated_m);
		if (get_time() - args->philo[i]->last_time_eated > args->time_to_die)
		{
			state_printing(args->philo[i], args, DYING);
			pthread_mutex_lock(&args->stop_m);
			args->stop = 1;
			pthread_mutex_unlock(&args->stop_m);
			pthread_mutex_unlock(&args->last_time_eated_m);
			return (1);
		}
		pthread_mutex_unlock(&args->last_time_eated_m);
		i++;
	}
	return (0);
}

void	monitor(t_args *args)
{
	while (1)
	{
		if (is_dead(args))
			return ;
		if (ate_enough(args))
			return ;
	}
}
