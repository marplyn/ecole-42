/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:40:09 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:53:14 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define TAKING_FORK 4
# define DYING 5

typedef struct s_philo
{
	int				philo_id;
	int				total_num_of_meals;
	int				right_fork;
	int				left_fork;
	long long		last_time_eated;
	struct s_args	*args;
}	t_philo;

typedef struct s_args
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	int				stop;
	long long		start_time;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	stdout_m;
	pthread_mutex_t	stop_m;
	pthread_mutex_t	last_time_eated_m;
	pthread_t		*thread_id;
	t_philo			**philo;
}	t_args;

void	destroy_all(t_args *args);
void	ft_usleep(long long time);
void	state_printing(t_philo *philo, t_args *args, int state);
long	get_time(void);
int		ft_atoi(char *str);
int		check_args(int argc, char **argv);
void	init_args(t_args *args, int argc, char **argv);
int		init_forks(t_args *args);
int		init_mutexes(t_args *args);
int		init_philos(t_args *args);
int		init_threads(t_args *args);
void	monitor(t_args *args);
int		is_dead(t_args *args);
int		ate_enough(t_args *args);
void	*ft_philo(void *data);
void	eating(t_philo *philo, t_args *args);
void	taking_forks(t_philo *philo, t_args *args);
void	*ft_philo_one(void *data);

#endif