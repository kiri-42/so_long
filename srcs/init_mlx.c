/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:47:01 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/07 23:44:21 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to initialize mlx */
void	init_mlx(t_data *game_data)
{
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, game_data->map_width * 32, \
	game_data->map_height * 32, "so_long");
	game_data->img = mlx_new_image(game_data->mlx, 32, 32);
	game_data->floor = mlx_xpm_file_to_image(game_data->mlx, FLOOR, \
	&game_data->width, &game_data->height);
	game_data->player = mlx_xpm_file_to_image(game_data->mlx, PLAYER, \
	&game_data->width, &game_data->height);
	game_data->coin = mlx_xpm_file_to_image(game_data->mlx, COIN, \
	&game_data->width, &game_data->height);
	game_data->wall = mlx_xpm_file_to_image(game_data->mlx, WALL, \
	&game_data->width, &game_data->height);
	game_data->exit = mlx_xpm_file_to_image(game_data->mlx, EXIT, \
	&game_data->width, &game_data->height);
}
