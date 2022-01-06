/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:07:21 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 14:56:48 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft-1.5.1/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# define FLOOR "./img/Floor.xpm"
# define PLAYER "./img/human_2.xpm"
# define COIN "./img/coin_floor.xpm"
# define WALL "./img/wall_rock.xpm"
# define ROCK "./img/stop_rock.xpm"
# define EXIT "./img/exit.xpm"
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		height;
	int		width;
	void	*floor;
	void	*player;
	void	*coin;
	void	*wall;
	void	*rock;
	void	*exit;
	char	**map_data;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	bool	can_exit;
	size_t	cnt_move;
	size_t	cnt_P;
	size_t	cnt_C;
	size_t	cnt_E;
}	t_data;

/* check_arg.c */

void	check_arg(int ac, char **av);

/* read_map_file.c */

void	read_map_file(t_data *game_data, char *map_file);

/* check_map_data.c */

void	check_map_data(t_data *game_data);

/* init_mlx.c */

void	init_mlx(t_data *game_data);

/* init_map.c */

void	init_map(t_data *game_data);

/* put_object.c */

void	put_object(t_data *game_data, size_t x, size_t y, void *object);

/* finish_error.c */

void	finish_error(char *error_message);

#endif