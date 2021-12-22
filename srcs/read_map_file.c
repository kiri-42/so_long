/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:23:36 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/23 01:13:05 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_line(t_data *game_data, char *map_file)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		finish_error("The file could not be opened.");
	game_data->map_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		game_data->map_height++;
	}
	close(fd);
}

static void	init_map_data(t_data *game_data, char *map_file)
{
	char	*line;
	int		fd;
	size_t	i;

	game_data->map_data = (char **)malloc(sizeof(char *) * game_data->map_height);
	if (game_data->map_data == NULL)
		exit(1);
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game_data->map_data[i] = line;
		i++;
	}
}



/* map_fileを読み込む関数 */
void	read_map_file(t_data *game_data, char *map_file)
{
	count_line(game_data, map_file);
	init_map_data(game_data, map_file);
	game_data->map_width = ft_strlen(game_data->map_data[0]);
	check_map_data(game_data);
}
