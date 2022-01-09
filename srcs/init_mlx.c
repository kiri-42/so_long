/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:47:01 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:30:32 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to initialize mlx */
void	init_mlx(t_game_data *gdata)
{
	gdata->mlx = mlx_init();
	gdata->win = mlx_new_window(gdata->mlx, gdata->map_width * 32, \
	gdata->map_height * 32, "so_long");
	gdata->img = mlx_new_image(gdata->mlx, 32, 32);
	gdata->field = mlx_xpm_file_to_image(gdata->mlx, FIELD, \
	&gdata->width, &gdata->height);
	gdata->player = mlx_xpm_file_to_image(gdata->mlx, PLAYER, \
	&gdata->width, &gdata->height);
	gdata->coin = mlx_xpm_file_to_image(gdata->mlx, COIN, \
	&gdata->width, &gdata->height);
	gdata->wall = mlx_xpm_file_to_image(gdata->mlx, WALL, \
	&gdata->width, &gdata->height);
	gdata->exit = mlx_xpm_file_to_image(gdata->mlx, EXIT, \
	&gdata->width, &gdata->height);
}
