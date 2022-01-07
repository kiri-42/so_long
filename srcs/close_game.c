/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:19:54 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/07 18:27:18 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to close the window */
int	close_game(t_data *game_data)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
	free_map_data(game_data);
	exit (0);
}
