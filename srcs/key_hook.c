/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:05:32 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/07 18:25:15 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to move the player */
static void	move_process(t_data *game_data, int next_x, int next_y)
{
	game_data->map_data[game_data->player_y][game_data->player_x] = '0';
	game_data->map_data[next_y][next_x] = 'P';
	game_data->player_x = next_x;
	game_data->player_y = next_y;
	printf("count : %zu\n", ++game_data->cnt_move);
	redraw_map(game_data);
}

/* Function to count the coins picked up */
static void	get_coin(t_data *game_data)
{
	game_data->cnt_C--;
	if (game_data->cnt_C == 0)
		game_data->can_exit = true;
}

/* Function when stepping on the exit */
static void	end_of_game(t_data *game_data)
{
	if (!game_data->can_exit)
		return ;
	printf("count : %zu\n", ++game_data->cnt_move);
	mlx_destroy_window(game_data->mlx, game_data->win);
	free_map_data(game_data);
	exit(0);
}

/* Function to move the player to an arbitrary direction */
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

/* Functions to distribute processing by key */
int	key_hook(int keycode, t_data *game_data)
{
	(void)game_data;
	if (keycode == W)
		move(game_data, 0, -1);
	else if (keycode == A)
		move(game_data, -1, 0);
	else if (keycode == S)
		move(game_data, 0, 1);
	else if (keycode == D)
		move(game_data, 1, 0);
	else if (keycode == ESC)
	{
		mlx_destroy_window(game_data->mlx, game_data->win);
		free_map_data(game_data);
		exit(0);
	}
	return (0);
}
