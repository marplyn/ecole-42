/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:12:49 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 12:29:38 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_data(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
}

int	game_win(t_game *game)
{
	free_map_data(&(game->map));
	ft_putstr_fd("You won!\n", 1);
	exit (EXIT_SUCCESS);
}

int	game_close(t_game *game)
{
	free_map_data(&(game->map));
	exit (EXIT_SUCCESS);
}
