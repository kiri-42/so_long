/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:16:51 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/08 22:22:35 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to initialize variables that need to be initialized in game_data */
void	init_game_data(t_data *game_data)
{
	game_data->cnt_P = 0;
	game_data->cnt_C = 0;
	game_data->cnt_E = 0;
	game_data->can_exit = false;
	game_data->cnt_move = 0;
}
