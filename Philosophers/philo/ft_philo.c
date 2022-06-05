/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:42:44 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:52:43 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *philo, t_args *args)
{
	if (philo->philo_id % 2 == 0
		&& (philo->philo_id + 1 != args->number_of_philos))
	{
		pthread_mutex_lock(&args->forks_m[philo->right_fork]);
		pthread_mutex_lock(&args->forks_m[philo->left_fork]);
		state_printing(philo, args, TAKING_FORK);
		state_printing(philo, args, TAKING_FORK);
	}
	else
	{
		pthread_mutex_lock(&args->forks_m[philo->left_fork]);
		pthread_mutex_lock(&args->forks_m[philo->right_fork]);
		state_printing(philo, args, TAKING_FORK);
		state_printing(philo, args, TAKING_FORK);
	}
}

void	eating(t_philo *philo, t_args *args)
{
	taking_forks(philo, args);
	pthread_mutex_lock(&args->last_time_eated_m);
	philo->total_num_of_meals++;
	philo->last_time_eated = get_time();
	pthread_mutex_unlock(&args->last_time_eated_m);
	state_printing(philo, args, EATING);
	ft_usleep(args->time_to_eat);
	pthread_mutex_unlock(&args->forks_m[philo->left_fork]);
	pthread_mutex_unlock(&args->forks_m[philo->right_fork]);
}

static int	is_stopped(t_args *args)
{
	pthread_mutex_lock(&args->stop_m);
	if (args->stop)
	{
		pthread_mutex_unlock(&args->stop_m);
		return (1);
	}
	pthread_mutex_unlock(&args->stop_m);
	return (0);
}

void	*ft_philo(void *data)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)data;
	args = philo->args;
	if (philo->philo_id % 2)
		usleep(100);
	while (1)
	{
		if (is_stopped(args))
			return (0);
		eating (philo, args);
		if (is_stopped(args))
			return (0);
		state_printing(philo, args, SLEEPING);
		ft_usleep(args->time_to_sleep);
		if (is_stopped(args))
			return (0);
		state_printing(philo, args, THINKING);
		if (is_stopped(args))
			return (0);
	}
	return (0);
}

void	*ft_philo_one(void *data)
{
	t_args	*args;

	args = (t_args *)data;
	ft_usleep(args->time_to_die);
	state_printing(args->philo[0], args, DYING);
	return (0);
}
