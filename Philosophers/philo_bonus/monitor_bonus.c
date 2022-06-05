/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:00:49 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 20:01:11 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meals_check(void *arg)
{
	t_args	*args;
	int		i;

	args = arg;
	i = -1;
	sem_wait(args->stdout_s);
	while (++i < args->number_of_philos)
	{
		sem_post(args->stdout_s);
		sem_wait(args->ate_enough_s);
		sem_wait(args->stdout_s);
	}
	sem_post(args->stop_s);
	return (0);
}
