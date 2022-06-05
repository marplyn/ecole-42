/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:05:23 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 12:46:29 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define TAKING_FORK 4

typedef struct s_philo
{
	pthread_t	monitor_tid;
	sem_t		*actions_s;
	size_t		philo_id;
	size_t		total_nbr_of_meals;
	time_t		time_of_last_meal;
	int			meals_to_eat;
}	t_philo;

typedef struct s_args
{
	pthread_t	monitor_tid;
	pid_t		*philo_pid;
	sem_t		*stdout_s;
	sem_t		*fork_s;
	sem_t		*stop_s;
	sem_t		*ate_enough_s;
	int			number_of_philos;
	time_t		start_time;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	size_t		meals_to_eat;
	t_philo		philo;
}	t_args;

void	taking_forks(t_args *args);
void	eating(t_args *args);
void	sleeping_and_thinking(t_args *args);
void	*ft_simulation(void *arg);
void	*death_check(void *arg);
void	init_philos(t_args *args);
int		ft_philo(t_args *args);
void	*meals_check(void *arg);
int		init_monitor(t_args *args);
int		init_semaphores(t_args *args);
int		init_args(t_args *args, int argc, char **argv);
void	kill_philos(t_args *args);
void	ft_usleep(int ms);
void	state_printing(t_args *args, int state);
long	get_time(void);
int		ft_atoi(char *str);

#endif