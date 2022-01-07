/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:07:23 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/07 18:30:01 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	game_data;

	check_arg(ac, av);
	read_map_file(&game_data, av[1]);
	init_mlx(&game_data);
	init_map(&game_data);
	game_data.can_exit = false;
	game_data.cnt_move = 0;
	mlx_key_hook(game_data.win, key_hook, &game_data);
	mlx_hook(game_data.win, 17, 0L, &close_game, &game_data);
	mlx_expose_hook(game_data.win, &redraw_map, &game_data);
	mlx_loop(game_data.mlx);
	free_map_data(&game_data);
	exit(0);
}
