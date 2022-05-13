/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:04:07 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 12:41:25 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_img(int i, int j, t_map *map, t_mlx mlx)
{
	if (map->map_data[i][j] == '0')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.empty,
			CELL_SIZE * j, CELL_SIZE * i);
	else if (map->map_data[i][j] == '1')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.wall,
			CELL_SIZE * j, CELL_SIZE * i);
	else if (map->map_data[i][j] == 'P')
	{
		map->player_position.x = j;
		map->player_position.y = i;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.player,
			CELL_SIZE * j, CELL_SIZE * i);
	}
	else if (map->map_data[i][j] == 'E')
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.exit,
			CELL_SIZE * j, CELL_SIZE * i);
	else if (map->map_data[i][j] == 'C')
	{
		(map->items_to_collect)++;
		mlx_put_image_to_window(mlx.ptr, mlx.win, map->img.collectible,
			CELL_SIZE * j, CELL_SIZE * i);
	}
}

void	img_to_win(t_game *game)
{
	int	i;
	int	j;

	game->map.items_to_collect = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			put_img(i, j, &(game->map), game->mlx);
			j++;
		}
		i++;
	}
}

void	img_init(t_mlx *mlx, t_img *img)
{
	int	pos[2];

	img->collectible = mlx_xpm_file_to_image(mlx->ptr, "./img/collectible.xpm",
			&pos[0], &pos[1]);
	img->empty = mlx_xpm_file_to_image(mlx->ptr, "./img/empty.xpm",
			&pos[0], &pos[1]);
	img->exit = mlx_xpm_file_to_image(mlx->ptr, "./img/exit.xpm",
			&pos[0], &pos[1]);
	img->player = mlx_xpm_file_to_image(mlx->ptr, "./img/player.xpm",
			&pos[0], &pos[1]);
	img->wall = mlx_xpm_file_to_image(mlx->ptr, "./img/wall.xpm",
			&pos[0], &pos[1]);
}
