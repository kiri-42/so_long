/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:07:23 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:29:13 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game_data	gdata;

	check_arg(ac, av);
	read_map_file(&gdata, av[1]);
	init_mlx(&gdata);
	init_game_data(&gdata);
	init_map(&gdata);
	mlx_key_hook(gdata.win, key_hook, &gdata);
	mlx_hook(gdata.win, 17, 0L, &close_game, &gdata);
	mlx_expose_hook(gdata.win, &redraw_map, &gdata);
	mlx_loop(gdata.mlx);
	free_map_data(&gdata);
	exit(0);
}
