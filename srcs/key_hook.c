/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:05:32 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:32:50 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to move the player */
static void	move_process(t_game_data *gdata, int next_x, int next_y)
{
	gdata->map_data[gdata->player_y][gdata->player_x] = '0';
	gdata->map_data[next_y][next_x] = 'P';
	gdata->player_x = next_x;
	gdata->player_y = next_y;
	printf("count : %zu\n", ++gdata->cnt_move);
	redraw_map(gdata);
}

/* Function to count the coins picked up */
static void	get_coin(t_game_data *gdata)
{
	gdata->cnt_C--;
	if (gdata->cnt_C == 0)
		gdata->can_exit = true;
}

/* Function when stepping on the exit */
static void	end_of_game(t_game_data *gdata)
{
	if (!gdata->can_exit)
		return ;
	printf("count : %zu\n", ++gdata->cnt_move);
	mlx_destroy_window(gdata->mlx, gdata->win);
	free_map_data(gdata);
	exit(0);
}

/* Function to move the player to an arbitrary direction */
static void	move(t_game_data *gdata, int move_x, int move_y)
{
	char	next;
	int		next_x;
	int		next_y;

	next_x = gdata->player_x + move_x;
	next_y = gdata->player_y + move_y;
	next = gdata->map_data[next_y][next_x];
	if (next == '1')
		return ;
	if (next == 'C')
		get_coin(gdata);
	if (next == 'E')
		end_of_game(gdata);
	else
		move_process(gdata, next_x, next_y);
}

/* Functions to distribute processing by key */
int	key_hook(int keycode, t_game_data *gdata)
{
	(void)gdata;
	if (keycode == W)
		move(gdata, 0, -1);
	else if (keycode == A)
		move(gdata, -1, 0);
	else if (keycode == S)
		move(gdata, 0, 1);
	else if (keycode == D)
		move(gdata, 1, 0);
	else if (keycode == ESC)
		close_game(gdata);
	return (0);
}
