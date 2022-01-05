/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 01:13:06 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/05 17:27:38 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to check if map data is too small */
static void	is_3_or_more_in_length(t_data *game_data)
{
	if (game_data->map_height < 3 || game_data->map_width < 3)
	{
		// free_all();
		finish_error("map height or width is too small");
	}
}

/* Function to check if the map data is surrounded by 1 (wall) */
static void	is_surrounded_by_wall(t_data *game_data)
{
	size_t	row_i;
	size_t	col_i;

	row_i = 0;
	while (row_i < (size_t)game_data->map_height)
	{
		if (!(game_data->map_data[row_i][0] == '1' && \
			game_data->map_data[row_i][game_data->map_width - 1] == '1'))
		{
			// free_all();
			finish_error("the map is not surrounded by walls.");
		}
		row_i++;
	}
	col_i = 0;
	while (col_i < (size_t)game_data->map_width)
	{
		if (!(game_data->map_data[0][col_i] == '1' && \
			game_data->map_data[game_data->map_height - 1][col_i] == '1'))
		{
			// free_all();
			finish_error("the map is not surrounded by walls.");
		}
		col_i++;
	}
}

/* Function to check if the width of map is equal */
static void	is_equal_in_width(t_data *game_data)
{
	size_t	row_i;

	row_i = 0;
	while (row_i < (size_t)game_data->map_height)
	{
		if (ft_strlen(game_data->map_data[row_i]) != (size_t)game_data->map_width)
		{
			// free_all();
			finish_error("the map is not rectangular");
		}
		row_i++;
	}
}

/* Function to check if the map data is in the correct format */
void	check_map_data(t_data *game_data)
{
	is_3_or_more_in_length(game_data);
	is_surrounded_by_wall(game_data);
	is_equal_in_width(game_data);
}
