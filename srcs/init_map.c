/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:50:50 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 15:40:52 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_cnt(t_data *game_data)
{
	game_data->cnt_P = 0;
	game_data->cnt_C = 0;
	game_data->cnt_E = 0;
}

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
		game_data->player_x = x;
		game_data->player_y = y;
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
		finish_error("the character is not registered as an object.");
}

static void	has_object(t_data *game_data)
{
	if (game_data->cnt_P == 0)
		finish_error("there's not a single player");
	if (game_data->cnt_P > 1)
		finish_error("there are too many players.");
	if (game_data->cnt_C == 0)
		finish_error("there's not a single coin.");
	if (game_data->cnt_E == 0)
		finish_error("there's not a single exit.");
}

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
