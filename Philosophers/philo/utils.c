/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:49:40 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:50:01 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long	num;

	if (is_num(str) == -1)
		return (-1);
	num = 0;
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if (num >= 0 && num <= 2147483647)
		return ((int)num);
	return (-1);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000);
}

void	state_printing(t_philo *philo, t_args *args, int state)
{
	long long	current_time;

	current_time = get_time() - args->start_time;
	pthread_mutex_lock(&args->stdout_m);
	pthread_mutex_lock(&args->stop_m);
	if (args->stop)
	{
		pthread_mutex_unlock(&args->stdout_m);
		pthread_mutex_unlock(&args->stop_m);
		return ;
	}
	pthread_mutex_unlock(&args->stop_m);
	if (state == TAKING_FORK)
		printf("%lld %d has taken a fork\n", current_time, philo->philo_id + 1);
	if (state == EATING)
		printf("%lld %d is eating\n", current_time, philo->philo_id + 1);
	if (state == SLEEPING)
		printf("%lld %d is sleeping\n", current_time, philo->philo_id + 1);
	if (state == THINKING)
		printf("%lld %d is thinking\n", current_time, philo->philo_id + 1);
	if (state == DYING)
		printf("%lld %d died\n", current_time, philo->philo_id + 1);
	pthread_mutex_unlock(&args->stdout_m);
}

void	ft_usleep(long long time)
{
	long long	t;

	t = get_time();
	while (get_time() - t < time)
	{
		usleep(50);
	}
}
