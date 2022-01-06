/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:07:23 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 16:13:17 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	redraw_map(t_data *game_data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game_data->map_height)
	{
		x = 0;
		while (x < (size_t)game_data->map_width)
		{
			if (game_data->map_data[y][x] == '1')
				put_object(game_data, x, y, game_data->wall);
			else if (game_data->map_data[y][x] == '0')
				put_object(game_data, x, y, game_data->floor);
			else if (game_data->map_data[y][x] == 'P')
				put_object(game_data, x, y, game_data->player);
			else if (game_data->map_data[y][x] == 'C')
				put_object(game_data, x, y, game_data->coin);
			else if (game_data->map_data[y][x] == 'E')
				put_object(game_data, x, y, game_data->exit);
			x++;
		}
		y++;
	}
}

static void	move_process(t_data *game_data, int next_x, int next_y)
{
	game_data->map_data[game_data->player_y][game_data->player_x] = '0';
	game_data->map_data[next_y][next_x] = 'P';
	game_data->player_x = next_x;
	game_data->player_y = next_y;
	printf("count : %zu\n", ++game_data->cnt_move);
	redraw_map(game_data);
}

static void	get_coin(t_data *game_data)
{
	game_data->cnt_C--;
	if (game_data->cnt_C == 0)
		game_data->can_exit = true;
}

static void	end_of_game(t_data *game_data)
{
	if (!game_data->can_exit)
		return ;
	printf("count : %zu\n", ++game_data->cnt_move);
	mlx_destroy_window(game_data->mlx, game_data->win);
	exit(0);
}

static void	move(t_data *game_data, int move_x, int move_y)
{
	char	next;
	int		next_x;
	int		next_y;

	next_x = game_data->player_x + move_x;
	next_y = game_data->player_y + move_y;
	next = game_data->map_data[next_y][next_x];
	if (next == '1')
		return ;
	if (next == 'C')
		get_coin(game_data);
	if (next == 'E')
		end_of_game(game_data);
	else
		move_process(game_data, next_x, next_y);
}

static int	key_hook(int keycode, t_data *game_data)
{
	(void)game_data;
	if (keycode == W)
		move(game_data, 0, -1);
	if (keycode == A)
		move(game_data, -1, 0);
	if (keycode == S)
		move(game_data, 0, 1);
	if (keycode == D)
		move(game_data, 1, 0);
	if (keycode == ESC)
	{
		mlx_destroy_window(game_data->mlx, game_data->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game_data;

	check_arg(ac, av);
	read_map_file(&game_data, av[1]);
	init_mlx(&game_data);
	init_map(&game_data);
	game_data.can_exit = false;
	game_data.cnt_move = 0;
	mlx_key_hook(game_data.win, key_hook, &game_data);
	mlx_loop(game_data.mlx);
	exit(0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1000, 800, "Hello world!");
// 	mlx_loop(mlx);
// }
