/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:50:50 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 01:29:29 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	search_object(t_data *game_data, size_t width_i, size_t height_i)
{
	if (game_data->map_data[height_i][width_i] == '1')
	{
		mlx_put_image_to_window(game_data->mlx, game_data->win, \
		game_data->wall, game_data->width * width_i, \
		game_data->height * height_i);
	}
	else if (game_data->map_data[height_i][width_i] == '0')
	{
		mlx_put_image_to_window(game_data->mlx, game_data->win, \
		game_data->floor, game_data->width * width_i, \
		game_data->height * height_i);
	}
	else if (game_data->map_data[height_i][width_i] == 'P')
	{
		mlx_put_image_to_window(game_data->mlx, game_data->win, \
		game_data->player, game_data->width * width_i, \
		game_data->height * height_i);
	}
	else if (game_data->map_data[height_i][width_i] == 'C')
	{
		mlx_put_image_to_window(game_data->mlx, game_data->win, \
		game_data->coin, game_data->width * width_i, \
		game_data->height * height_i);
	}
	else if (game_data->map_data[height_i][width_i] == 'E')
	{
		mlx_put_image_to_window(game_data->mlx, game_data->win, \
		game_data->exit, game_data->width * width_i, \
		game_data->height * height_i);
	}
	else
		finish_error("the character is not registered as an object.");
}

void	init_map(t_data *game_data)
{
	size_t	height_i;
	size_t	width_i;

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
