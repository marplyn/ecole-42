/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:06:29 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 17:03:04 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*skip_beginning_newlines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static void	skip_ending_newlines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line, 1) > 0)
		{
			free(line);
			close(fd);
			disp_error_exit(MAP_SIZE_ERR);
		}
		line = get_next_line(fd);
	}
}

void	init_map_size(t_map *map, char *ber)
{
	t_file	file;	

	map->height = 0;
	file.fd = open(ber, O_RDONLY);
	file.line = skip_beginning_newlines(file.fd);
	while (file.line != NULL)
	{
		map->width = ft_strlen(file.line, 1);
		free(file.line);
		(map->height)++;
		file.line = get_next_line(file.fd);
		if (file.line != NULL && map->width != ft_strlen(file.line, 1))
		{
			free(file.line);
			disp_error_exit(MAP_SIZE_ERR);
		}
		if (file.line != NULL && file.line[0] == '\n')
			break ;
	}
	skip_ending_newlines(file.fd);
	close(file.fd);
	map->map_data = (char **)malloc(sizeof(char *) * map->height);
	if (map->map_data == NULL)
		disp_error_exit(MALLOC_ERR);
}

void	map_init(char *ber, t_map *map)
{
	t_file	file;
	int		height;

	is_ber_file(ber);
	init_map_size(map, ber);
	height = 0;
	file.fd = open(ber, O_RDONLY);
	file.line = skip_beginning_newlines(file.fd);
	if (file.line == NULL)
		disp_error_exit(OTHER_ERR);
	while (height < map->height)
	{
		map->map_data[height] = (char *)malloc(sizeof(char) * (map->width + 2));
		if (map->map_data[height] == NULL)
			disp_error_exit(MALLOC_ERR);
		ft_strcpy(map->map_data[height], file.line);
		map->map_data[height][map->width] = '\0';
		free(file.line);
		height++;
		file.line = get_next_line(file.fd);
	}
	close(file.fd);
	map_symbols_checker(map);
}
