/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:07:21 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/05 00:25:52 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft-1.5.1/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map_data;
	int		map_height;
	int		map_width;
}	t_data;

/* check_arg.c */

void	check_arg(int ac, char **av);

/* read_map_file.c */

void	read_map_file(t_data *game_data, char *map_file);

/* check_map_data.c */

void	check_map_data(t_data *game_data);

/* init_mlx.c */

void	init_mlx(t_data *game_data);

/* finish_error.c */

void	finish_error(char *error_message);

#endif