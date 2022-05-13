/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:05:14 by dground           #+#    #+#             */
/*   Updated: 2022/05/03 21:46:40 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	symbols_params_init(t_checker_map *checker)
{
	checker->exits = 0;
	checker->collectibles = 0;
	checker->start = 0;
}

static void	count_map_components(t_checker_map *checker, char character)
{
	if (character == 'E')
		checker->exits++;
	else if (character == 'P')
		checker->start++;
	else if (character == 'C')
		checker->collectibles++;
}

static void	content_size_check(int i, int j, t_map *map)
{
	if (map->map_data[i][j] != '0' && map->map_data[i][j] != '1'
		&& map->map_data[i][j] != 'P' && map->map_data[i][j] != 'C'
		&& map->map_data[i][j] != 'E')
		disp_error_exit(WRONG_CHAR_ERR);
	if (i == 0 || j == 0 || j == map->width - 1 || i == map->height - 1)
		if (map->map_data[i][j] != '1')
			disp_error_exit(MAP_WALLS_ERR);
}

void	map_symbols_checker(t_map *map)
{
	int				i;
	int				j;
	t_checker_map	checker;

	symbols_params_init(&checker);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			count_map_components(&checker, map->map_data[i][j]);
			content_size_check(i, j, map);
			j++;
		}
		i++;
	}
	if (checker.exits * checker.collectibles == 0)
		disp_error_exit(MAP_EXIT_ERR);
	if (checker.start != 1)
		disp_error_exit(MAP_START_ERR);
}

void	is_ber_file(char *filename)
{
	int	length;

	length = ft_strlen(filename, 0) - 1;
	if ((filename[length - 3] != '.') || (filename[length - 2] != 'b')
		|| (filename[length - 1] != 'e') || (filename[length] != 'r'))
		disp_error_exit(FILE_EXT_ERR);
}
