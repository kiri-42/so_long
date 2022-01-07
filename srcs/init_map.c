/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:50:50 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/08 00:20:02 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to initialize a variable that stores the number of objects */
static void	init_cnt(t_data *game_data)
{
	game_data->cnt_P = 0;
	game_data->cnt_C = 0;
	game_data->cnt_E = 0;
}

/* Function to read the player's position */
static void	read_player_xy(t_data *game_data, size_t x, size_t y)
{
	game_data->player_x = x;
	game_data->player_y = y;
}

/* Function to check which object */
static void	search_object(t_data *game_data, size_t x, size_t y)
{
	if (game_data->map_data[y][x] == '1')
		put_object(game_data, x, y, game_data->wall);
	else if (game_data->map_data[y][x] == '0')
		put_object(game_data, x, y, game_data->floor);
	else if (game_data->map_data[y][x] == 'P')
	{
		put_object(game_data, x, y, game_data->player);
		game_data->cnt_P++;
		read_player_xy(game_data, x, y);
	}
	else if (game_data->map_data[y][x] == 'C')
	{
		put_object(game_data, x, y, game_data->coin);
		game_data->cnt_C++;
	}
	else if (game_data->map_data[y][x] == 'E')
	{
		put_object(game_data, x, y, game_data->exit);
		game_data->cnt_E++;
	}
	else
	{
		free_map_data(game_data);
		finish_error("the character is not registered as an object");
	}
}

/* Function to check if you have the correct number object */
static void	has_object(t_data *game_data)
{
	if (game_data->cnt_P == 0)
	{
		free_map_data(game_data);
		finish_error("there's not a single player");
	}
	if (game_data->cnt_P > 1)
	{
		free_map_data(game_data);
		finish_error("there are too many players");
	}
	if (game_data->cnt_C == 0)
	{
		free_map_data(game_data);
		finish_error("there's not a single coin");
	}
	if (game_data->cnt_E == 0)
	{
		free_map_data(game_data);
		finish_error("there's not a single exit");
	}
}

/* Function to initialize the map */
void	init_map(t_data *game_data)
{
	size_t	height_i;
	size_t	width_i;

	init_cnt(game_data);
	height_i = 0;
	while (height_i < (size_t)game_data->map_height)
	{
		width_i = 0;
		while (width_i < (size_t)game_data->map_width)
		{
			search_object(game_data, width_i, height_i);
			width_i++;
		}
		height_i++;
	}
	has_object(game_data);
}
