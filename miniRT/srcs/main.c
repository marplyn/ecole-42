/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:33:16 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 23:42:30 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_mlx				mlx;
	t_list				*scene_elements;
	t_filtered_elements	filtered_elements;

	if (argc != 2)
		display_error_exit(ARGS_ERROR);
	scene_elements = init_scene_elements(argv[1]);
	mlx.mlx_ptr = mlx_init();
	filtered_elements = filtered_elements_new(scene_elements);
	ray_tracing(&mlx, filtered_elements);
	register_all_hooks(mlx, scene_elements);
	mlx_loop(mlx.mlx_ptr);
	clear_scene(&scene_elements);
	exit(EXIT_SUCCESS);
	return (0);
}
