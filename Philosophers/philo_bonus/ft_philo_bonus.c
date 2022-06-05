/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:58:41 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 20:00:06 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taking_forks(t_args *args)
{
	sem_wait(args->fork_s);
	sem_wait(args->fork_s);
	state_printing(args, TAKING_FORK);
	state_printing(args, TAKING_FORK);
}

void	eating(t_args *args)
{
	taking_forks(args);
	state_printing(args, EATING);
	args->philo.time_of_last_meal = get_time();
	args->philo.total_nbr_of_meals += 1;
	if (args->philo.total_nbr_of_meals == args->meals_to_eat)
		sem_post(args->ate_enough_s);
	ft_usleep(args->time_to_eat);
	sem_post(args->fork_s);
	sem_post(args->fork_s);
}

void	sleeping_and_thinking(t_args *args)
{
	state_printing(args, SLEEPING);
	ft_usleep(args->time_to_sleep);
	state_printing(args, THINKING);
}

void	*ft_simulation(void *arg)
{
	t_args	*philo;

	philo = (t_args *)arg;
	philo->start_time = get_time();
	while (1)
	{
		eating(philo);
		sleeping_and_thinking(philo);
	}
	return (0);
}

int	ft_philo(t_args *args)
{
	int	i;

	i = 0;
	args->start_time = get_time();
	while (i < args->number_of_philos)
	{
		args->philo.philo_id = i;
		args->philo_pid[i] = fork();
		if (args->philo_pid[i] == -1)
		{
			while (--i >= 0)
				kill(args->philo_pid[i], SIGKILL);
			return (1);
		}
		else if (args->philo_pid[i] == 0)
		{
			init_philos(args);
			ft_simulation(args);
		}
		i++;
	}
	sem_wait(args->stop_s);
	return (0);
}
