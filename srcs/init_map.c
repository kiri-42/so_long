/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:50:50 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 01:55:17 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_cnt(t_data *game_data)
{
	game_data->cnt_P = 0;
	game_data->cnt_C = 0;
	game_data->cnt_E = 0;
}

static void	put_object(t_data *game_data, size_t x, size_t y, void *object)
{
	mlx_put_image_to_window(game_data->mlx, game_data->win, \
	object, game_data->width * x, game_data->height * y);
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
	// check_map(game_data);
}
