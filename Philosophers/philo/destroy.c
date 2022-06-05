/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:45:34 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:46:09 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_all(t_args *args)
{
	int	i;

	i = 0;
	free(args->thread_id);
	while (i < args->number_of_philos)
	{
		free(args->philo[i]);
		i++;
	}
	free(args->philo);
	free(args->forks_m);
	free(args);
}

void	destroy_all(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philos)
	{
		pthread_join(args->thread_id[i], 0);
		i++;
	}
	i = 0;
	while (i < args->number_of_philos)
	{
		pthread_mutex_destroy(&args->forks_m[i]);
		i++;
	}
	pthread_mutex_destroy(&args->stdout_m);
	pthread_mutex_destroy(&args->stop_m);
	pthread_mutex_destroy(&args->last_time_eated_m);
	free_all(args);
}
