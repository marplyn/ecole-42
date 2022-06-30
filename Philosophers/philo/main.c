/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:49:29 by dground           #+#    #+#             */
/*   Updated: 2022/06/03 19:53:09 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0 || (argc == 6 && ft_atoi(argv[5]) < 1))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (check_args(argc, argv) == -1)
		return (-1);
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (1);
	init_args(args, argc, argv);
	if (init_forks(args))
		return (1);
	if (init_mutexes(args))
		return (1);
	if (init_philos(args))
		return (1);
	if (init_threads(args))
		return (1);
	destroy_all(args);
	return (EXIT_SUCCESS);
}
