/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:50:50 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/05 22:29:25 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_object(t_data *game_data, size_t width_i, size_t height_i)
{
	if (game_data->map_data[height_i][width_i] == '1')
		put_wall(game_data, width_i, height_i);
	else if (game_data->map_data[height_i][width_i] == '0')
		put_floor(game_data, width_i, height_i);
	else if (game_data->map_data[height_i][width_i] == 'P')
		put_player(game_data, width_i, height_i);
	else if (game_data->map_data[height_i][width_i] == 'C')
		put_coin(game_data, width_i, height_i);
	else if (game_data->map_data[height_i][width_i] == 'E')
		put_exit(game_data, width_i, height_i);
	else
		finish_error("the character is not registered as an object.");
}

void	init_map(t_data *game_data)
{
	size_t	height_i;
	size_t	width_i;

	height_i = 0;
	while (height_i < game_data->map_height)
	{
		width_i = 0;
		while (width_i < game_data->map_width)
		{
			put_object(game_data, width_i, height_i);
			width_i++;
		}
		height_i++;
	}
	check_map(game_data);
}
