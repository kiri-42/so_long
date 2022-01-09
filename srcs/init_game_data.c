/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:16:51 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:31:31 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to initialize variables that need to be initialized in game_data */
void	init_game_data(t_game_data *gdata)
{
	gdata->cnt_P = 0;
	gdata->cnt_C = 0;
	gdata->cnt_E = 0;
	gdata->can_exit = false;
	gdata->cnt_move = 0;
}
