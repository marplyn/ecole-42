/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:57:19 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 20:08:22 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philos(t_args *args)
{
	args->philo.time_of_last_meal = get_time();
	if (pthread_create(&args->monitor_tid, 0, &death_check, args))
		sem_post(args->stop_s);
	pthread_detach(args->monitor_tid);
}

int	init_monitor(t_args *args)
{
	if (args->meals_to_eat)
	{
		if (pthread_create(&args->monitor_tid, 0, &meals_check, args))
			return (1);
		pthread_detach(args->monitor_tid);
	}
	return (0);
}

int	init_semaphores(t_args *args)
{
	sem_unlink("fork_s");
	sem_unlink("stdout_s");
	sem_unlink("stop_s");
	sem_unlink("ate_enough_s");
	args->fork_s = sem_open("fork_s", O_CREAT | O_EXCL,
			S_IRWXU, args->number_of_philos);
	args->stdout_s = sem_open("stdout_s", O_CREAT | O_EXCL, S_IRWXU, 1);
	args->stop_s = sem_open("stop_s", O_CREAT | O_EXCL, S_IRWXU, 0);
	if (args->meals_to_eat)
		args->ate_enough_s = sem_open("ate_enough_s",
				O_CREAT | O_EXCL, S_IRWXU, 0);
	return (0);
}

int	init_args(t_args *args, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0 || (argc == 6 && ft_atoi(argv[5]) < 1))
		return (-1);
	memset(args, 0, sizeof(t_args));
	args->number_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->meals_to_eat = ft_atoi(argv[5]);
	if (argc == 5)
		args->meals_to_eat = -1;
	args->philo_pid = malloc(sizeof(pid_t) * args->number_of_philos);
	memset(args->philo_pid, 0, sizeof(pid_t) * args->number_of_philos);
	return (0);
}
