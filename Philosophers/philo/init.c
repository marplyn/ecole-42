/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:40:14 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:52:24 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_args *args, int argc, char **argv)
{
	args->number_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->meals_to_eat = ft_atoi(argv[5]);
	if (argc == 5)
		args->meals_to_eat = -1;
	args->stop = 0;
	args->start_time = get_time();
}

int	init_forks(t_args *args)
{
	int	i;

	args->forks_m = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args->number_of_philos);
	if (!args->forks_m)
		return (1);
	i = 0;
	while (i < args->number_of_philos)
	{
		if (pthread_mutex_init(&args->forks_m[i], 0))
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_args *args)
{
	int	i;

	i = 0;
	args->philo = (t_philo **)malloc(sizeof(t_philo *)
			* args->number_of_philos);
	if (!args->philo)
		return (1);
	while (i < args->number_of_philos)
	{
		args->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!args->philo[i])
			return (1);
		args->philo[i]->philo_id = i;
		args->philo[i]->args = args;
		args->philo[i]->total_num_of_meals = 0;
		args->philo[i]->last_time_eated = get_time();
		args->philo[i]->left_fork = i;
		if (i == 0)
			args->philo[i]->right_fork = args->number_of_philos - 1;
		else
			args->philo[i]->right_fork = i - 1;
		i++;
	}
	return (0);
}

int	init_mutexes(t_args *args)
{
	if (pthread_mutex_init(&args->stop_m, 0))
		return (1);
	if (pthread_mutex_init(&args->stdout_m, 0))
		return (1);
	if (pthread_mutex_init(&args->last_time_eated_m, 0))
		return (1);
	return (0);
}

int	init_threads(t_args *args)
{
	int	i;

	i = 0;
	args->thread_id = (pthread_t *)malloc(sizeof(pthread_t)
			* args->number_of_philos);
	if (!args->thread_id)
		return (1);
	if (args->number_of_philos == 1)
	{
		if (pthread_create(&args->thread_id[i], 0, ft_philo_one, (void *)args))
			return (1);
		ft_usleep(args->time_to_die);
		return (0);
	}
	while (i < args->number_of_philos)
	{
		if (pthread_create(&args->thread_id[i], NULL, ft_philo,
				(void *)args->philo[i]))
			return (1);
		i++;
	}
	monitor(args);
	return (0);
}
