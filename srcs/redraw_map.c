/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:13:13 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:35:42 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to redraw the map */
int	redraw_map(t_game_data *gdata)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)gdata->map_height)
	{
		x = 0;
		while (x < (size_t)gdata->map_width)
		{
			if (gdata->map_data[y][x] == '1')
				put_object(gdata, x, y, gdata->wall);
			else if (gdata->map_data[y][x] == '0')
				put_object(gdata, x, y, gdata->field);
			else if (gdata->map_data[y][x] == 'P')
				put_object(gdata, x, y, gdata->player);
			else if (gdata->map_data[y][x] == 'C')
				put_object(gdata, x, y, gdata->coin);
			else if (gdata->map_data[y][x] == 'E')
				put_object(gdata, x, y, gdata->exit);
			x++;
		}
		y++;
	}
	return (0);
}
