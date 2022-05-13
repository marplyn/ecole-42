/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:43:59 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 17:49:19 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	game_loose_bonus(t_game *game)
{
	free_map_data(&(game->map));
	ft_putstr_fd("You lost!\n", 1);
	exit (EXIT_SUCCESS);
}

void	put_enemy_to_map_bonus(t_map *map)
{
	int	i;
	int	j;

	srand(time(NULL));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_data[i][j] == '0' && rand() % (100 / 5) == 0)
				map->map_data[i][j] = 'M';
			j++;
		}
		i++;
	}
}
