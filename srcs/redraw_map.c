/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:13:13 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:24:09 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to redraw the map */
int	redraw_map(t_data *game_data)
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
				put_object(game_data, x, y, game_data->field);
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
	return (0);
}
