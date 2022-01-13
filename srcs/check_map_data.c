/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 01:13:06 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:37:29 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to check if map data is too small */
static void	is_3_or_more_in_length(t_game_data *gdata)
{
	if (gdata->map_height < 2 || gdata->map_width < 2)
	{
		free_map_data(gdata);
		finish_error("map height or width is too small");
	}
}

/* Function to check if the width of map is equal */
static void	is_equal_in_width(t_game_data *gdata)
{
	size_t	row_i;

	row_i = 0;
	while (row_i < (size_t)gdata->map_height)
	{
		if (ft_strlen(gdata->map_data[row_i]) != (size_t)gdata->map_width)
		{
			free_map_data(gdata);
			finish_error("map is not rectangular");
		}
		row_i++;
	}
}

/* Function to check if the map data is surrounded by 1 (wall) */
static void	is_surrounded_by_wall(t_game_data *gdata)
{
	size_t	row_i;
	size_t	col_i;

	row_i = 0;
	while (row_i < (size_t)gdata->map_height)
	{
		if (!(gdata->map_data[row_i][0] == '1' && \
			gdata->map_data[row_i][gdata->map_width - 1] == '1'))
		{
			free_map_data(gdata);
			finish_error("map is not surrounded by walls.");
		}
		row_i++;
	}
	col_i = 0;
	while (col_i < (size_t)gdata->map_width)
	{
		if (!(gdata->map_data[0][col_i] == '1' && \
			gdata->map_data[gdata->map_height - 1][col_i] == '1'))
		{
			free_map_data(gdata);
			finish_error("map is not surrounded by walls");
		}
		col_i++;
	}
}

/* Function to check if the map data is in the correct format */
void	check_map_data(t_game_data *gdata)
{
	is_3_or_more_in_length(gdata);
	is_equal_in_width(gdata);
	is_surrounded_by_wall(gdata);
}
