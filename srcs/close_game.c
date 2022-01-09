/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:19:54 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:31:49 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to close the window */
int	close_game(t_game_data *gdata)
{
	mlx_destroy_window(gdata->mlx, gdata->win);
	free_map_data(gdata);
	exit (0);
}
