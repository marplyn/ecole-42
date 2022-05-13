/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:24:12 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 17:01:12 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 72

# define ESC_KEY 53
# define A_KEY 0
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2

# define ARGS_ERR "Wrong number of arguments."
# define FILE_EXT_ERR "Wrong map file format."
# define FILE_PERMISSION_ERR "Can't open map file."
# define MAP_SIZE_ERR "Map is not rectangular."
# define MALLOC_ERR "Can't allocate memory."
# define WRONG_CHAR_ERR "Map must contain only these characters: 0, 1, P, C, E."
# define MAP_WALLS_ERR "Map must be surrounded by walls."
# define MAP_EXIT_ERR "Map must have an exit."
# define MAP_START_ERR "Map must have one player position."
# define OTHER_ERR "Something went wrong."

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# include "mlx/mlx.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_enemy
{
	void	*enemy_right;
	void	*enemy_left;
}	t_enemy;

typedef struct s_img
{
	void			*wall;
	void			*exit;
	void			*collectible;
	void			*player;
	void			*empty;
	struct s_enemy	enemy;
}	t_img;

typedef struct s_player_position
{
	unsigned int	x;
	unsigned int	y;
}	t_player_position;

typedef struct s_map
{
	struct s_mlx				mlx;
	struct s_img				img;
	char						**map_data;
	struct s_player_position	player_position;
	int							width;
	int							height;
	unsigned int				items_to_collect;
}	t_map;

typedef struct s_game
{
	struct s_mlx	mlx;
	struct s_map	map;
	unsigned int	steps;
	int				exit;
}	t_game;

typedef struct s_checker_map
{
	unsigned int	exits;
	unsigned int	collectibles;
	unsigned int	start;
}	t_checker_map;

typedef struct s_file
{
	int		fd;
	char	*line;
}	t_file;

char	*get_next_line(int fd);

void	disp_error_exit(char *message);
void	map_symbols_checker(t_map *map);
void	is_ber_file(char *filename);
void	init_map_size(t_map *map, char *ber);
void	map_init(char *ber, t_map *map);
int		game_close(t_game *game);
int		game_win(t_game *game);
int		game_action(int keycode, t_game *game);
void	img_init(t_mlx *mlx, t_img *img);
void	img_to_win(t_game *game);
char	make_player_moves(t_map *map, int keycode, int exit);
void	free_map_data(t_map *map);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *dst, char *src);
int		ft_strlen(const char *str, int type);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);

void	game_loose_bonus(t_game *game);
void	put_enemy_to_map_bonus(t_map *map);
void	img_init_bonus(t_mlx *mlx, t_img *img);
void	img_to_win_bonus(t_game *game);
int		game_action_bonus(int keycode, t_game *game);
char	make_player_moves_bonus(t_map *map, int keycode, int exit);

#endif