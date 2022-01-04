/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:47:01 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/04 04:44:23 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mlx(t_data *game_data)
{
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, game_data->map_width, \
	game_data->map_height, "so_long");
	mlx_loop(game_data->mlx);
}
