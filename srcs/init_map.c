/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:50:50 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:34:53 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to read the player's position */
static void	read_player_xy(t_game_data *gdata, size_t x, size_t y)
{
	gdata->player_x = x;
	gdata->player_y = y;
}

/* Function to check which object */
static void	search_object(t_game_data *gdata, size_t x, size_t y)
{
	if (gdata->map_data[y][x] == '1')
		put_object(gdata, x, y, gdata->wall);
	else if (gdata->map_data[y][x] == '0')
		put_object(gdata, x, y, gdata->field);
	else if (gdata->map_data[y][x] == 'P')
	{
		put_object(gdata, x, y, gdata->player);
		gdata->cnt_P++;
		read_player_xy(gdata, x, y);
	}
	else if (gdata->map_data[y][x] == 'C')
	{
		put_object(gdata, x, y, gdata->coin);
		gdata->cnt_C++;
	}
	else if (gdata->map_data[y][x] == 'E')
	{
		put_object(gdata, x, y, gdata->exit);
		gdata->cnt_E++;
	}
	else
	{
		free_map_data(gdata);
		finish_error("the character is not registered as an object");
	}
}

/* Function to check if you have the correct number object */
static void	has_object(t_game_data *gdata)
{
	if (gdata->cnt_P == 0)
	{
		free_map_data(gdata);
		finish_error("there's not a single player");
	}
	if (gdata->cnt_P > 1)
	{
		free_map_data(gdata);
		finish_error("there are too many players");
	}
	if (gdata->cnt_C == 0)
	{
		free_map_data(gdata);
		finish_error("there's not a single coin");
	}
	if (gdata->cnt_E == 0)
	{
		free_map_data(gdata);
		finish_error("there's not a single exit");
	}
}

/* Function to initialize the map */
void	init_map(t_game_data *gdata)
{
	size_t	height_i;
	size_t	width_i;

	height_i = 0;
	while (height_i < (size_t)gdata->map_height)
	{
		width_i = 0;
		while (width_i < (size_t)gdata->map_width)
		{
			search_object(gdata, width_i, height_i);
			width_i++;
		}
		height_i++;
	}
	has_object(gdata);
}
