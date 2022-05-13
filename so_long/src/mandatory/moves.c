/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:37:30 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 12:43:41 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	change_cordinates(int keycode, t_player_position *old,
								t_player_position *new)
{
	if (keycode == W_KEY)
	{
		new->x = old->x;
		new->y = old->y - 1;
	}
	if (keycode == A_KEY)
	{
		new->x = old->x - 1;
		new->y = old->y;
	}
	if (keycode == S_KEY)
	{
		new->x = old->x;
		new->y = old->y + 1;
	}
	if (keycode == D_KEY)
	{
		new->x = old->x + 1;
		new->y = old->y;
	}
}

char	make_player_moves(t_map *map, int keycode, int exit)
{
	t_player_position	old;
	t_player_position	new;
	char				passed;

	old.y = map->player_position.y;
	old.x = map->player_position.x;
	change_cordinates(keycode, &old, &new);
	passed = '1';
	if (map->map_data[new.y][new.x] != '1')
	{
		passed = map->map_data[new.y][new.x];
		map->map_data[new.y][new.x] = 'P';
		map->map_data[old.y][old.x] = '0';
	}
	if (exit == FALSE && passed == 'E')
	{
		map->map_data[old.y][old.x] = 'P';
		map->map_data[new.y][new.x] = 'E';
	}
	return (passed);
}

int	game_action(int keycode, t_game *game)
{
	char	passed;

	if (keycode == ESC_KEY)
		game_close(game);
	if (keycode != W_KEY && keycode != A_KEY && keycode != S_KEY
		&& keycode != D_KEY)
	{
		return (0);
	}
	if (game->map.items_to_collect == 0)
		game->exit = TRUE;
	passed = make_player_moves(&(game->map), keycode, game->exit);
	if (passed != '1' && !(game->exit == FALSE && passed == 'E'))
	{
		ft_putstr_fd("Number of movements: ", 1);
		ft_putnbr_fd(++(game->steps), 1);
		ft_putstr_fd("\n", 1);
	}
	if (passed == 'E' && game->map.items_to_collect == 0)
		game_win(game);
	img_to_win(game);
	return (0);
}
